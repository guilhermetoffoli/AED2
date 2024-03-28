#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

TipoGrafo* CriarGrafo(int NVertices){
   int i, k;
   TipoGrafo *Grafo;
   if ( NVertices <= 0) return NULL;
   Grafo = (TipoGrafo*) malloc(sizeof(TipoGrafo));
   if (Grafo == NULL) return NULL;
 
   Grafo->Mat = (int **) malloc(NVertices*sizeof(int*));
   if (Grafo->Mat == NULL) {
      free(Grafo);
      return NULL;
   }
   for(i=0; i<NVertices; i++) {
      Grafo->Mat[i] = (int*) calloc (NVertices,sizeof(int));
      if (Grafo->Mat[i] == NULL) {
          for (k=0; k<i; k++)
             free(Grafo->Mat[k]);
          free(Grafo) ;
          return NULL;
      }
   }
   Grafo->NumVertices = NVertices;
   Grafo->NumArestas = 0;
   return Grafo;
}

int inserirAresta(TipoGrafo *G, int v1, int v2) { 
  if (G == NULL)
     return -1;
  if (v1<0 || v1>= G-> NumVertices || v2 < 0 || v2 >= G->NumVertices)
     return -1; // nao eh possivel criar aresta: intervalo
  if (G->Mat[v1][v2] == 0) {
        G->Mat[v1][v2] = 1; 
        G->NumArestas++;
   }
  return 1;
}


int retirarAresta(TipoGrafo *G, int v1, int v2){
   if (G == NULL)
      return -1; // grafo nao existe
   if (v1<0 || v1>=G->NumVertices || v2<0 || v2>=G-> NumVertices)
      return -1; // nao eh possivel retirar aresta: intervalo
   if( G->Mat[v1][v2] == 0)
      return 0; // aresta nao existe
   G->Mat[v1][v2] = 0; //remove aresta
   G->NumArestas--;
   return 1;
}

void exibirGrafo(TipoGrafo *G) { 
   int v, w; 
   printf("\nGrafo - Resumo:\n");
   for (v = 0; v < G->NumVertices; ++v) {
       printf( "%d:", v);
       for (w = 0; w < G->NumVertices; ++w)
          if (G->Mat[v][w] == 1) 
               printf( " %d",w );
       printf( "\n");
   }
}

void exibirMatriz(TipoGrafo *G) { 
   int v, w; 
   printf("\nGrafo - Matriz:\n");
   for (v = 0; v < G->NumVertices; ++v) {
       printf( "%d:", v);
       for (w = 0; w < G->NumVertices; ++w)
            printf( " %d",G->Mat[v][w] );
       printf( "\n");
   }
}

TipoGrafo* liberarGrafo(TipoGrafo* G){
   int i;
   if (G == NULL)
      return NULL;

   for(i=0; i< G->NumVertices; i++)
      free(G->Mat[i]);
   free(G->Mat);
   free(G);
   G = NULL;
   return G;
}

int ehNaoDirecionado(TipoGrafo *G){
int i,j;  
    if (G == NULL)
        return -1;
    for (i = 0; i < G->NumVertices; i++) {
        for (j = 0; j < G->NumVertices; j++){
            if (i == j && G->Mat[i][j] != 0)
                return 0;
            if (G->Mat[i][j] != G->Mat[j][i])
                return 0;
        }
    }
    return 1;
}

int grau(TipoGrafo *G, int v){
  int i,j,grau = 0;  
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
int vizinhoComum(TipoGrafo *G, int v1, int v2){
  int i,j,v;  
  if (G == NULL)
        return -1;
  if (v1 == v2 || G->Mat[v1][v2] != 0 || G->Mat[v2][v1]!= 0)
        return 0;
  for (i = 0; i < G->NumVertices; i++) {
       if (G->Mat[v1][i] != 0 && G->Mat[v2][i] != 0) 
           return 1;
  }
  return 0;
}

int main() {
  TipoGrafo *g;
  int v;
  g = CriarGrafo(5);
  inserirAresta(g,0,2);
  inserirAresta(g,2,0);
  inserirAresta(g,1,4);
  inserirAresta(g,4,1);
  inserirAresta(g,2,3); 
  inserirAresta(g,3,2);
  inserirAresta(g,2,1);
  inserirAresta(g,1,2);
  inserirAresta(g,1,3);
  inserirAresta(g,3,1);
  //inserirAresta(g,3,4);
  
  exibirMatriz(g);
  exibirGrafo(g);
  //retirarAresta(g,2,4);
  //exibirGrafo(g);
  v = ehNaoDirecionado(g);
  if (v==1)
     printf("Grafo não direcionado");
  else
     printf("Grafo direcionado");
  printf("\nGrau do vértice 3: %d", grau(g,3));
  v = vizinhoComum(g,1,3);
  printf("\nVizinhos em Comum (1) e (3) -> %d\n",v);

  g = liberarGrafo(g);
  return 0;
}