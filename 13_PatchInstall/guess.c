#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>

#define MIN_NUMB 0
#define MAX_NUMB 100

#define _(STRING) gettext(STRING)

int main(int argc, char *argv[]) {
    setlocale (LC_ALL, "");
    char *dir = dirname(realpath(argv[0], NULL));
    bindtextdomain("guess", dir);
    textdomain("guess");

    int real_numb = 0;
    printf(_("Input a number from 0 to 100: "));
    scanf("%d", &real_numb);
    int left_border = MIN_NUMB, right_border = MAX_NUMB, try_numb = (left_border + right_border) / 2;
    char s[10];
    char *s_yes, *s_no;
    s_yes = _("YES");
    s_no = _("NO");
    while (left_border != right_border && left_border + 1 != right_border) {
        printf(_("Is the number greater than %d (YES or NO)?\n"), try_numb);
        scanf("%s", s);
        if (strcmp(s, s_yes) == 0) {
            left_border = try_numb;
        } else {
            if (strcmp(s, s_no) == 0) {
                right_border = try_numb;
            } else {
                printf(_("Wrong input!\n"));
                continue;
            }
        }
        try_numb = (left_border + right_border) / 2;
    }
    if (left_border + 1 == right_border) {
        printf(_("Is the number greater than %d (YES or NO)?\n"), left_border);
        scanf("%s", s);
        if (strcmp(s, s_yes) == 0) {
            try_numb = right_border;
        } else {
            try_numb = left_border;
        }
    }
    if (try_numb == real_numb) {
        printf(_("Your number is %d! \n"), try_numb);
    } else {
        printf(_("You made a mistake when answering the questions :( \n"));
    }
}
