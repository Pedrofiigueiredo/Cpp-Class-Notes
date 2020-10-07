#include "lista_v7.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main() {

	typedef Lista<int> ListaInt ; // Declara um novo tipo de dado que é uma lista de inteiros
	typedef Lista<float> ListaFloat; // Lista de float
	//typedef Lista<string> ListaString;

  int i, j, pos, sum;

	ListaInt li; // Criando uma lista de inteiros
	ListaFloat lf; // Criando uma lista de float
  // Para alocar dinamicamente, posso usar ListaInt li(100), por exemplo

	j = 10;
	sum=j;

  // Add elementos nas duas listas
	cout << "Colocando elementos na lista" << endl ;
	for(i=0; i<10; i++){
	  pos=rand()%10;
	  cout<<pos<<" "<<sum<<" "<<endl;
	  li.inseri(sum, pos);
	  lf.inseri(sum*1.25,pos);
		j += 1.1 ;
		sum+=j;
	}
	cout<<endl;
	li.imprimeLista();
	lf.imprimeLista();
	cout << endl << "Lista cheia" << endl;
	cout<<"Posicao do elemento 46 na lista = "<<li.buscaItem(46)<<endl;
	cout<<"Posicao do elemento 26.25 na lista = "<<lf.buscaItem(26.25)<<endl;
	cout<< endl << "removendo elementos da lista" << endl ;
	for(int i=0; i<3; i++){
	  pos=rand()%10;
	  cout<<pos<<" ";
	  cout << li.remove(pos) << ' '<<endl ;
	}
	li.imprimeLista();
	pos=lf.buscaItem(26.25);
	lf.remove(pos);
	pos=lf.buscaItem(93.75);
	lf.remove(pos);
	pos=lf.buscaItem(75.);
	lf.remove(pos);
	lf.imprimeLista();
	getchar();
	return 0;
}






/*
int main() {
  typedef Lista<float> ListaFloat ;
	typedef Lista<int> ListaInt ;

	ListaFloat lf(5) ;
	float f = 1.1 ;
	cout << "Colocando elementos na lista" << endl ;
	for(int i=0; i<5; i++){
	  lf.inseriUltimo(f);
		cout << f << ' ' ;
		f += 1.1 ;
	}
	cout << endl << "Lista cheia" << endl
	<< endl << "removendo elementos da lista" << endl ;
	for(int i=0; i<5; i++){
	  cout << lf.removePrimeiro() << ' ' ;
	}
	cout << endl << "Lista Vazia" << endl ;
	cout << endl ;

	ListaInt li ;
	int j = 1.1 ;
		cout << "Colocando elementos na lista" << endl ;
	for(int i=0; i<5; i++){
	  li.inseriUltimo(j);
		cout << j << ' ' ;
		j += 1.1 ;
	}
	cout << endl << "Lista cheia" << endl
	<< endl << "removendo elementos da lista" << endl ;
	for(int i=0; i<5; i++){
	  cout << li.removePrimeiro() << ' ' ;
	}
	cout << endl << "Lista Vazia" << endl ;
	cout << endl ;
}
*/
