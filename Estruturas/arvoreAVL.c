#include <stdio.h>
#include<stdlib.h>
#include "arvoreAVL.h"

struct no{
    int info;
    int alt;
    struct no *esq;
    struct no *dir;
};

ArvAVL * cria_arvore(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
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

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL) return;
    libera_no(*raiz);
    free(raiz);
}

int estaVazia(ArvAVL *raiz){
    if(raiz == NULL) return 1;
    if(*raiz == NULL) return 1;
    return 0;
}

int altura_arv(ArvAVL *raiz){
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;

    int alt_esq = altura_arv(&((*raiz)->esq));
    int alt_dir = altura_arv(&((*raiz)->dir));
    if(alt_esq > alt_dir) 
        return (alt_esq+1);
    else
        return (alt_dir+1);
}

int totalNo_arv(ArvAVL *raiz){
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;

    int alt_esq = totalNo_arv(&((*raiz)->esq));
    int alt_dir = totalNo_arv(&((*raiz)->dir));

    return (alt_dir+alt_esq+1)
}
