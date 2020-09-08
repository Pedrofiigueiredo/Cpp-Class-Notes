#include "../pessoa.h"

int main(){
	pessoa p;
	aluno a;
	funcionario f;
	professor pf;

	p.define_nome("Gisele");
	p.define_sobrenome("Bundchen");
	p.define_nasc(20, 7, 1980);
	p.define_local("Horizontina, RS");

	p.imprime();

	a.define_nome("Barack");
	a.define_sobrenome("Obama");
	a.define_nasc(4, 8, 1961);
	a.define_local("Honolulu, Hawai");
	a.define_curso("Direito");
	a.define_entrada(2,2018);
	a.define_semestre(5);

	a.imprime();

	f.define_nome("Angela");
	f.define_sobrenome("Merckel");
	f.define_nasc(17, 7, 1954);
	f.define_local("Hamburgo");
	f.define_departamento("Fisica");
	f.define_cargo("Pesquisador");
	f.define_salario(15480.00);
	f.define_admissao(4, 8, 2004);

	f.imprime();

	pf.define_nome("Michael");
	pf.define_sobrenome("Jordan");
	pf.define_nasc(17, 2, 1963);
	pf.define_local("New York, NY");
	pf.define_departamento("Educacao Fisica");
	pf.define_salario(18560.00);
	pf.define_cargo("Professor");
	pf.define_admissao(2,2,2020);
	pf.define_titulo("Mestre");
	pf.define_area_pesquisa("Basketball");
	pf.define_data_titulacao(14, 10, 2019);

	pf.imprime();
}
