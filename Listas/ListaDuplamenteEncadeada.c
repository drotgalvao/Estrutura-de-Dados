#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

//Lista duplamente encadeada
typedef struct No{
    int valor;
    struct No *prox;
    struct No *ant;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

// inserir no inicio da lista
void inserirInicio(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor; // (*novo).valor = valor
    novo->prox = lista->inicio;
    novo->ant = NULL;
    if(lista->inicio != NULL){
        lista->inicio->ant = novo;
    }
    lista->inicio = novo;
    lista->tam++;	
}

// inserir no final da lista
void inserirFim(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    
    if(lista->inicio == NULL){  // lista vazia
        lista->inicio = novo;   // novo elemento é o inicio da lista
    }else{
        No *aux = lista->inicio;   // auxiliar para percorrer a lista
        while(aux->prox != NULL){  // percorre a lista até o ultimo elemento
            aux = aux->prox;       // aux recebe o proximo elemento
        }
        aux->prox = novo;          // o ultimo elemento recebe o novo elemento
        novo->ant = aux;
    }
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
        aux->prox = novo;
        lista->tam++;
    }
}

// remover no inicio da lista
void removerInicio(Lista *lista){
    if(lista->inicio != NULL){
        No *aux = lista->inicio;
        lista->inicio = lista->inicio->prox;
        lista->inicio->ant = NULL;
        free(aux);
        lista->tam--;
    }
}   

// remover no final da lista
void removerFim(Lista *lista){
    if(lista->inicio != NULL){
        No *aux = lista->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->ant->prox = NULL;
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
        for(i = 0; i < posicao; i++){
            aux = aux->prox;
        }
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        free(aux);
        lista->tam--;
    }
}

// imprimir lista
void imprimir(Lista *lista){
    No *aux = lista->inicio;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

// mostrar todos os elementos da lista
void mostrar(Lista *lista){
    No *aux = lista->inicio;
    while(aux != NULL){
        printf("Valor: %d\n", aux->valor);
        printf("Endereço: %p\n", aux);
        printf("Anterior: %p\n", aux->ant);
        printf("Próximo: %p\n", aux->prox);
        printf("\n");
        aux = aux->prox;
    }
}

int main(){
    Lista lista;

    lista.inicio = NULL;
    lista.tam = 0;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 30);
    inserirInicio(&lista, 40);
    inserirInicio(&lista, 50);

    inserirFim(&lista, 60); 

    inserirMeio(&lista, 70, 3); // 50 40 30 70 20 10 60

    removerMeio(&lista, 0); // 40 30 70 20 10 60

    mostrar(&lista);


}
