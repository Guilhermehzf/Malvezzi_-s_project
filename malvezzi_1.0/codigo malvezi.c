/*
Faça um Programa utilizando as seguintes funcionalidades:

Escolha o número referente ao desafio desejado:
 (0) - Sair
 (1) - Imprime uma reta (Algoritmo DDA)
 (2) - Imprime uma reta (Algoritmo de Bresenham)
 (3) - Imprime o traçado de um círculo (Algoritmo de Bresenham)
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
void main(){
    setlocale(LC_ALL, "Portuguese");
    int v_v = 1;
    while(v_v != 0){
        printf("(0) - Sair\n(1) - Imprime uma reta (Algoritmo DDA)\n(2) - Imprime uma reta (Algoritmo de Bresenham)\n(3) - Imprime o traçado de um círculo (Algoritmo de Bresenham)\nEscolha o número referente ao desafio desejado:");
        scanf("%d", &v_v);
        if(v_v == 1){
            printf("--------------------------------------\n");
            printf("(1) - Imprime uma reta (Algoritmo DDA)\n");
            printf("--------------------------------------\n");
        }
        if(v_v == 2){
            printf("-----------------------------------------------\n");
            printf("(2) - Imprime uma reta (Algoritmo de Bresenham)\n");
            printf("-----------------------------------------------\n");
        }
        if(v_v == 3){
            printf("--------------------------------------------------------------\n");
            printf("(3) - Imprime o traçado de um círculo (Algoritmo de Bresenham)\n");
            printf("--------------------------------------------------------------\n");
        }

    }
    printf("você escolheu sair\n");
    system ("pause");


}
