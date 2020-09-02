/*
  Esse arquivo tem conceitos, não é executável

  Conceitos:
    -> Encapsulamento
    * Herança
    * Polimorfismo
    * Abstração
*/

// Encapsulamento (Public, Private, Protected)
class Pessoa {
  // Public é o padrão
  public:
    String nome;
    int dia, mes, ano;
    String local_de_nascimento;

  // Se eu não coloco nenhum limitador, ele entende e trata como Public
  String nome;
  int dia, mes, ano;
  String local_de_nascimento;

    /*
      aluno.nome = "Maça" seria válido
      Qualquer alteração feita aqui é aceita pela classe.
    */
}


// Aqui eu dou acesso às FUNÇÔES ao usuário, não às variáveis
class Pessoa {
  private:
    String nome;
    int dia, mes, ano; // Data de Nascimento
    String local_de_nascimento;

  /*
    Essas funções só permitem dados válidos
    Então se o usuário tentar definir um aluno.nome = "Maça",
    não será possível (dá erro de COMPILAÇÃO).

    Para usar a classe:
    aluno.define_nome = "Pedro"
  */
  public:
    void define_nome (String n) {
      // Testar se n é um nome válido, se for, nome = n
    };
    void define_dia (int d) {
      // Testa se o dia é válido, se for dia = d
    }
};

// Private -> só um objeto da classe pessoa pode chamar
// Protected -> uma herança também pode chamar
