// (02/09/20)

#include <iostream>
using namespace std;

#include "pessoa.h"

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
