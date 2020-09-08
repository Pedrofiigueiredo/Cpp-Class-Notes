// (02/09/20)

#include <iostream>
#include <string>

using namespace std;

#include "pessoa.h"

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
