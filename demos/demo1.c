#include <stdio.h>

int main() {
    int *v = malloc(10 * sizeof(int));
    char *my_string = calloc(100, sizeof(char));

    free(v);
}