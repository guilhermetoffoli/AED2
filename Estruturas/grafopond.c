#include "grafopond.h"
#include <stdlib.h>
#include <stdio.h>

TipoGrafo *CriarGrafo(int NVertices) {
    int i, k;
    TipoGrafo *Grafo;
    if (NVertices <= 0) return NULL;
    Grafo = (TipoGrafo *) malloc(sizeof(TipoGrafo));
    if (Grafo == NULL) return NULL;

    Grafo->Mat = (int **) malloc(NVertices * sizeof(int *));
    if (Grafo->Mat == NULL) {
        free(Grafo);
        return NULL;
    }
    for (i = 0; i < NVertices; i++) {
        Grafo->Mat[i] = (int *) calloc(NVertices, sizeof(int));
        if (Grafo->Mat[i] == NULL) {
            for (k = 0; k < i; k++)
                free(Grafo->Mat[k]);
            free(Grafo);
            return NULL;
        }
    }
    Grafo->NumVertices = NVertices;
    Grafo->NumArestas = 0;
    return Grafo;
}

int inserirAresta(TipoGrafo *G, int v1, int v2, int peso) {
    if (G == NULL)
        return -1;
    if (v1 < 0 || v1 >= G->NumVertices || v2 < 0 || v2 >= G->NumVertices)
        return -1; // nao eh possivel criar aresta: intervalo
    if (G->Mat[v1][v2] == 0) {
        G->Mat[v1][v2] = peso;
        G->NumArestas++;
    }
    return 1;
}


int retirarAresta(TipoGrafo *G, int v1, int v2) {
    if (G == NULL)
        return -1; // grafo nao existe
    if (v1 < 0 || v1 >= G->NumVertices || v2 < 0 || v2 >= G->NumVertices)
        return -1; // nao eh possivel retirar aresta: intervalo
    if (G->Mat[v1][v2] == 0)
        return 0; // aresta nao existe
    G->Mat[v1][v2] = 0; //remove aresta
    G->NumArestas--;
    return 1;
}

void exibirGrafo(TipoGrafo *G) {
    int v, w;
    printf("\nGrafo - Resumo:\n");
    for (v = 0; v < G->NumVertices; ++v) {
        printf("%d:", v);
        for (w = 0; w < G->NumVertices; ++w)
            if (G->Mat[v][w] == 1)
                printf(" %d", w);
        printf("\n");
    }
}

void exibirMatriz(TipoGrafo *G) {
    int v, w;
    printf("\nGrafo - Matriz:\n");
    for (v = 0; v < G->NumVertices; ++v) {
        printf("%d:", v);
        for (w = 0; w < G->NumVertices; ++w)
            printf(" %d", G->Mat[v][w]);
        printf("\n");
    }
}

TipoGrafo *liberarGrafo(TipoGrafo *G) {
    int i;
    if (G == NULL)
        return NULL;

    for (i = 0; i < G->NumVertices; i++)
        free(G->Mat[i]);
    free(G->Mat);
    free(G);
    G = NULL;
    return G;
}

int ehNaoDirecionado(TipoGrafo *G) {
    int i, j;
    if (G == NULL)
        return -1;
    for (i = 0; i < G->NumVertices; i++) {
        for (j = 0; j < G->NumVertices; j++) {
            if (i == j && G->Mat[i][j] != 0)
                return 0;
            if (G->Mat[i][j] != G->Mat[j][i])
                return 0;
        }
    }
    return 1;
}

int grau(TipoGrafo *G, int v) {
    int i, j, grau = 0;
    if (G == NULL)
        return -1;
    for (i = 0; i < G->NumVertices; i++) {
        if (G->Mat[v][i] != 0)
            grau++;
    }
    if (!ehNaoDirecionado(G)) {
        for (i = 0; i < G->NumVertices; i++) {
            if (G->Mat[i][v] != 0)
                grau++;
        }
    }
    return grau;
}

// Verifica se dois vértices não adjacentes possuem um vizinho em comum
int vizinhoComum(TipoGrafo *G, int v1, int v2) {
    int i, j, v;
    if (G == NULL)
        return -1;
    if (v1 == v2 || G->Mat[v1][v2] != 0 || G->Mat[v2][v1] != 0)
        return 0;
    for (i = 0; i < G->NumVertices; i++) {
        if (G->Mat[v1][i] != 0 && G->Mat[v2][i] != 0)
            return 1;
    }
    return 0;
}

void caminhoMaisCurto(TipoGrafo *grafo, int origem){
    int *M = (int *) malloc (grafo->NumVertices * sizeof(int)); // Vértices visitados
    int *C = (int *) malloc (grafo->NumVertices * sizeof(int)); // Custos a partir da origem
    int *D = (int *) malloc (grafo->NumVertices * sizeof(int)); // Predecessor
    // Preenchimento preliminar dos vetores
    for (int i=0; i < grafo->NumVertices; i++) {
        M[i] = 0; // falso; vértice não visitado
        C[i] = 999999; // custo inicial para todos os vértices
        D[i] = 0;
    }

    M[origem] = 1;

    // Guardar as distâncias dos vértices alcançados a partir da origem
    for (int i = 0; i < grafo->NumVertices; ++i) {
        if (grafo->Mat[origem][i] != 0) {
            C[i] = grafo->Mat[origem][i];
        }
    }

    int S;
    int posmin;
    int found = 0;
    for (int i = 0; i < grafo->NumVertices; ++i) {
        found = 0;
        posmin = 999999;
        for (int j = 0; j < grafo->NumVertices; ++j) {
            if (C[j] < posmin && M[j] == 0) {
                found = 1;
                posmin = j;
            }
        }
        if (found == 0) break;
        M[posmin] = 1;
        for (int j = 0; j < grafo->NumVertices; ++j) {
            if(grafo->Mat[posmin][j] != 0 && M[j] == 0) {
                S = C[posmin] + grafo->Mat[posmin][j];
                if (S < C[j]) {
                    C[j] = S;
                    D[j] = posmin;
                }
            }
        }
    }

    printf("\nMenor caminho partindo de %d: \n",origem);
    for (int v = 0; v < grafo->NumVertices; v++) {
        if (C[v] == 999999)
            printf("%d: - \n",v);
        else
            printf("%d: %d\n",v,C[v]);
    }
}

int main() {
    TipoGrafo *g;
    int v;
    g = CriarGrafo(5);
    inserirAresta(g,1,2, 10);
    inserirAresta(g, 1, 3, 50);
    inserirAresta(g, 1, 4, 65);
    inserirAresta(g,2,3,30);
    inserirAresta(g,2,5,4);
    inserirAresta(g,3,4,20);
    inserirAresta(g,3,5,44);
    inserirAresta(g,4,2,70);
    inserirAresta(g,4,5,23);
    inserirAresta(g,5,1,6);
  //inserirAresta(g, 0, 3, 3);
    exibirGrafo(g);
    exibirMatriz(g);
    caminhoMaisCurto(g, 0);
}
