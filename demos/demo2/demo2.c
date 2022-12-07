#include <stdio.h>
#include <stdlib.h>

int main() {
    // Progamul citeste de la tastatura un sir de n numere
    // apoi inca m numere, pe care le pune in acelasi vector
    int n, m;
    int *v;

    // citesc de la consola dimensiunea primului vector
    scanf("%d", &n);
    // aloc memorie pentru v
    v = malloc(n * sizeof(int));
    // citesc de la consola elementele lui v
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // citesc de la consola cate numere trebuie sa mai adaug la vectorul meu
    scanf("%d", &m);
    // realoc memoria vectorului meu
    v = realloc(v, (n + m) * sizeof(int));
    // citesc de la consola elementele noi in v
    for (int i = 0; i < m; i++) {
        scanf("%d", &v[n + i]);
    }

    // afisez vectorul
    for (int i = 0; i < n + m; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}