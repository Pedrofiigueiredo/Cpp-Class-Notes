// (02/09/20)

#include <iostream>
#include <string>

using namespace std;

class pessoa {
  private: // Visibilidade dos dados da classe
    string nome;
    string sobrenome;
    int dia_nasc, mes_nasc, ano_nasc;
    string cidade_nasc;

  public:
    // Construtor: é um método que possui o MESMO NOME DA CLASSE e pode - ou não - possuir parâmetros
    pessoa() {
      /*
        Ele aloca - reserva espaço de memória - para
        todas os valores que eu defini no private
      */
    }

    // Método para definir o nome da pessoa
    void define_nome (string n) {
      nome = n;
    }

    // Método para definir o sobrenome da pessoa
    void define_sobrenome (string s) {
      sobrenome = s;
    }

    // Método para definir a data de nascimento
    void define_nasc (int d, int m, int a) {
      // Verifica ano de nascimento
      if (a > 1910 && a < 2021) {
        ano_nasc = a;
      }
      // Verifica se o mês é válido
      if (m > 0 && m < 13) {
        mes_nasc = m;
      }

      // Verifica se o dia do mês é válido
      if (m == 2) { // Mês de fevereiro (28 dias)
        if (d > 0 && d < 29) {
          dia_nasc = d;
        }
      }

      // Meses com 31 dias
      else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d > 0 && d < 32) {
          dia_nasc = d;
        }
      }

      // Demais meses - com 30 dias
      else {
        if ( d > 0 && d < 31) {
          dia_nasc=d;
        }
      }
    }

    void define_local (string l) {
      cidade_nasc = l;
    }

    void imprime(){
      cout<<"************************************************"<<endl;
      cout<<"Nome: "<<nome<<" "<<sobrenome<<endl;
      cout<<"Data Nasc.: "<<dia_nasc<<"/"<<mes_nasc<<"/"<<ano_nasc<<endl;
      cout<<"Local Nasc.: "<<cidade_nasc<<endl;
    }
};

int main () {
  pessoa p1, p2; // Declaração das pessoas p1 e p2 usando a classe pessoa
  pessoa *p;

  p1.define_nome("Gisele"); // Chama o método da classe
  p1.define_sobrenome("Bundchen");
  p1.define_nasc(20, 7, 1980);
  p1.define_local("Horizontina, RS");

  p1.imprime();

  p2.define_nome("Barack");
	p2.define_sobrenome("Obama");
	p2.define_nasc(4, 8, 1961);
	p2.define_local("Honolulu, Hawai");

	p2.imprime();

  // Criando uma pessoa, com alocação dinâmica
  p = new pessoa; // p é um ponteiro para aluno | aloca um espaço de memória para um novo aluno

  // Inicializa p
  p->define_nome("Philippe");
  p->define_sobrenome("Coutinho");
  p->define_nasc(12, 6, 1992);
  p->define_local("Rio de Janeiro, RJ");

  p->imprime();
}
