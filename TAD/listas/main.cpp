// Arquivo principal para os testes de listas

#include "lista_v5.h"

using namespace std;

int main(){

	//Lista LST(100);
	Lista LST;

	int lst[]={13, 27, 54, 17, 29, 46, 61, 34};

	for(int i=0; i<8; i++){
		LST.inserir(lst[i]);
		//LST.inserir(lst[i], i);
	}

	cout<<"Posicao do 29: "<<LST.buscar(29)<<endl;

	cout<<"Posicao do 61: "<<LST.buscar(61)<<endl;

	LST.imprimeLista();

	LST.remover(LST.buscar(17));

	cout<<"Posicao do 46: "<<LST.buscar(46)<<endl;
	cout<<"Posicao do 51: "<<LST.buscar(51)<<endl;

	LST.imprimeLista();

	//Para teste com posicao de inserir v3 e v5.

	//LST.inserir(51, 4);

	//LST.imprimeLista();

    return 0;


};
