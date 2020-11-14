#include <stdio.h>
#include <string.h>

#define MAX_NUMB 100

int main(void) {
    int real_numb = 0;
    printf("Input a number from 0 to 100: ");
    scanf("%d", &real_numb);
    int try_numb = 50, left_border = 0, right_border = MAX_NUMB;
    char *s;
    while (real_numb != try_numb) {
        printf("Is the number greater than %d (YES or NO)\n", try_numb);
        scanf("%s", s);
        if (strcmp(s, "YES") == 0) {
            left_border = try_numb;
        } else {
            if (strcmp(s, "NO") == 0) {
                right_border = try_numb;
            } else {
                printf("Wrong input!\n");
            }
        }
        try_numb = (left_border + right_border) / 2;
    }
    printf("Your number is %d\n", try_numb);
}
