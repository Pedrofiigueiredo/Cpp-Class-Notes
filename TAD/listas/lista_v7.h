#include <iostream>
using namespace std;

// * Template só serve para implementação em vetor, porque as operações de inserir e remover (operações de encadeamento) são válidas para lidar com ponteiros etc.

template <class T> class Lista {
  private:
    const int LIMITE=5000;
  	int tamanho=10;
  	int numElementos = 0;
  	T* minhaLista ;

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
  	Lista(){
  	  minhaLista=new T[tamanho];
  	}
  	Lista(int tam){
  	  if(tam<tamanho){
  	    tam=tamanho;
  	  }
  	  if(tam>LIMITE){
  	    tam=LIMITE;
  	  }
  	  tamanho=tam;
  	  minhaLista=new T[tamanho];
  	}
  	~Lista(){ // Destrutor (~) que reseta a lista
  	  delete[] minhaLista;
  	}
  	void inseriUltimo(const T& item){
  	  if(!cheia()){
  	    minhaLista[numElementos]=item;
  	    numElementos++;
  	  }
  	  else{
  	    cout<<"ERRO - LISTA CHEIA"<<endl;
  	  }
  	}
    T removePrimeiro(){
  	  if(!vazia()){
  	    T temp;
  	    temp=minhaLista[0];
  	    fechaEspacoLista(0);
  	    numElementos--;
  	    return temp;
  	  }
  	}

  	int vazia(){
  	  return numElementos==0;
  	}

  	int cheia(){
  	  return numElementos==tamanho;
  	}
  	//novos metodos da classe lista
  	int buscaItem(const T& item){
  	  int i;
  	  for(i=0; i<numElementos; i++){
  	    if(minhaLista[i]==item){
  	      return i;
  	    }
  	  }
  	  return -1;
  	}
  	T remove(int posicao){
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
    void inseri(const T& item, int posicao){
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
