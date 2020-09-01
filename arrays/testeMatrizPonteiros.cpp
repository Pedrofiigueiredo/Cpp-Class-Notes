/*
	Alocação dinâmica é usada quando eu não sei o tamanho da
	matriz ou do vetor que eu vou lidar.

	Exemplo: receber uma foto de um usuário em uma aplicação
	web (Facebook por exemplo). As fotos tem tamanhos diferentes.
	Então uma alocação dinâmica recebe primeiro o tamanho da foto,
	para então alocar espaços na memória e mostrar a foto.
*/

#include <iostream>

using namespace std;

// Definir constates: define
#define LINHAS 5
#define COLUNAS 7

void imprimeMatriz(int **m) {
	for(int i=0; i<LINHAS; i++) {
		for(int j=0; j<COLUNAS; j++)
			cout<<m[i][j]<<"   ";

		cout<<endl;
	}
}

int main() {
	int **matriz;
	matriz = new int *[LINHAS];

	// Alocação
	for(int i=0; i<LINHAS; i++) {
		matriz[i] = new int [COLUNAS];
	}

	/*
		Criando uma matriz com alocação eśtática, os valores da
		matriz estão alocados em uma única "tabela". No caso de
		uma matriz 5x7, são 35 "linhas" na memória reservada para
		essa matriz.

		Alocando uma matriz dinamicamente - com ponteiros - os
		espaços de memória que armazenam as linhas não
		necessáriamente estarão agrupadas ou organizadas.
		Mas isso não faz diferença para o programador, o programa
		funciona da mesma maneira.
	*/


	// Inicialização (igual a inicialização em alocação estática)
	for(int i=0; i<LINHAS; i++) {
		for(int j=0; j<COLUNAS; j++)
			matriz[i][j] = i+j;
	}

	imprimeMatriz(matriz);
}
