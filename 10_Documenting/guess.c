/** @file guess.c
 * Main library file
 * Guess a number
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>

#define MIN_NUMB 1 /**< Minimum number */
#define MAX_NUMB 100 /**< Maximal number */
#define ARAB_LEN 15 /**< Size of an Arabic number from 1 to 100 */

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "."
#define MANUAL _("Guess is used for guessing a hidden number\n\
\n\
Usage: guess [OPTION]\n\
\n\
    --help		print this help, then exit\n\
    --version		print version number, then exit\n\
\n")
#define VERSION "0.0"

/**
* the array to match the Roman and Arabic numbers
*/
char* roman[MAX_NUMB - MIN_NUMB + 1] = {
  "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
  "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX",
  "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX",
  "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL",
  "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", 
  "L", "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX",
  "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX",
  "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX",
  "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC",
  "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"
};

/**
* translation from Arabic to Roman
*/
char *
to_roman(char * a, char * p) {
    int i = 0;
    int arabic_len = MAX_NUMB - MIN_NUMB + 1;
    while (strcmp(a, roman[i]) != 0 && i < arabic_len) {
        i++;
    }
    sprintf(p, "%d", i + 1);
    return p;
}

/**
* translation from Roman to Arabic
*/
char *
to_arabic(int n) {
    return roman[n - 1];
}

/**
* transform a number to (char *)
*/
char *
number_prepare(int n, int arabic_flag, char * p) {
    if (arabic_flag) {
        return to_arabic(n);
    } else {
        sprintf(p, "%d", n);
        return p;
    }
}

/**
* print the input text
*/
void
input_printf(int arabic_flag, char p[]) {
    printf(_("Input a number from "));
    printf("%s", number_prepare(1, arabic_flag, p));
    printf(_(" to "));
    printf("%s", number_prepare(100, arabic_flag, p));
    printf(":  ");
}

/**
* get the number
*/
int
get_one_number(int arabic_flag) {
    int real_numb;
    char p[ARAB_LEN], arab[ARAB_LEN];
    if (arabic_flag) {
        scanf("%s", arab);
        real_numb = atoi(to_roman(arab, p));
    } else {
        scanf("%d", &real_numb);
    }
    return real_numb;
}

/**
* requests a number until it succeeds
*/
int
get_number(int arabic_flag) {
    int real_numb;
    char p[ARAB_LEN];
    input_printf(arabic_flag, p);
    real_numb = get_one_number(arabic_flag);
    while (real_numb < 1 || real_numb > 100) {
        printf(_("You wrote a wrong number\n"));
        input_printf(arabic_flag, p);
        real_numb = get_one_number(arabic_flag);
    }
    return real_numb;
}

/**
* Main function for guessing
*/
int main(int argc, char *argv[]) {
    setlocale (LC_ALL, "");
    bindtextdomain("guess", LOCALE_PATH);
    textdomain("guess");
    int arabic_flag = 0, i = 0;
    for(i=1; i<argc; i++)
        if(!strcmp(argv[i], "--help")) {
            printf(MANUAL);
            return 0;
        } else if(!strcmp(argv[i], "--version")) {
            return !printf("guess %s\n", VERSION);
        } else if(!strcmp(argv[i], "-r")) {
            arabic_flag = 1;
        }
    int real_numb = get_number(arabic_flag);
    int left_border = MIN_NUMB, right_border = MAX_NUMB, try_numb = (left_border + right_border) / 2;
    char s[10];
    char *s_yes, *s_no;
    s_yes = _("YES");
    s_no = _("NO");
    char p[ARAB_LEN];
    while (left_border != right_border && left_border + 1 != right_border) {
        printf(_("Is the number greater than "));
	printf("%s", number_prepare(try_numb, arabic_flag, p));
        printf(_(" (YES or NO)?\n"));
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
        printf(_("Is the number greater than "));
	printf("%s", number_prepare(left_border, arabic_flag, p));
        printf(_(" (YES or NO)?\n"));
        scanf("%s", s);
        if (strcmp(s, s_yes) == 0) {
            try_numb = right_border;
        } else {
            try_numb = left_border;
        }
    }
    if (try_numb == real_numb) {
        printf(_("Your number is "));
        printf("%s! \n", number_prepare(try_numb, arabic_flag, p));
    } else {
        printf(_("You made a mistake when answering the questions :( \n"));
    }
}
