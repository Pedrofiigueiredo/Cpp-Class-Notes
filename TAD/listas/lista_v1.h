/*
	-- Lista v1 --
	Lista simples, não dinamica - com posição fixa de 100 elementos
 	* Adicionar elementos somente depois de todos os outros
	* Remover elemento deixa -1 na lista (não funciona com negativos)
*/

#include <iostream>
#include <string>

using namespace std;

class Lista {
  private:
    int lista[100];
    int tamanhoLista = 0;
    int tamanhoMaximo = 100;

  public:
    // Construtor | Inicializa as variáveis (do private) e aloca memória para elas
    Lista() { // Complexidade constante O(1)
    }

    // Adiciona um elemento se houver espaço
    void insert (int elemento) { // Complexidade O(1)
      if (tamanhoLista < tamanhoMaximo) {
        lista[tamanhoLista] = elemento;
        tamanhoLista ++;
      } else {
        cout<< "A lista não tem mais espaços livres";
      }
    }

    // Remove um elemento da posição informada (assumindo que não há valores negativos)
    void remove (int posicao) { // Complexidade constante O(1)
      if (posicao < tamanhoLista) {
        lista[posicao] = -1;
        tamanhoLista--;
      }
    }

    // Busca por um elemento específico
    int busca (int elemento) { // Complexidade O(n)
      int i = 0;
      while (i < tamanhoLista) {
        if (lista[i] == elemento) {
          return i;
        } else if (lista[i] != -1) {
          i++;
        }
      }
      return 0;
    }

    // Imprime todos os elementos da lista
    void imprimeLista () { // Complexidade constante O(n)
      int i=0;
      int j=0;

      cout<<"LISTA"<<endl;
      while (i < tamanhoLista) {
        if (lista[j] != -1) {
          cout<<lista[j]<<", ";
          i++;
          j++;
        } else {
          j++;
        }
      }
    }
};
