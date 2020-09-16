#include <iostream>
using namespace std;

// Classe Nó
class no {
  public:
    int valor;
    no *proximo;
    no() { // Construtor
    }
};


class Lista {
  private:
    // Instâncias da classe no
    no *listaPrimeiro; // PRIMEIRO elemento da lista
    no *listaUltimo; // ÚLTIMO elemento da lista
    int tamanhoLista = 0;

  public:
    Lista() { //Construtor
    }

    // Inserir novo elemento na lista se houver espaço
    void insert(int elemento) {
      no *temp; // Instância da classe no
      temp = new no; // Aloca espaço de memória dinamicamente
      /*
        Nota-se que no é um bloco que contém valor (int) e o ponteiro proximo
      */
      temp -> proximo = NULL; // Arrow operator (->), usado para ponteiros
      temp -> valor = elemento;
      /*
        valor e proximo estão definidos na classe no
        A instância temp da classe no contém essas duas variáveis
        Para acessá-las, usa-se o ->
        Logo:
          temp -> proximo = NULL define que o ponteiro proximo, que é 'filho' de temp é igual a NULL e
          temp -> valor = elemento define que a variavel valor, que também é 'filha' de temp é igual a elemento (parâmetro da função)

        DOT (.) tem a mesma função, mas o ARROW OPERATOR (->) é usado para ponteiros
      */

      // cout<< temp<<endl; // Endereço de memória
      // cout<< temp->valor<<endl; // Elemento

      if (tamanhoLista == 0) {
        // Só tenho um elemento, então o primeiro e o último são a mesma coisa
        listaPrimeiro = temp; // Aponta para o endereço de temp
        listaUltimo = temp;
        /*
          temp é um no, que é um bloco (elemento, NULL)
          | 12 |  -|---> NULL
        */
      } else { // A partir do segundo elemento
        listaUltimo -> proximo = temp; // a variável proximo - de listaUltimo - é igual ao endereço de temp
        /*
          temp é (elemento, NULL)
          listaUltimo está aqui: (12, listaUltimo)
          e proximo está aqui: (12, listaUltimo -)--> (valor, proximo) - em que valor recebe o elemento passado na função
          Logo:
            listaUltimo -> proximo = temp cria um outro bloco com (elemento, proximo), e listaUltimo aponta para ele
        */
        listaUltimo = temp;
      }
      tamanhoLista++;
    }

    void imprimeLista() {
      no *temp;
      temp = listaPrimeiro;

      cout<< "--- Lista ---"<<endl;
      for (int i = 0; i < tamanhoLista; i++) { // Tamanho lista é definido no private da Classe
        cout<< temp -> valor<<endl;
        temp = temp -> proximo;
      }
    }
};

int main() {
  Lista lst;
  for (int i=0; i<10; i++)
    lst.insert(i);

  lst.imprimeLista();
}
