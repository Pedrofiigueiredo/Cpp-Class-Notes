/*
	-- Lista v4 --
	Lista com encadeamento simples
*/

#include<iostream>

using namespace std;

class no{
	public:
		int valor; // Variável que guarda um valor da lista
		no *proximo; // Ponteiro que aponta para o segundo (próximo) elemento do bloco
		// ! proximo "tem" um int valor e um no *proximo

		no(){ // Construtor da classe nó
			// Aloca memória
		}
};

class Lista{
	private:
	no *listaPrimeiro; // listaPrimeiro tem um int valor e um no *proximo
	no *listaUltimo;
	int tamanhoLista=0;

	public:
	Lista(){ // Construtor da classe
	}

	void inserir(int elemento) { // Iserir um novo elemento na última posição
		no *temp;
		temp = new no; // Cria um bloco na memória (valor, próximo)
		// Inicializando os elementos
		temp -> proximo = NULL;
		temp -> valor = elemento; // Valor do elemento = valor que eu passei como parâmetro
		if(tamanhoLista==0) { // Se a lista está vazia, 1o = ultimo
			listaPrimeiro = temp; // Lembrando que temp é um bloco (valor, próximo)
			listaUltimo = temp;
		}
		else { // Para exemplificar, tratei como a 2a inserção
			// O próximo do 1o bloco aponta para o bloco temp, que tem o valor que eu passei
      listaUltimo -> proximo = temp;
      listaUltimo= temp; // Agora o novo listaUltimo é o bloco do elemento que eu acabei de inserir
		}
		tamanhoLista++;
	}

	void remover(int posicao){ // Assumindo que nao existem valores negativos na lista
		no *temp; // Bloco (valor, proximo)...
		temp = listaPrimeiro; // Começa pelo começo...
		// Lembrando que listaPrimeiro também é um bloco (valor, proximo)
		// que já foi definido ao inserir o primeiro elemento

		if (posicao < tamanhoLista) { // Verifica se a posição é válida
			for (int i = 0; i < posicao - 1 ; i++) { // Até -1 porque o i começa = 0...
				temp = temp -> proximo;
				// Aqui eu só estou percorrendo a lista encadeada até chegar
				// na posição que eu quero, porque não há um índice direto
				// como nas outras listas. Isso não é um vetor.
			} // Saindo desse bloco de código, temp é o bloco que está a minha posição
			temp -> proximo = temp -> proximo -> proximo; // temp pula um bloco e aponta para o próximo
			tamanhoLista--;
		}
		else{
			cout<<"Posicao nao existe na lista"<<endl;
		}
	}

	int buscar(int elemento){ // Buscar um elemento na lista e retorna a posicao da lista em que o elemento esta
		no *temp; // Bloco (valor, proximo)
		temp = listaPrimeiro; // Começa no primeiro
		int i = 0; // Variável para a posição em que o elemento está na lista

		while (temp != NULL) { // Se eu chegar em NULL e não tiver retornado ainda, o elemento não existe na lista
			if(temp -> valor == elemento){
				return i;
			}
			else{
				temp = temp -> proximo; // Avança para o próximo bloco
				i++; // Índice para a próxima posição (que vai ser retornada caso o elemento esteja aqui)

				// O índice i não está diretamente ligado a lista, é só um
				// contador que acompanha a busca e é retornado quando encontrado
			}
		}
		cout<<"Elemento nao esta na lista"<<endl;
		return -1;
	}

	void imprimeLista(){
		no *temp;
		temp=listaPrimeiro;

		cout<< "******** LISTA ***********" <<endl;
		for(int i = 0 ; i<tamanhoLista; i++){
			cout<< temp -> valor <<endl;
			temp = temp -> proximo; // Endereço do próximo bloco (em ordem, porque eu vou atualizando temp)
		}
	}

};
