#include<iostream>
#include<string>
using namespace std;

class no{
	public:
		string valor; // Variavel que guarda um valor da lista
		no *proximo; // Ponteiro que aponta para o segundo (proximo) elemento do bloco
		// ! proximo "tem" um int valor e um no *proximo

		no(){ // Construtor da classe nó
			// Aloca memória
		}
};

class Lista{
	private:
		no *listaPrimeiro; // listaPrimeiro tem um int valor e um no *proximo
		no *listaUltimo;
		int tamanhoLista = 0;
		int tamanhoAux = 1; // A primeira empresa é add fora do loop

	public:
		Lista(){ // Construtor da classe
		}

	  // Assinatura dos métodos
	  void inserir(string elemento); // O(1), sempre no final
		int busca(string elemento); // O(n)
		int buscaTodos(string elemento); // O(n)
		void imprime(); // ()
};

// Iserir um novo elemento na última posição
void Lista::inserir(string elemento) { // O(1)
  no *temp;
  temp = new no; // Cria um bloco na memória (valor, próximo)
  // Inicializando os elementos
  temp -> proximo = NULL;
  temp -> valor = elemento;
  if(tamanhoLista == 0) { // Se a lista está vazia, 1o = ultimo
    listaPrimeiro = temp;
    listaUltimo = temp;
  }
  else { // Para exemplificar, tratei como a 2a inserção
    // O próximo do 1o bloco aponta para o bloco temp, que tem o valor que eu passei
    listaUltimo -> proximo = temp;
    listaUltimo = temp; // Atualiza listaUltimo como bloco do elemento que eu acabei de inserir
  }
  tamanhoLista++;
}

int Lista::busca(string elemento) { // O(n)
	no *temp;
	temp = listaPrimeiro;
	while (temp != NULL) {
		if (temp->valor == elemento) {
			return 1;
		} else temp = temp->proximo;
	}
	return -1;
}

int Lista::buscaTodos(string elemento) { // O(n)
	no *temp;
	temp = listaPrimeiro;
	int count = 0;

	while(temp != NULL) {
		if(temp->valor == elemento) {
			count ++;
			temp = temp->proximo;
		} else temp = temp->proximo;
	}
	return count;
}

void Lista::imprime() {
	Lista aux; // Lista auxiliar para contar o número de elementos diferentes
	no *temp, *temp2;
	temp = listaPrimeiro;
	aux.inserir(temp->valor); // Insere um 1o elemento na lista aux

	// A partir do 2o eu preciso verificar se ele já existe
	while (temp != NULL) { // O(n)
		int existe = aux.busca(temp->valor);
		if (existe == -1) { // Se a função retornar que o elemento não existe
			tamanhoAux++;
			aux.inserir(temp->valor);
		} else temp = temp->proximo;
	}

	cout<< "Quantidade total de empresas aereas = "<< tamanhoAux<<endl;

	temp2 = aux.listaPrimeiro;

	int maiorNumero = 0;
	string maiorEmpresa;
	cout<< "Empresa Aerea - Num. de Voos"<<endl;
	while (temp2 != NULL) { // O(n)
		int numeroVoos = buscaTodos(temp2->valor);

		if (numeroVoos > maiorNumero) { // Verificação da empresa com mais voos no dia
			maiorNumero = numeroVoos;
			maiorEmpresa = temp2->valor; // Passa apenas o código da empresa
		}
		cout<<"     "<< temp2->valor<< "              "<<numeroVoos<<endl;
		temp2 = temp2->proximo;
	}
	cout<< "Número total de voos = "<< tamanhoLista<<endl;
	cout<< "Empresa com maior número de voos = "<< maiorEmpresa<< " N-mero de voos = "<< maiorNumero;
}
