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

    void imprime() {
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

class funcionario:public pessoa {
  // Definindo a visibilidade
  private:
    int dia_admissao, mes_admissao, ano_admissao;
    float salario;
    string departamento;
    string cargo;

  public:
    // Construtor
    funcionario() {}

    void define_admissao (int d, int m, int a) {
      // Verifica ano de admissão (2000 é quando a instituição foi criada)
      if (a > 2000 && a < 2021) {
        ano_admissao = a;
      }

      // Verifica se o mês é válido
      if (m > 0 && m < 13) {
        mes_admissao = m;
      }

      // Verifica se o dia do mês é válido
      if (m == 2) { // Mês de fevereiro (28 dias)
        if (d > 0 && d < 29) {
          dia_admissao = d;
        }
      }

      // Meses com 31 dias
      else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d > 0 && d < 32) {
          dia_admissao = d;
        }
      }

      // Demais meses - com 30 dias
      else {
        if ( d > 0 && d < 31) {
          dia_admissao=d;
        }
      }
    }

    void define_salario (float s) {
      // Verificação do salário mínimo (2020)
      if (s >= 1039) {
        salario = s;
      }
    }

    void define_departamento (string d) {
      departamento = d;
    }

    void define_cargo (string c) {
      cargo = c;
    }

    void imprime () {
      pessoa::imprime(); // :: Indica que o método está na classe pessoa
      cout<<"Departamento: "<<departamento<<endl;
      cout<<"Cargo: "<<cargo<<endl;
      cout<<"Salário: "<<salario<<endl;
      cout<<"Data de Admissão: "<<dia_admissao<<"/"<<mes_admissao<<"/"<<ano_admissao<<endl;
    }
};

class professor:public funcionario {
  private:
    string titulo;
    int dia_titutacao, mes_titulacao, ano_titulacao;
    string area_pesquisa;

  public:
    // Construtor
    professor() {}

    void define_titulo (string t) {
      titulo = t;
    }

    void define_data_titulacao (int d, int m, int a) {
      // Ano de titulação
      if (a > 1950 && a < 2021) {
        ano_titulacao = a;
      }

      // Verifica se o mês é válido
      if (m > 0 && m < 13) {
        mes_titulacao = m;
      }

      // Verifica se o dia do mês é válido
      if (m == 2) { // Mês de fevereiro (28 dias)
        if (d > 0 && d < 29) {
          dia_titutacao = d;
        }
      }

      // Meses com 31 dias
      else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d > 0 && d < 32) {
          dia_titutacao = d;
        }
      } else { // Demais meses - com 30 dias
        if ( d > 0 && d < 31) {
          dia_titutacao = d;
        }
      }
    }

    void define_area_pesquisa (string p) {
      area_pesquisa = p;
    }

    void imprime () {
      funcionario::imprime(); // :: Indica que o método está na classe pessoa
      cout<<"Título: "<<titulo<<endl;
      cout<<"Área de pesquisa: "<<area_pesquisa<<endl;
      cout<<"Data da Titulação: "<<dia_titutacao<<"/"<<mes_titulacao<<"/"<<ano_titulacao<<endl;
    }
};
