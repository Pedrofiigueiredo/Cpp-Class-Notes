/* -- arquivo de texto, não é executável
  ENCADEAMENTO SIMPLES -> Uso de memória da máquina

  vetor -> superdimensionado (aloca memória que não será usada)
        -> subdimensionado (é necessáiro mais memória do que foi alocado)

*/

// Classe nó
class no {
  int valor;
  no *proximo; // Ponteiro para um bloco de memória chamado no [nó]
  // Lembrando que enquanto eu não inicializar o ponteiro (new) ele não aponta para nada

  /*
    Tratando dos espaços que essa classe ocupa na memória...
    OBJETO DO TIPO NÓ:
    * Cria um campos de dados para 'valor'
    * E um campo de encadeamento para o ponteiro 'proximo'
  */
}

int main() {
  // Criação de uma instância da classe no
  no meu_no;
  meu_no.valor = 10;
  meu_no.proximo = NULL; // Ponteiro NULO em C++

  cout<< meu_no.valor<<endl; // 10
  cout<< meu_no.proximo<<endl; // NULL


  /*
    OBJETO DO TIPO NÓ
     __________________________________________
    | campo de dados |  campo de encadeamento  |
    | int valor (10) |   no *proximo (NULL)    |
    |________________|_________________________|
  */


  // Criar duas instâncias da classe no
  no meu_no1, meu_no2; // Aqui foram criadas duas INSTÂNCIAS da classe no
  meu_no1.valor = 10;
  meu_no2.valor = 5;
  meu_no2.proximo = NULL;
  meu_no1.proximo = &meu_no2; // Aponta para o endereço (bloco) de meu_no2
  // Lembrando que & indica para o ENDEREÇO de uma VARIÁVEL

  // Em termos de desenho...
  /* meu_no1 __________________________________ BLOCO é um ESPAÇO (o tamanho de um inteiro + o tamanho de um ponteiro)
    |                |                         |
    |       10       |   Aponta para meu_no2   |
    |________________|_________________________|
  */

  /* meu_no2 _____________________________
    |                |                   |
    |        5       |       NULL        |
    |________________|___________________|
  */

  return 0;
}

// É possível criar uma lista encadeada simples:
class Lista_encadeada {
  private:
    no *primeiro; // Aponta para o primeiro elemento da lista
    no *ultimo; // Aponta para o último elemento da lista
    int num_elementos;

  public:
    void imprime() {
      no *temp;
      temp = primeiro;
      // "É melhor usar while para trabalhar com encadeamento"
      while (temp != NULL) {
        cout<< temp -> valor<<endl;
        temp = temp -> proximo;
      }
    }
}
