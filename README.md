# Workshop alocare dinamica (si Siruri)

by Andrei Mărunțiș

## Descarcarea codului

Daca nu stii sa clonezi repo-ul si sa il descarci local, cea mai usoara metoda de a descarca codul este sub forma de arhiva:

![Download repository as .zip archive](https://i.imgur.com/xbeA1Cz.jpg "Download repository as .zip archive")

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
#include <stdlib.h>

// Functie care aloca dinamic o zona de memorie cu dimensiunea size
void *malloc(size_t size);
// Functie care aloca dinamic o zona de memorie de dimensiune nitems * size
// In plus, elementele sunt initializate cu 0
void *calloc(size_t nitems, size_t size);
// Functie care aloca dinamic o zona de memorie de dimensiune size
// In plus, copiaza pana la size biti de la adresa referentiata de ptr
void *realloc(void *ptr, size_t size);
// Functie care elibereaza memoria alocata dinamic de la adresa ptr
void free(void *ptr);
```

## Exemplu folosire utilitar valgrind

Pentru a verifica "memory leak"-urile unui program `my_prog` putem rula utilitarul valgrind, astfel:

```
valgrind ./my_prog
```

Daca programul ruleaza corespunzator si elibereaza toate zonele de memorie, output-ul acestei comenzi va arata cam asa:

```
student$ valgrind ./my_prog
==132== Memcheck, a memory error detector
==132== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==132== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==132== Command: ./my_prog
==132==
==132== 
==132== HEAP SUMMARY:
==132==     in use at exit: 0 bytes in 0 blocks
==132==   total heap usage: 2 allocs, 2 frees, 140 bytes allocated
==132==
==132== All heap blocks were freed -- no leaks are possible
==132==
==132== For lists of detected and suppressed errors, rerun with: -s
==132== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

In caz contrar, utilitarul imi va afisa un mesaj de eroare:

```
student$ valgrind ./my_prog
==139== Memcheck, a memory error detector
==139== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==139== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==139== Command: ./my_prog
==139==
==139== 
==139== HEAP SUMMARY:
==139==     in use at exit: 100 bytes in 1 blocks
==139==   total heap usage: 2 allocs, 1 frees, 140 bytes allocated
==139==
==139== LEAK SUMMARY:
==139==    definitely lost: 100 bytes in 1 blocks
==139==    indirectly lost: 0 bytes in 0 blocks
==139==      possibly lost: 0 bytes in 0 blocks
==139==    still reachable: 0 bytes in 0 blocks
==139==         suppressed: 0 bytes in 0 blocks
==139== Rerun with --leak-check=full to see details of leaked memory
==139==
==139== For lists of detected and suppressed errors, rerun with: -s
==139== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Pot adauga flag-ul `--leak-check=full` pentru a vedea detalii despre unde apare memory leak-ul:

```
student$ valgrind --leak-check=full ./my_prog
==140== Memcheck, a memory error detector
==140== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==140== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==140== Command: ./my_prog
==140==
==140== 
==140== HEAP SUMMARY:
==140==     in use at exit: 100 bytes in 1 blocks
==140==   total heap usage: 2 allocs, 1 frees, 140 bytes allocated
==140==
==140== 100 bytes in 1 blocks are definitely lost in loss record 1 of 1
==140==    at 0x483DD99: calloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==140==    by 0x1091B1: main (demo1.c:5)
==140==
==140== LEAK SUMMARY:
==140==    definitely lost: 100 bytes in 1 blocks
==140==    indirectly lost: 0 bytes in 0 blocks
==140==      possibly lost: 0 bytes in 0 blocks
==140==    still reachable: 0 bytes in 0 blocks
==140==         suppressed: 0 bytes in 0 blocks
==140==
==140== For lists of detected and suppressed errors, rerun with: -s
==140== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

Astfel, aflu ca zona de memorie neeliberata a fost alocata la linia 5. Programul pe care l-am compilat este urmatorul:

```c
#include <stdio.h>

int main() {
    int *v = malloc(10 * sizeof(int));
    char *my_string = calloc(100, sizeof(char));

    free(v);
    // free(mt_string);
}
```