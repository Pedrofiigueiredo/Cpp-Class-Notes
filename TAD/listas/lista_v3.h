#include<iostream>

using namespace std;

class Lista{
	private:
	int *minhaLista;
	int tamanhoLista=0;
	int tamanhoMaximo;

	void abreEspacoLista(int posicao){
		for(int i=tamanhoLista; i>=posicao; i--){
			minhaLista[i]=minhaLista[i-1];
		}
	}

	void fechaEspacoLista(int posicao){
		for(int i=posicao; i<tamanhoLista; i++){
			minhaLista[i]=minhaLista[i+1];
		}
	}

	public:
	Lista(int tamanho){//construtor da classe
		minhaLista=new int[tamanho];
		tamanhoMaximo=tamanho;
	}

	void inserir(int elemento, int posicao){ //inserir um novo elemento na lista se houver espaco
		if((tamanhoLista<tamanhoMaximo)&&(posicao<=tamanhoLista)){
			abreEspacoLista(posicao);
			minhaLista[posicao]=elemento;
			tamanhoLista++;
		}
	}

	void remover(int posicao){//assumindo que nao existem valores negativos na lista
		if(posicao<tamanhoLista){
			fechaEspacoLista(posicao);
			tamanhoLista--;
		}
		else{
			cout<<"Posicao nao existe na lista"<<endl;
		}
	}

	int buscar(int elemento){//buscar um elemento na lista e retorna a posicao da lista em que o elemento esta
		for(int i=0; i<tamanhoLista; i++){
			if(minhaLista[i]==elemento){
				return i;
			}
		}
		cout<<"Elemento nao esta na lista"<<endl;
		return -1;
	}

	void imprimeLista(){
		cout<<"******** LISTA ***********"<<endl;
		for(int i = 0 ; i<tamanhoLista; i++){
			cout<<minhaLista[i]<<endl;
		}
	}

};
