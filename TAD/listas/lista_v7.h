/*
  -- Lista v7 --
  Nas outras listas, o tipo era definido no arquivo,
  se eu quisesse diferentes tipos, eu precisaria ter
  um arquivo para cada tipo.

  * Template
  template <class T> ...
*/

#include <iostream>
using namespace std;

// * Template só serve para implementação em vetor, porque as operações de inserir e remover (operações de encadeamento) são válidas para lidar com ponteiros etc.

template <class T> class Lista {
  private:
    const int LIMITE=5000;
  	int tamanho=10;
  	int numElementos = 0;
  	T* minhaLista; // minhaLista é um ponteiro para a classe T

  	void fechaEspacoLista(int posicao) {
  	  int i;
  	  for(i=posicao+1; i<numElementos; i++){
  	    minhaLista[i-1]=minhaLista[i];
  	  }
  	}

  	void abreEspacoLista(int posicao){
  	  int i;
  	  for(i=numElementos-1; i>=posicao; i--){
  	    minhaLista[i+1]=minhaLista[i];
  	  }
  	}

  public:
    // Posso passar tamanho de lista ou não...
  	Lista() { // Se eu não passar nenhum tamanho no arquivo principal
  	  minhaLista = new T[tamanho]; // Cria a lista com 10 elementos (definido em private)
  	}

  	Lista(int tam) { // Se eu passar parâmetro
  	  if(tam<tamanho){
  	    tam=tamanho;
  	  }
  	  if(tam>LIMITE){
  	    tam=LIMITE;
  	  }
  	  tamanho = tam;
  	  minhaLista = new T[tamanho];
  	}

  	~Lista(){ // Destrutor (~) que reseta a lista e libera a memória
  	  delete[] minhaLista;
  	}

    /*
      Lembrando que eu posso ter quantos construtores eu quiser,
      só não podem ter a mesma assinatura. Mas se os contrutores,
      tem parâmetros diferentes...
    */

  	void inseriUltimo(const T& item) { // Parâmetro do tipo T
  	  if(!cheia()) {
  	    minhaLista[numElementos] = item;
  	    numElementos++;
  	  }
  	  else{
  	    cout<<"ERRO - LISTA CHEIA"<<endl;
  	  }
  	}

    T removePrimeiro() { // T é o tipo do return da função
  	  if(!vazia()){
  	    T temp;
  	    temp = minhaLista[0];
  	    fechaEspacoLista(0);
  	    numElementos--;
  	    return temp;
  	  }
  	}

  	int vazia() { // Se a lista está vazia
  	  return numElementos == 0;
  	}

  	int cheia(){ // Se a lista está cheia
  	  return numElementos == tamanho;
  	}

  	// Novos metodos da classe lista
  	int buscaItem(const T& item){
  	  int i;
  	  for(i=0; i<numElementos; i++){
  	    if(minhaLista[i]==item){
  	      return i;
  	    }
  	  }
  	  return -1;
  	}

  	T remove(int posicao) {
  	  if(!vazia()){
  	    if(posicao<numElementos){
    	    T temp;
    	    temp=minhaLista[posicao];
    	    fechaEspacoLista(posicao);
    	    numElementos--;
    	    return temp;
  	    }
  	    else{
  	      cout<<"ERRO - POSICAO NAO EXISTE NA LISTA"<<endl;
  	      return (T)NULL;
  	    }
  	  }
      else{
        return (T)NULL;
      }
  	}

    // Inserir por posição
    void inseri(const T& item, int posicao) {
      if(!cheia()){
        if(posicao>numElementos){
          posicao=numElementos;
          minhaLista[posicao]=item;
  	      numElementos++;
        }
        else{
          abreEspacoLista(posicao);
    	  minhaLista[posicao]=item;
    	  numElementos++;
        }
  	  }
  	  else{
  	    cout<<"ERRO - LISTA CHEIA"<<endl;
  	  }
    }

    void imprimeLista(){
      int i;
      cout<<"Tamanho maximo: "<<tamanho<<endl;
      for(i=0; i<numElementos; i++){
        cout<<minhaLista[i]<<" ";
      }
      cout<<endl;
    }
} ;
