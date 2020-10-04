#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define DX 3
#define STRLEN 20
#define BEGINSIZE 2
#define SHOWLINECOUNT 7

void set_end(char *p) { // set \n at the end of the line, if there isn`t \n in the line.
    char *i = p;
    while (*i != 0 && *i != 10) {
        i++;
    }
    if (*i == 10) {
        return;
    } else {
        *i = 10;
        i++;
        *i = 0;
        return;
    }
}

int read_str(FILE *mf, char ** toHere) {
    char s[100];
    fgets(s, sizeof(s), mf);
    if (feof(mf) == 0) {
        *toHere = malloc(STRLEN + 2);
        strncpy(*toHere, s, STRLEN);
        set_end(*toHere);
    }
    return feof(mf);
}

char ** read_lines(FILE * mf, int * size) {
    char ** s_arr = malloc(BEGINSIZE);
    int i = 0;
    int cur_len = BEGINSIZE;
    while (read_str(mf, &s_arr[i]) == 0) {
        i++;
        if (i >= cur_len) {
            s_arr = (char **) realloc(s_arr, cur_len * sizeof(char *) * 2);
            cur_len = cur_len * 2;
        }
    }
    s_arr = (char **) realloc(s_arr, i * sizeof(char *));
    *size = i;
    return s_arr;
}

void visualize(WINDOW * win, char ** s_arr, int *first_ind, int line_count) {
    if (*first_ind + SHOWLINECOUNT <= line_count) {
        werase(win);
        for (int j = *first_ind; j < *first_ind + SHOWLINECOUNT; j++) {
            mvwprintw(win, j - *first_ind + 1, 0, "%s", s_arr[j]);
        }
        box(win, 0, 0);
        wrefresh(win);
        *first_ind = *first_ind + 1;
    }
}

void main(int argc, char * argv[]) {
    setlocale(LC_ALL, "");
    WINDOW *win;
    int c = 0;            
    initscr();
    noecho();
    cbreak();
    printw("Window:%s", argv[1]);
    FILE *mf;
    mf = fopen(argv[1], "r");
    int line_count = 0;
    char ** s_arr = read_lines(mf, &line_count);
    fclose(mf);
    refresh();
    win = newwin(LINES - 2 * DX, COLS - 25 * DX, DX, DX);
    keypad(win, TRUE);
    int first_ind = 0;
    visualize(win, s_arr, &first_ind, line_count);
    do {
        if (c == 32) {
            visualize(win, s_arr, &first_ind, line_count);
        }
    } while((c = wgetch(win)) != 27);
    for (int j = 0; j < line_count; j++) {
        free(s_arr[j]);
    }
    endwin();
}