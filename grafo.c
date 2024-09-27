#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include <stdbool.h>

void carregarGrafoDistancias(char* nomeArquivo, GrafoMatriz* gMatriz) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo: %s\n", nomeArquivo);
        return;
    }

    fscanf(arquivo, "%d", &gMatriz->numVertices);
    for (int i = 0; i < gMatriz->numVertices; i++) {
        for (int j = 0; j < gMatriz->numVertices; j++) {
            fscanf(arquivo, "%d", &gMatriz->adjMatrix[i][j]);
        }
    }
    fclose(arquivo);
}

void imprimirCaminhoBFS(GrafoMatriz* gMatriz, int inicio, int destino) {
    int fila[MAX_VERTICES], frente = 0, tras = 0;
    bool visitado[MAX_VERTICES] = {false};
    int anterior[MAX_VERTICES];
    
    for (int i = 0; i < gMatriz->numVertices; i++) {
        anterior[i] = -1;  // Inicializando o array para rastrear o caminho
    }

    fila[tras++] = inicio;
    visitado[inicio] = true;

    while (frente < tras) {
        int verticeAtual = fila[frente++];
        for (int i = 0; i < gMatriz->numVertices; i++) {
            if (gMatriz->adjMatrix[verticeAtual][i] != 0 && !visitado[i]) {
                fila[tras++] = i;
                visitado[i] = true;
                anterior[i] = verticeAtual;  // Guardar de onde viemos

                // Se encontramos o destino
                if (i == destino) {
                    printf("Caminho entre %d e %d: ", inicio, destino);
                    int caminho[MAX_VERTICES];
                    int tamanhoCaminho = 0;
                    for (int v = destino; v != -1; v = anterior[v]) {
                        caminho[tamanhoCaminho++] = v;
                    }
                    for (int j = tamanhoCaminho - 1; j >= 0; j--) {
                        if(j != tamanhoCaminho){
                            printf("-> ");
                        }
                        printf("%d ", caminho[j]);
                    }
                    printf("\n");
                    return;
                }
            }
        }
    }

    printf("Nao ha caminho entre %d e %d\n", inicio, destino);
}

void buscaProfundidadeDFS(GrafoMatriz* gMatriz, int inicio) {
    bool visitado[MAX_VERTICES] = {false};
    int pilha[MAX_VERTICES], topo = -1;

    pilha[++topo] = inicio;
    visitado[inicio] = true;

    printf("Busca em profundidade a partir do vertice %d: ", inicio);

    while (topo >= 0) {
        int verticeAtual = pilha[topo--];
        printf("%d ", verticeAtual);

        for (int i = 0; i < gMatriz->numVertices; i++) {
            if (gMatriz->adjMatrix[verticeAtual][i] != 0 && !visitado[i]) {
                pilha[++topo] = i;
                visitado[i] = true;
            }
        }
    }
    printf("\n");
}
