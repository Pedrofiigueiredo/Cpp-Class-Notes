/*
	-- Lista v3 --
	Alocação dinâmica da lista, com tamanho pré-definido pelo usuário
*/

#include<iostream>

using namespace std;

class Lista{
	private:
	int *minhaLista; // Ponteiro que aponta para o endereço de memória que guarda uma lista de N posições
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
	Lista(int tamanho){ // Construtor da classe faz a alocação dinâmica da lista
		minhaLista = new int[tamanho];
		/*
			Reserva um espaço para "tamanho" inteiros e retorna o
			endereço desse espaço de memória para o ponteiro minha lista.
			Minha lista não valor ainda.
		*/
		tamanhoMaximo = tamanho;

		/*
			Agora o construtor está esperando um parâmetro, então
			no arquivo main eu preciso criar a instância da classe
			passando esse parâmetro, que é o tamanho da minha lista.

			Lista minhaLista(20);
		*/
	}

	/*
		Outro jeito de fazer isso é criar outro método e deixar o construtor vazio.
		Isso faz com que a declaração da instância continue a mesma e o tamanho da
		lista é recebido durante a execução.

		void criaLista (int tamanho) {
			tamanhoMaximo = tamanho
			minhaLista = new int[tamanho]
		}
	}
	*/

	// Todos os demais métodos são EXATAMENTE iguais

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
