#include<iostream>

using namespace std;

class no{
	public:
	int valor;
	no *proximo;

	no(){
	}
};

class Lista{
	private:
	no *listaPrimeiro;
	no *listaUltimo;
	int tamanhoLista;

	public:
	Lista(){//construtor da classe
		listaPrimeiro=NULL;
		listaUltimo=NULL;
		tamanhoLista=0;
	}

	void inserir(int elemento, int posicao){ //inserir um novo elemento na lista se houver espaco
		no *temp, *temp2;
		temp = new no;
		temp->proximo=NULL;
		temp->valor=elemento;
		if(posicao>tamanhoLista){
			cout<<"Posicao nao existe na lista."<<endl;
		}
		else{
			if(posicao==0){
				temp->proximo=listaPrimeiro;
				listaPrimeiro=temp;
				listaUltimo=temp;
			}
			else if(posicao!=tamanhoLista){
				temp2=listaPrimeiro;
				for(int i=0; i<posicao-1; i++){
					temp2=temp2->proximo;
				}
				temp->proximo=temp2->proximo;
				temp2->proximo=temp;
			}
			else{
				listaUltimo->proximo=temp;
            	listaUltimo=temp;
			}
			tamanhoLista++;
		}
	}

	void remover(int posicao){//assumindo que nao existem valores negativos na lista
		no *temp;
		temp=listaPrimeiro;
		if(posicao<tamanhoLista){
			for(int i = 0; i<posicao-1 ; i++){
				temp=temp->proximo;
			}
			temp->proximo=temp->proximo->proximo;
			tamanhoLista--;
		}
		else{
			cout<<"Posicao nao existe na lista"<<endl;
		}
	}

	int buscar(int elemento){//buscar um elemento na lista e retorna a posicao da lista em que o elemento esta
		no *temp;
		temp=listaPrimeiro;
		int i=0;
		while(temp != NULL){
			if(temp->valor==elemento){
				return i;
			}
			else{
				temp=temp->proximo;
				i++;
			}
		}
		cout<<"Elemento nao esta na lista"<<endl;
		return -1;
	}

	void imprimeLista(){
		no *temp;
		temp=listaPrimeiro;
		cout<<"******** LISTA ***********"<<endl;
		for(int i = 0 ; i<tamanhoLista; i++){
			cout<<temp->valor<<endl;
			temp=temp->proximo;
		}
	}

};
