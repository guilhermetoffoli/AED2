/*
Arvore Binaria: cada vértice pode ter duas 'sub-arvores', direita e        esquerda, o grau delas (n de filhos) pode ser 0, 1 ou 2

Funções: Criar, inserir, remover, acessar e destruir
Dependem do tipo de alocação de memória:
    -Estática (heap)
    -Dinâmica (Lista encadeada)

Estática (heap)

    -Usa array
    -Usa função para retornar a posição dos filhos a esq e a dir
    filho_esq(PAI) = 2*PAI+1
    filho_dir(PAI) = 2*PAI+2

Dinâmica (L Encadeada)
    -Cada nó é tratado como um ponteiro alocado dinamicamente
    (ponteiro pra esq, dir e o dado)
*/

#include <stdio.h>
#include<stdlib.h>
#include "arvoreBin.h"

struct no{
    int info;
    struct no *esq;
    struct no *dir;
};

ArvBin * cria_arvore(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if (raiz != NULL){
        *raiz = NULL; //apontando pra null
    }
    return raiz;
}

void libera_no(struct no* no){
    if(no == NULL) return;
    libera_no(no->esq);
    libera_no(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL) return;
    libera_no(*raiz);
    free(raiz);
}

int estaVazia(ArvBin *raiz){
    if(raiz == NULL) return 1;
    if(*raiz == NULL) return 1;
    return 0;
}

int altura_arv(ArvBin *raiz){
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;

    int alt_esq = altura_arv(&((*raiz)->esq));
    int alt_dir = altura_arv(&((*raiz)->dir));
    if(alt_esq > alt_dir) 
        return (alt_esq+1);
    else
        return (alt_dir+1);
}

int totalNo_arv(ArvBin *raiz){
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;

    int alt_esq = totalNo_arv(&((*raiz)->esq));
    int alt_dir = totalNo_arv(&((*raiz)->dir));

    return (alt_dir+alt_esq+1)
}

int insere_Arv(ArvBin * raiz, int valor){
    if (raiz == NULL) return 0;

    struct no* novo = (struct no*) malloc(sizeof(struct no));

    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct no* atual = *raiz;
        struct no* ant = NULL;
        while (atual != NULL){          //Navegar os nos até chegar em 
            ant = atual;                   //no folha
            if(valor == atual->info){
                free(novo);
                return 0;
            }
            if(valor > atual->info)     //insere como filho do nó folha
                atual = atual->dir;     //Seguindo a ordem estabelecida
            else                        // no->esq < raiz < no->dir
                atual = atual->esq;
        }
    if(valor > ant->info)
        ant->dir = novo;
    else
        ant->esq = novo;
    }
    return 1;
}