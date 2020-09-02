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

/*
  - Herança -
  Definição da classe Aluno que herda propriedades e métodos da classe pessoa
  Toda vez que eu criar um aluno, eu estou também criando uma pessoa
*/

class aluno:public pessoa {
  private:
    string curso;
    int semestre, ano; // Semestre e ano de admissão
    int semestre_atual; // Semestre atual do curso

  public:
    // Método que define o curso
    void define_curso (string c) {
      curso = c;
    }

    // Método que define o semestre de admissão
    void define_entrada (int s, int a) {
      if (s == 1 || s == 2) {
        semestre = s;
      }

      if (a < 2021 && a > 2014) {
        ano = a;
      }
    }

    // Método que define o semestre atual do aluno
    void define_semestre (int s) {
      // Verificação com base no total do curso
      if( s > 0 && s < 11){
        semestre_atual = s;
      }
    }

    void imprime () {
      pessoa::imprime(); // :: Indica que o método está na classe pessoa
      cout<<"Curso: "<<curso<<endl;
			cout<<"Semestre atual: "<<semestre_atual<<endl;
    }
};

int main () {
  aluno lista[3]; // Define OBJETO do tipo ALUNO - uma 'lista' com 3 posições
  aluno *p; // Ponteiro p para aluno

  lista[0].define_nome("Barack"); // Esse métodos são buscados da classe herdade - pessoa
  lista[0].define_sobrenome("Obama");
  lista[0].define_local("Honolulu, Hawai");
  // --
	lista[0].define_curso("Direito"); // Métodos da classe aluno
	lista[0].define_entrada(2,2018);
	lista[0].define_semestre(5);


  lista[1].define_nome("Angela");
	lista[1].define_sobrenome("Merckel");
	lista[1].define_nasc(17, 7, 1954);
	lista[1].define_local("Hamburgo");
  // --
	lista[1].define_curso("Fisica"); // Métodos da classe aluno
	lista[1].define_entrada(1,2017);
	lista[1].define_semestre(8);

  for (int i = 0; i < 2; i++)
    lista[i].imprime();

  p = new aluno;

  p -> define_nome("Philippe");
  p -> define_sobrenome("Coutinho");
  p -> define_nasc(12, 6, 1992);
  p-> define_local("Rio de Janeiro, RJ");
  // --
  p->define_curso("Educacao Fisica");
  p->define_entrada(1, 2020);
  p->define_semestre(2);

  p -> imprime();
}
