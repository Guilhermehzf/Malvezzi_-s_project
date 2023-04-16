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
#include<math.h> //Operações matemáticas
#include<windows.h> //Inclui as bibliotecas gráficas

//Método que faz o apontamento das coordenadas X e Y
void irParaXY(int x, int y) {
	COORD coord;
	coord.X = (short) x;
	coord.Y = (short) y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Método que imprime o plano cartesiano na tela
void planoCartesiano(void) {
	int vertical, horizontal;
	for (vertical = 14; vertical < 55 ; vertical++) {//Reta que separa o plano na vertical
    	irParaXY(118, vertical);
        printf("|");
	}
	for (horizontal = 18; horizontal < 219; horizontal++) {//Reta que separa o plano na horizontal
        irParaXY(horizontal, 34);
        printf("-");
	}
	irParaXY(118, 34);
    printf("X");//Ponto central
}



//Desloca X em 118 + X
int setX(int x) {
	return (118 + x);
}

//Desloca Y em 34- Y
int setY(int y) {
	return (34 - y);
}

int algoritimo_DDA(double x1, double y1, double x2, double y2){
	double aux, auy, step, xinc, yinc;

	if(abs(x2- x1) > abs(y2-y1))
    	step = (x2-x1);

	else
    	step = abs(y2-y1);

	xinc = (x2 - x1)/step;
	yinc = (y2 - y1)/step;
	int contador = 0;
	for(int c = 0; c <= step; c++){
    	int x = round(setX(x1 + c * xinc));
    	int y = round(setY(y1 + c * yinc));
            if(contador == 0){
             printf("M");
            }
            else if(contador == 1){
             printf("a");
            }
            else if(contador == 2){
             printf("l");
            }
            else if(contador == 3){
             printf("v");
            }
            else if(contador == 4){
             printf("e");
            }
            else if(contador == 5 || contador == 6){
             printf("z");
            }
            else if(contador == 7){
             printf("i");
             contador = -1;
            }
            contador++;
            irParaXY(setX(round(x)), setY(round(y)));
	}
}
void algoritmo_Bresenham(double x1, double y1, double x2, double y2) {
	double d_x, d_y, p, incE, incNE, x, y;

	d_x = fabs(x2 - x1);
	d_y = fabs(y2 - y1);
	p = 2 * d_y - d_x;

	// verificando a inclinação da reta
	if (d_y <= d_x) {  // inclinação menor ou igual a 45 graus
    	incE = 2 * d_y;
    	incNE = 2 * d_y - 2 * d_x;

    	if (x1 <= x2) {
        	x = x1;
        	y = y1;
    	}
    	else {
        	x = x2;
        	y = y2;
        	x2 = x1;
        	y2 = y1;
    	}
        int contador = 0;
    	while (x <= x2) {
            irParaXY(setX(round(x)), setY(round(y)));

            if(contador == 0){
             printf("M");
            }
            else if(contador == 1){
             printf("a");
            }
            else if(contador == 2){
             printf("l");
            }
            else if(contador == 3){
             printf("v");
            }
            else if(contador == 4){
             printf("e");
            }
            else if(contador == 5 || contador == 6){
             printf("z");
            }
            else if(contador == 7){
             printf("i");
             contador = -1;
            }
            contador++;

        	if (p <= 0) {
            	p = p + incE;
        	} else {
            	p = p + incNE;
            	y = y + ((y2 >= y1) ? 1 : -1);
        	}
        	x++;
    	}

	} else {  // inclinação maior que 45 graus
    	incE = 2 * d_x;
    	incNE = 2 * d_x - 2 * d_y;

    	if (y1 <= y2) {
        	x = x1;
        	y = y1;
    	} else {
        	x = x2;
        	y = y2;
        	y2 = y1;
        	x2 = x1;
    	}
    	int contador = 0;
    	while (y <= y2) {
            /* Malvezzi */
            irParaXY(setX(round(x)), setY(round(y)));
            if(contador == 0){
             printf("M");
            }
            else if(contador == 1){
             printf("a");
            }
            else if(contador == 2){
             printf("l");
            }
            else if(contador == 3){
             printf("v");
            }
            else if(contador == 4){
             printf("e");
            }
            else if(contador == 5 || contador == 6){
             printf("z");
            }
            else if(contador == 7){
             printf("i");
             contador = -1;
            }
            contador++;
        	if (p <= 0) {
            	p = p + incE;
        	} else {
            	p = p + incNE;
            	x = x + ((x2 >= x1) ? 1 : -1);
        	}
   	     y++;
    	}
	}
}
int algoritmo_Bresenham_circulo(int r){
	int x = 0, y = r, p = 1 - r;

	while(x <= r){

        irParaXY(setX(+x), setY(+y));
        printf("°");
        irParaXY(setX(+x), setY(-y));
        printf("°");
    	irParaXY(setX(-x), setY(+y));
        printf("°");
        irParaXY(setX(-x), setY(-y));
        printf("°");
        irParaXY(setX(+y), setY(+x));
        printf("°");
        irParaXY(setX(+y), setY(-x));
        printf("°");
        irParaXY(setX(-y), setY(+x));
        printf("°");
        irParaXY(setX(-y), setY(-x));
        printf("°");

    	if (p <= 0) {
        	p = p+2*x+1;
    	}
    	else {
        	p = p+2*x+1-2*y;
        	y--;
    	}
    	x++;
	}
}


void main(){
	setlocale(LC_ALL, "Portuguese");
	int v_v = 1;
	while(v_v != 0){
        printf("(0) - Sair\n(1) - Imprime uma reta (Algoritmo DDA)\n(2) - Imprime uma reta (Algoritmo de Bresenham)\n(3) - Imprime o traçado de um círculo (Algoritmo de Bresenham)\nEscolha o número referente ao desafio desejado:");
        scanf("%d", &v_v);
    	if(v_v == 1){
            printf("Você escolheu o algoritimo DDA --> 1\n");
        	int x1, x2, y1, y2;
            printf("escolha o valor de x1: ");
            scanf("%d", &x1);
            printf("escolha o valor de x2: ");
            scanf("%d", &x2);
            printf("escolha o valor de y1: ");
            scanf("%d",&y1);
            printf("escolha o valor de y2: ");
            scanf("%d", &y2);
            planoCartesiano();
            algoritimo_DDA(x1, y1, x2, y2);
            irParaXY(0,15);
        	system ("pause");
            system("cls");
    	}
    	if(v_v == 2){
        	printf("Você escolheu o algoritimo algoritimo_Bresenham --> 2\n");
        	int x1, x2, y1, y2;
            printf("escolha o valor de x1: ");
            scanf("%d", &x1);
            printf("escolha o valor de x2: ");
            scanf("%d", &x2);
	        printf("escolha o valor de y1: ");
            scanf("%d",&y1);
            printf("escolha o valor de y2: ");
            scanf("%d", &y2);
            planoCartesiano();
            algoritmo_Bresenham(x1, y1, x2, y2);
            irParaXY(0,15);
        	system ("pause");
            system("cls");
    	}
    	if(v_v == 3){
            printf("Você escolheu algoritimo_Bresenham traçado de um círculo --> 3\n");
        	int raio;
            printf("escolha o valor do raio: ");
            scanf("%d", &raio);
        	abs(raio);
            planoCartesiano();
            algoritmo_Bresenham_circulo(raio);
            irParaXY(0,15);
        	system ("pause");
            system("cls");
    	}

	}
	printf("você escolheu sair\n");
	system ("pause");



}
