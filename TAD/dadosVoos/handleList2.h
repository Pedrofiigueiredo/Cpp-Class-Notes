#include<iostream>
using namespace std;

class no {
  public:
    string valor; // Nome da empresa aerea
    int qtd = 0; // Quantidade de voos no dia
    no *proximo; // Aponta para o proximo elemento da lista

    no() {
      // Construtor
    }
};

class Lista {
  private:
    no *listaPrimeiro;
    no *listaUltimo;
    no *maisVoos; // Nome e qtd de voos da empresa com mais voos no dia
    int numeroVoos = 0; // Nemero total
    int empresasAereas = 0; // Empresas distintas

  public:
    Lista() {
    } // Construtor
    int busca(string e); // O(n) Verifica se uma empresa ja foi add na lista
    void inserir(string e); // O(1) Insere uma nova empresa (se ja não foi add)
    void maiorVoos(); // O(n) Verifica qual empresa teve mais voos
    void imprime(); // O(n)
};

int Lista::busca(string e) {
	no *temp;
	temp = listaPrimeiro;
	while (temp != NULL) {
		if (temp->valor == e) return 1;
		else temp = temp->proximo;
	}
  return -1;
}

void Lista::inserir(string e) {
  no *temp; // Declara instancia da classe
  temp = new no; // Aloca memoria

  // Inicializando variaveis do no
  temp->valor = e;
  temp->qtd += 1;
  temp->proximo = NULL;

  if (numeroVoos == 0) { // Inserção do 1o elemento
    listaPrimeiro = temp; // 1o e ultimo são a mesma coisa se length = 1
    listaUltimo = temp;
    empresasAereas++;
  }
  else {
    if (busca(e) == -1) { // Se ainda não estiver na lista, add
      listaUltimo -> proximo = temp;
      listaUltimo = temp;
      empresasAereas++;
    } else listaUltimo->qtd += 1; // Empresa não aparece 2 vezes na lista, mas a qtd de voos e atualizada
  }
  numeroVoos++;
}

void Lista::maiorVoos() { // O(n)
  no *temp;
  temp = listaPrimeiro;
  maisVoos = listaPrimeiro;

  while (temp != NULL) {
    if (temp->qtd > maisVoos->qtd) {
      maisVoos = temp;
    }
    temp = temp->proximo;
  }
}

void Lista::imprime() { // O(n)
  no *temp;
  temp = listaPrimeiro;
  cout<< "Quantidade total de empresas aereas = "<< empresasAereas<<endl;
  cout<< "Empresa Aerea - Num. de Voos"<<endl;
  while (temp != NULL) {
    cout<<"     ";
    cout<< temp->valor;
    cout<<"              ";
    cout<< temp->qtd<<endl;

    temp = temp->proximo;
  }
  cout<< "Nemero total de voos: "<< numeroVoos<<endl;
  maiorVoos();
  cout<< "Empresa com maior numero de voos: "<< maisVoos->valor<< " N-mero de voos: "<< maisVoos->qtd;
}
