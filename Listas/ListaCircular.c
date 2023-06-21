#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

// Lista circular
typedef struct No{
    int valor;
    struct No *prox;
    struct No *ant;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Lista;

// inserir no inicio da lista
void inserirInicio(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista->inicio;
    novo->ant = lista->fim;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->inicio->ant = novo;
        lista->fim->prox = novo;
        lista->inicio = novo;
    }

    lista->tam++;
}

// inserir no final da lista
void inserirFim(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista->inicio;
    novo->ant = lista->fim;
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        lista->fim->prox = novo;
    }
    lista->fim = novo;
    lista->tam++;
}

// inserir em uma posição especifica
void inserirMeio(Lista *lista, int valor, int posicao){
    if(posicao == 0){
        inserirInicio(lista, valor);
    }else if(posicao == lista->tam){
        inserirFim(lista, valor);
    }else{
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        No *aux = lista->inicio;
        int i;
        for(i = 0; i < posicao-1; i++){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox->ant = novo;
        aux->prox = novo;
        lista->tam++;
    }
}

// remover no inicio da lista
void removerInicio(Lista *lista){
    if(lista->inicio != NULL){
        No *aux = lista->inicio;
        lista->inicio = lista->inicio->prox;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
        free(aux);
        lista->tam--;
    }
}

// remover no final da lista
void removerFim(Lista *lista){
    if(lista->inicio != NULL){
        No *aux = lista->fim;
        lista->fim = lista->fim->ant;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
        free(aux);
        lista->tam--;
    }
}

// remover em uma posição especifica
void removerMeio(Lista *lista, int posicao){
    if(posicao == 0){
        removerInicio(lista);
    }else if(posicao == lista->tam-1){
        removerFim(lista);
    }else{
        No *aux = lista->inicio;
        int i;
        for(i = 0; i < posicao-1; i++){
            aux = aux->prox;
        }
        No *aux2 = aux->prox;
        aux->prox = aux2->prox;
        aux2->prox->ant = aux;
        free(aux2);
        lista->tam--;
    }
}

// imprimir lista
void imprimir(Lista *lista){
    No *aux = lista->inicio;
    int i;
    for(i = 0; i < lista->tam; i++){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

// mostrar todos os elementos da lista valor endereço proximo e anterior
void mostrar(Lista *lista){
    No *aux = lista->inicio;
    int i;
    for(i = 0; i < lista->tam; i++){
        printf("Valor: %d\n", aux->valor);
        printf("Endereço: %p\n", aux);
        printf("Anterior: %p\n", aux->ant);
        printf("Próximo: %p\n", aux->prox);
        printf("\n");
        aux = aux->prox;
    }
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tam = 0;

    int opcao;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 30);
    inserirInicio(&lista, 40);

    inserirFim(&lista, 50);

    inserirMeio(&lista, 60, 2); // 40 30 60 20 10 50

    removerMeio(&lista, 2); // 40 30 20 10 50




    do {
        printf("1 - Mostrar lista\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrar(&lista);
                break;
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao != 2);

    return 0;
}
