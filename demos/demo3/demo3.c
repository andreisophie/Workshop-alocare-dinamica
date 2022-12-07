#include <stdio.h>
#include <stdlib.h>

int main() {
    // Progamul citeste de la tastatura o matrice cu n*m numere
    // si apoi afiseaza elementele inmultite cu o valoare k citita de la tastatura
    int n, m, k;
    int **mat;

    // citesc dimensiunile matricei
    scanf("%d %d", &n, &m);
    // aloc memorie pentru matrice
    mat = malloc(n * sizeof(int *));
    for (int i = 0 ; i < n; i++) {
        mat[i] = malloc(m * sizeof(int));
    }

    // citesc elementele matricei
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // citesc numarul k cu care trebuie inmultite elementele matricei
    scanf("%d", &k);
    // afisez elementele matricei inmultite cu k
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", k * mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}