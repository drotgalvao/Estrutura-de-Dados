#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

//Lista encadeada circular
typedef struct No{
    int valor;
    struct No *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Lista;



