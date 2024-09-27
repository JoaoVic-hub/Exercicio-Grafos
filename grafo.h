#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 200

// Estrutura do Grafo usando Matriz de Adjacência
typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} GrafoMatriz;

// Funções de manipulação do grafo
void carregarGrafoDistancias(char* nomeArquivo, GrafoMatriz* gMatriz);
void imprimirCaminhoBFS(GrafoMatriz* gMatriz, int inicio, int destino);
void buscaProfundidadeDFS(GrafoMatriz* gMatriz, int inicio);

#endif
