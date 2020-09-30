/*
	-- Lista v2 --
	Inserir em qualquer posição

	* Continua com alocação estática (tamanho fixo)
*/

#include<iostream>
using namespace std;

class Lista{
	private:
		int minhaLista[100];
		int tamanhoLista=0; // Número de elementos na lista
		int tamanhoMaximo=100; // Máximo de elementos possíveis

		// Assinatura do metodo - tipo de retorno, nome do metodo e parametros com seus tipos
		void abreEspacoLista(int posicao);
		void fechaEspacoLista(int posicao);

	public:
		Lista(){ // Construtor da classe
		}

		// * Sobrecarga de métodos (mesmo nome, mas assinaturas diferentes)
		void inserir(int elemento); // Inserir na ultima posicao da lista
		void inserir(int elemento, int posicao); // Inserir na posicao desejada
		void remover(int posicao);
		int buscar(int elemento);
		void imprimeLista();
		int mostraElemento(int posicao);

};

//
void Lista::abreEspacoLista(int posicao) { // "Esse método é da classe lista"
	for(int i = tamanhoLista; i >= posicao; i--)
		minhaLista[i] = minhaLista[i-1];
}

//
void Lista::fechaEspacoLista(int posicao) {
	for(int i=posicao; i<tamanhoLista; i++)
		minhaLista[i]=minhaLista[i+1];
}

// Sempre no final
void Lista::inserir(int elemento) {
	if(tamanhoLista<tamanhoMaximo){
		minhaLista[tamanhoLista]=elemento;
		tamanhoLista++;
	}
}

// Inserir por posição
void Lista::inserir(int elemento, int posicao){
	if((tamanhoLista < tamanhoMaximo) && (posicao <= tamanhoLista)){
		abreEspacoLista(posicao); // Copia todos os elementos uma posição para frente
		minhaLista[posicao] = elemento;
		tamanhoLista++;
	}
}

void Lista::remover(int posicao){ // Assumindo que nao existem valores negativos na lista
	if(posicao<tamanhoLista){
		fechaEspacoLista(posicao); // Copia todos os elementos uma posição para trás
		tamanhoLista--;
	}
	else{
		cout<<"Posicao nao existe na lista"<<endl;
	}
}

int Lista::buscar(int elemento){ // Buscar um elemento na lista e retorna a posicao da lista em que o elemento esta
	for(int i=0; i<tamanhoLista; i++){
		if(minhaLista[i]==elemento){
			return i;
		}
	}
	cout<<"Elemento nao esta na lista"<<endl;
	return -1;
}

void Lista::imprimeLista(){
	cout<<"******** LISTA ***********"<<endl;
	for(int i = 0 ; i<tamanhoLista; i++){
		cout<<minhaLista[i]<<endl;
	}
}

int Lista::mostraElemento(int posicao){
	if(posicao<tamanhoLista){
		cout<<minhaLista[posicao]<<endl;
	}
	else{
		cout<<"Posicao nao existe na lista"<<endl;
	}
}

/*
	Implementação dos métodos fora da classe
	para facilitar a orgaqnização do código
	(mais fácil de ver o que é a classe)
*/
