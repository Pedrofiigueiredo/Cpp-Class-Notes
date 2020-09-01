#include <iostream>

using namespace std;

int main()
{
	int valor; // Declara uma variável inteira
	int *p_valor; // Declara ponteiro para inteiro

	cout<<valor<<endl; // Mostra o que tem na variável valor (lixo por enquanto)
	cout<<p_valor<<endl; // Mostra o endereço de memória do ponteiro p_valor

	valor = 25; // Atribui na variável valor o número 25
	p_valor = new int; // Alocação de memória do ponteiro p_valor para 1 int (reserva um espaço de memória)
	*p_valor = 26; // Atribuindo para o ponteiro p_valor o número 26

	// & Endereço do ponteiro
	// * Valor do ponteiro

	cout<<"\n-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-"<<endl;
	cout<<valor<<endl; // Impime o valor da variável valor
	cout<<&valor<<endl; //Imprime o endereço da variável valor

	cout<<p_valor<<endl; // Imprime o valor do ponteiro p_valor (0x...)
	cout<<*p_valor<<endl; // Imprime o valor apondado pelo ponteiro p_valor (26)

	// Valor do ponteiro: ENDEREÇO do ponteiro...
	// Valor apontado pelo ponteiro: O que tem DENTRO do ponteiro...

	// x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x

	valor = *p_valor; // A variável valor recebe o mesmo VALOR (valor apontado) que o ponteiro p_valor
	p_valor = &valor; // O ponteiro p_valor recebe o mesmo endereço que a variável valor

	// 'p_valor' indica o ENDEREÇO do ponteiro e '&' indica o ENDEREÇO de uma variável

	cout<<"\n-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-"<<endl;
	cout<<valor<<endl; // Imprime o valor da variável valor (agora, igual ao valor apontado por p_ponteiro)
	cout<<&valor<<endl; // Imprime o endereço da variável valor

	cout<<p_valor<<endl; // Imprime o ENDEREÇO do ponteiro p_valor
	cout<<*p_valor<<endl; // Imprim o VALOR APONTADO (conteúdo) do ponteiro p_valor
}

/*
	endereço na memória para p_valor quando declarei new int(2) 0x55ca6472cec0 - Ponteiro para 2 inteiros
	endereço na memória para p_valor quando declarei new int 0x557f1f516ec0 - Ponteiro para 1 inteiro
*/
