// Exemplo de classe

#include <iostream>
using namespace std;

int main () {
  // Definição da classe
  class pontoCartesiano {
    private: // Definindo visibilidade
      double x, y; // Dados da classe pontoCartesiano

    public:
      // Construtor define o objeto e inicaliza os campos de dados (mesmo nome da classe)
      pontoCartesiano () {
        x = y = 0.0;
      }
      // Método para imprimir os valores do ponto
      void imprimePonto () {
        cout<< "x = "<<x<<", y = "<<y<<endl;
      }
      // Método para alterar o valor de x
      void alteraX(double X) {
        if (X < 0) {
          cout<<"ERRO: O valor de X deve ser positivo"<<endl;
          exit(EXIT_FAILURE);
        }
        x = X;
      }
  };

  pt1.imprimePonto(); // 0, 0
  pt1.alteraX(5.4);
  pt1.imprimePonto(); // 5.4, 0
  // pt1.y=7.2; // Não compila (y é privado, não existe acesso direto)

  return 0
}
