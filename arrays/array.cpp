/*
	Básico de vetores, matrizes e ponteiros em C++
	
	VETORES
	* <tipo do vetor> <nome da variável> <[tamanho]>
	* Indexação inicia em 0

	MATRIZES
	* <tipo da matriz> <nome da variável> <[linhas][colunas]>
	* Matrizes de N dimensões

	PONTEIROS
	* É um endereço de memória. Um endereço de memória em 
		um computador é sempre um inteiro.
	* C, C++ são duas das poucas linguagens que permitem
		a manipulação de endereços de memória

	* int *ponteiro; - a declaração diz que a variável 
		ponteiro é um endereço que memória que armazena um int.

	* Trabalhando com ponteiros, eu não uso variáveis e altero
		o valor dessas variáveis, eu trabalho com endereços de
		memória e coloco valores neles.
*/

#include <iostream>
using namespace std;

void vetores()
{
	// 
	int numeros[5]; // Cria um vetor com 5 posições definidas
	char letras[5]; // Vetor de caracteres com 5 posições

	int vetor[5] = {23, 35, 75, 26, 17};
	cout<<vetor[0]<<endl; // Imprime o valor 23
	cout<<vetor[1]<<endl; // 35
	cout<<vetor[2]<<endl; // 75
	cout<<vetor[3]<<endl; //26
	cout<<vetor[4]<<endl; // 17
	cout<<vetor[5]<<endl; // Qualquer coisa que estiver na memória

	int vetorA[5] = {23, 56, 75}; // Reserva 5 posições, então duas ficam em aberto
	int vetorB[] = {23, 56, 75}; // Assume 3 posições definidas

	int vetorC[5] = {1, 2, 3};
	cout<<vetor[5]; // Retorna um lixo (se o SO conseguir converter para int - ou para o tipo do vetor em questão)
}

void matriz()
{
	int matriz[5][7]; // Matriz com 5 linhas e 7 colunas
	char matriz_grande[125][250][12][300][1200];

	// Matrizes de N dimensões
	// * Coordenadas X e Y e altura
	// * Coordenadas X e Y, altura e região do local (sul, sudeste, norte, nordeste, centro-oeste)
	// * X, Y, altura, região, tempo...
}

void ponteiro()
{
	// Declaração
	int *ponteiro; // ponteiro (nome) vai ser um endereço para inteiro
	// cout<<ponteiro;

	// Atribuição
	*ponteiro = 5; // O valor apontado por ponteiro é = 5
	ponteiro = new int;

	cout<<&ponteiro;

	// Alocação dinâmica de uma matriz (mais de uma dimensão)
	/*
		Ponteiros e ponteiros de ponteiros

		int **matriz; // Declaração

		// Alocação
		matriz = new *int[5]
		for(int i=0; i<5; i++)
			matriz[i] = new int[7];

		// Inicialização (atribuir valores)
		for(int i=0; i<5; i++)
			for(int j=0; j<7; j++)
				matriz[i][j] = 0; // Todos os valores iguais a 0;
	*/

}

int main()
{
	ponteiro();

	return 0;
}