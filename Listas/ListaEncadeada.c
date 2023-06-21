#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct No{
	int valor;
	struct No *prox;
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
	lista->inicio = novo;
	lista->tam++;	
}

// inserir no final da lista
void inserirFim(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        No *aux = lista->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
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
        aux->prox = novo;
        lista->tam++;
    }
}

// remover no inicio da lista e retorna o primeiro nó
No* removerInicio(Lista *lista){
    if(lista->inicio == NULL){
        printf("Lista vazia!\n");
        return NULL;
    }else{
        No *aux = lista->inicio;
        lista->inicio = aux->prox;
        lista->tam--;
        return aux;
    }
}

// dividir uma lista em duas
void dividir(Lista *lista, Lista *lista1, Lista *lista2) {
    int i = 0;
    No *atual = lista->inicio;
    
    while (atual != NULL) {
        if (i % 2 == 0) {
            inserirFim(lista1, atual->valor);
        } else {
            inserirFim(lista2, atual->valor);
        }
        
        i++;
        atual = atual->prox;
    }
}

// dividir uma lista em duas utilizando a função removerInicio
void dividirRemover(Lista *lista, Lista *lista1, Lista *lista2) {
    int i = 0;
    
    while (lista->inicio != NULL) {
        if (i % 2 == 0) {
            inserirFim(lista1, lista->inicio->valor);
        } else {
            inserirFim(lista2, lista->inicio->valor);
        }
        
        removerInicio(lista);
        i++;
    }
}

// imprimir a lista
void imprimir(Lista *lista){
	No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL){
        printf("%d\n", inicio->valor);
        inicio = inicio->prox;
    }
    printf("\n\n");
}

// imprimir a lista 1
void imprimir1(Lista *lista){
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL){
        printf("%d\n", inicio->valor);
        inicio = inicio->prox;
    }
    printf("\n\n");
}

// imprimir a lista 2
void imprimir2(Lista *lista){
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL){
        printf("%d\n", inicio->valor);
        inicio = inicio->prox;
    }
    printf("\n\n");
}


int main() {
    setlocale(LC_ALL, "Portuguese");
	Lista lista;
    Lista lista1;
    Lista lista2;
    int opcao, valor;
    lista.inicio = NULL;
	lista.tam = 0;
    lista1.inicio = NULL;
    lista1.tam = 0;
    lista2.inicio = NULL;
    lista2.tam = 0;

    do{
        printf("1 - Inserir no inicio\n"
                "2 - Imprimir\n"
                "3 - Inserir no fim\n"
                "4 - Inserir no meio da lista depois de certa posição\n"
                "5 - Dividir a lista em duas indices pares lista 1 indices impares lista 2\n"
                "6 - Imprimir a lista 1\n"
                "7 - Imprimir a lista 2\n"
                "8 - Dividir a lista em duas removendo a lista original indices pares lista 1 indices impares lista 2\n"
                "10 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirInicio(&lista, valor);
                break;
            case 2:
                imprimir(&lista);
                break;
            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirFim(&lista, valor);
                break;
            case 4:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("Digite a posicao: ");
                scanf("%d", &opcao);
                inserirMeio(&lista, valor, opcao);
                break;
            case 5:
                dividir(&lista, &lista1, &lista2);
                break;
            case 6:
                imprimir1(&lista1);
                break;
            case 7:
                imprimir2(&lista2);
                break;
            case 8:
                dividirRemover(&lista, &lista1, &lista2);
                break;
            case 10:
                printf("Saindo...");
                break;
            default:
                printf("Opcao invalida!\n");
        }
     } while(opcao != 10);
	


    return 0;
}
