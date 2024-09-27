#include <stdio.h>
#include "grafo.h"

int main() {
    GrafoMatriz gMatriz;

    // Testando com o arquivo pcv4.txt
    printf("Testando com o arquivo pcv4.txt\n");
    carregarGrafoDistancias("pcv4.txt", &gMatriz);
    imprimirCaminhoBFS(&gMatriz, 0, 3);
    buscaProfundidadeDFS(&gMatriz, 0);

    // Testando com o arquivo pcv10.txt
    printf("\nTestando com o arquivo pcv10.txt\n");
    carregarGrafoDistancias("pcv10.txt", &gMatriz);
    imprimirCaminhoBFS(&gMatriz, 0, 9);
    buscaProfundidadeDFS(&gMatriz, 0);

    // Testando com o arquivo pcv50.txt
    printf("\nTestando com o arquivo pcv50.txt\n");
    carregarGrafoDistancias("pcv50.txt", &gMatriz);
    imprimirCaminhoBFS(&gMatriz, 0, 49);
    buscaProfundidadeDFS(&gMatriz, 0);

    // Testando com o arquivo pcv177.txt
    printf("\nTestando com o arquivo pcv177.txt\n");
    carregarGrafoDistancias("pcv177.txt", &gMatriz);
    imprimirCaminhoBFS(&gMatriz, 0, 176);
    buscaProfundidadeDFS(&gMatriz, 0);

    return 0;
}
