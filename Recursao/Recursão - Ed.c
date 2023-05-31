#include <stdio.h>
#include <stdlib.h>

typedef struct sLista {
    int info;
    struct sLista *next;
}lista;

void inicializar(lista **L) {
    *L = NULL;
}

lista* getnode() {
    return (lista*) malloc (sizeof(lista));
}

void freenode(lista *L) {
    free(L);
}

int vazia(lista *L) {
    if(L == NULL)
        return 1;
    return 0;
}

void inserir_fim(lista **L, int elem) {
    lista *q;
    lista *aux;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->next = NULL;

        if(vazia(*L))
            *L = q;
        else {
            aux = *L;
            while(aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = q;
        }
    } else {
        printf("\nErro! - Nao foi possivel alocar o no");
    }
}

int tamanho_lista(lista *L) {

    if(vazia(L))
        return 0;
    else
        return 1 + tamanho_lista(L->next);
}

int somar_elementos(lista *L) {

    if(vazia(L))
        return 0;
    else
        return L->info + somar_elementos(L->next);
}

int multiplicar_elementos(lista *L) {

    if(vazia(L))
        return 0;
    else if(vazia(L->next))
        return L->info;
    else
        return L->info * multiplicar_elementos(L->next);
}

void elementos_impares(lista *L) {

    if(vazia(L->next)) {
        if(L->info %2 != 0)
            printf("[%d]", L->info);
    }
    else {
        if(L->info %2 != 0)
            printf("[%d] ", L->info);
        elementos_impares(L->next);
    }
}

void elementos_impares_inverso(lista *L) {

    if(vazia(L->next)) {
        if(L->info %2 != 0)
            printf("[%d]", L->info);
    }
    else {
        elementos_impares_inverso(L->next);
        if(L->info %2 != 0)
            printf("[%d] ", L->info);
    }
}

void elementos_pares(lista *L) {

    if(vazia(L->next)) {
        if(L->info %2 == 0)
            printf("[%d]", L->info);
    }
    else {
        if(L->info %2 == 0)
            printf("[%d] ", L->info);
        elementos_pares(L->next);
    }
}

void elementos_pares_inverso(lista *L) {

    if(vazia(L->next)) {
        if(L->info %2 == 0)
            printf("[%d]", L->info);
    }
    else {
        elementos_pares_inverso(L->next);
        if(L->info %2 == 0)
            printf(" [%d]", L->info);
    }
}

int soma_caracteres(int elem) {

    if(elem < 10)
        return elem;
    else
        return elem %10 + soma_caracteres(elem / 10);
}

int subtracao_caracteres(int elem) {

    if(elem < 10)
        return elem;
    else
        return elem %10 - subtracao_caracteres(elem / 10);
}

int multiplicacao_caracteres(int elem) {

    if(elem < 10)
        return elem;
    else
        return elem %10 * multiplicacao_caracteres(elem / 10);
}

int divisao_caracteres(int elem) {

    if(elem < 10)
        return elem;
    else
        return elem %10 / divisao_caracteres(elem / 10);
}

void exibir_lista(lista **L) {
    lista *aux = *L;

    if(vazia(*L)) {
        printf("\nErro! - Lista vazia");
        return;
    }
    while(aux != NULL) {
        printf("[%d] ", aux->info);
        aux = aux->next;
    }
}

void menu() {
    printf("\n\n----PROGRAMA DESENVOLVIDO UTILIZANDO RECURSAO COM UMA LISTA DINAMICA----\n\n\n");
    printf("---------------MENU----------------\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Exibir tamanho da lista\n");
    printf("3 - Soma dos elementos da lista\n");
    printf("4 - Multiplicacao dos elementos da lista\n");
    printf("5 - Elementos impares da lista\n");
    printf("6 - Elementos impares da lista na ordem inversa\n");
    printf("7 - Elementos pares da lista\n");
    printf("8 - Elementos pares da lista na ordem inversa\n");
    printf("9 - Soma dos caracteres de um numero inteiro\n");
    printf("10 - Subtracao dos caracteres de um numero inteiro\n");
    printf("11 - Multiplicacao dos caracteres de um numero inteiro\n");
    printf("12 - Divisao dos caracteres de um numero inteiro\n");
    printf("13 - Exibir lista\n");
    printf("0 - Sair\n");
    printf("----------------------------------");
}

void main() {
    lista *L;
    int elem, valor, opcao;

    inicializar(&L);

    do {
        menu();
        printf("\n\nInforme a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nInforme o valor que deseja inserir na lista: ");
                scanf("%d", &valor);
                inserir_fim(&L, valor);
                break;

            case 2:
                printf("\nTamanho: %d", tamanho_lista(L));
                printf("\n");
                break;

            case 3:
                printf("\nSoma dos elementos da lista: %d", somar_elementos(L));
                printf("\n");
                break;

            case 4:
                printf("\nMultiplicacao dos elementos da lista: %d", multiplicar_elementos(L));
                printf("\n");
                break;

            case 5:
                printf("\nElementos impares da lista: ");
                elementos_impares(L);
                printf("\n");
                break;

            case 6:
                printf("\nElementos impares na ordem inversa da lista: ");
                elementos_impares_inverso(L);
                printf("\n");
                break;

            case 7:
                printf("\nElementos pares da lista: ");
                elementos_pares(L);
                printf("\n");
                break;

            case 8:
                printf("\nElementos pares na ordem inversa da lista: ");
                elementos_pares_inverso(L);
                printf("\n");
                break;

            case 9:
                printf("\nInforme um elemento inteiro: ");
                scanf("%d", &elem);
                printf("Soma dos caracteres do numero [%d]: %d", elem, soma_caracteres(elem));
                printf("\n");
                break;

            case 10:
                printf("\nInforme um elemento inteiro: ");
                scanf("%d", &elem);
                printf("\nSubtracao dos caracteres do numero [%d]: %d", elem, subtracao_caracteres(elem));
                printf("\n");
                break;

            case 11:
                printf("\nInforme um elemento inteiro: ");
                scanf("%d", &elem);
                printf("\nMultiplicacao dos caracteres do numero [%d]: %d", elem, multiplicacao_caracteres(elem));
                printf("\n");
                break;

            case 12:
                printf("\nInforme um elemento inteiro: ");
                scanf("%d", &elem);
                printf("\nDivisao dos caracteres do numero inteiro: %d", divisao_caracteres(elem));
                printf("\n");
                break;

            case 13:
                printf("\nLista: ");
                exibir_lista(&L);
                printf("\n");
                break;

            case 0:
                printf("\nSaindo...");
                break;

            default:
                printf("\nOpcao invalida");
                break;
        }
        system("pause");
        system("cls");

    }while(opcao != 0);
}
