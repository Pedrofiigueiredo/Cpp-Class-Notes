/*
	-- Lista v2 --
	# Inserir em qualquer posição

	* Continua estática
*/

#include<iostream>
using namespace std;

class Lista{
	private:
		int minhaLista[100];
		int tamanhoLista=0;
		int tamanhoMaximo=100;

		// Assinatura do metodo - tipo de retorno, nome do metodo e parametros com seus tipos
		void abreEspacoLista(int posicao);
		void fechaEspacoLista(int posicao);

	public:
		Lista(){ // Construtor da classe
		}

		void inserir(int elemento); // Inserir na ultima posicao da lista
		void inserir(int elemento, int posicao); // Inserir na posicao desejada
		void remover(int posicao);
		int buscar(int elemento);
		void imprimeLista();
		int mostraElemento(int posicao);

};

//
void Lista::abreEspacoLista(int posicao) {
	for(int i = tamanhoLista; i >= posicao; i--)
		minhaLista[i] = minhaLista[i-1];
}

//
void Lista::fechaEspacoLista(int posicao) {
	for(int i=posicao; i<tamanhoLista; i++)
		minhaLista[i]=minhaLista[i+1];
}

void Lista::inserir(int elemento) {
	if(tamanhoLista<tamanhoMaximo){
		minhaLista[tamanhoLista]=elemento;
		tamanhoLista++;
	}
}

// Inserir um novo elemento na lista se houver espaco
void Lista::inserir(int elemento, int posicao){
	if((tamanhoLista < tamanhoMaximo) && (posicao <= tamanhoLista)){
		abreEspacoLista(posicao);
		minhaLista[posicao] = elemento;
		tamanhoLista++;
	}
}

void Lista::remover(int posicao){//assumindo que nao existem valores negativos na lista
	if(posicao<tamanhoLista){
		fechaEspacoLista(posicao);
		tamanhoLista--;
	}
	else{
		cout<<"Posicao nao existe na lista"<<endl;
	}
}

int Lista::buscar(int elemento){//buscar um elemento na lista e retorna a posicao da lista em que o elemento esta
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
