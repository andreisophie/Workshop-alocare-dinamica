# Workshop alocare dinamica (si Siruri)

by Andrei Mărunțiș

## Subiecte abordate

- Recapitulare pointeri
- Vectori statici
- Vectori alocati dinamici
- Matrici alocate dinamic
- Programare defensiva
- Utilitarul `valgrind`

## Alocare dinamica: sintaxa in C

```c
// Libraria care trebuie inclusa
#include <stdio.h>

// Functie care aloca dinamic o zona de memorie cu dimensiunea size
void *malloc(size_t size)
// Functie care aloca dinamic o zona de memorie de dimensiune nitems * size
// In plus, elementele sunt initializate cu 0
void *calloc(size_t nitems, size_t size)
// Functie care aloca dinamic o zona de memorie de dimensiune size
// In plus, copiaza pana la size biti de la adresa referentiata de ptr
void *realloc(void *ptr, size_t size)
// Functie care elibereaza memoria alocata dinamic de la adresa ptr
void free(void *ptr)
```

## Exemplu folosite utilitar valgrind

Pentru a verifica "memory leak"-urile unui program `my_prog` putem rula utilitarul valgrind, astfel:

```
valgrind ./my_prog
```