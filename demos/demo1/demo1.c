#include <stdio.h>

int main() {
    // Se citeste de la tastatura un numar n si apoi un sir de n numere
    // Se afiseaza aceste numere in aceeasi ordine in care au fost citite
    int n, v[10000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}