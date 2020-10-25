#include <stdlib.h>

#define MAGIC 5
int main(void) {
    int *a = malloc(MAGIC);
    free(a);
    free(a);
}
