#include <iostream>

using namespace std;

void imprimeMatriz(int m[5][7]) 
{
	for(int i=0; i<5; i++) {
		for(int j=0; j<7; j++)
			cout<< m[i][j]<<"   ";

		cout<<endl;
	}
}

int main()
{
	int matriz[5][7]; // Cria matriz de 5 linhas por 7 colunas

	// Inicializando a matriz
	for(int i=0; i<5; i++) {
		for(int j=0; j<7; j++)
			matriz[i][j] = i+j;
	}

	imprimeMatriz(matriz);
}