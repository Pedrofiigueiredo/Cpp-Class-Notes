#include <iostream>
using namespace std;

int tamanhoLista = 10;
int tamanhoMaximo = 10;

int remover(int lst[], int pos) {

  for(int i=pos; i<tamanhoLista; i++) {
    lst[i]=lst[i+1];
  }
  tamanhoLista--;
  return lst[pos];
}

void inserir(int lst[], int valor, int pos){
	if(pos <= tamanhoLista){

    for(int i = tamanhoLista; i >= pos; i--) {
  		lst[i] = lst[i-1];
    }

		lst[pos] = valor;
  } else lst[tamanhoLista+1] = valor;
  tamanhoLista++;
}

int main() {
  int lista[] = {0,1,2,3,4,5,6,7,8,9};
  int j = 10;
  int valor;
  while (j>=0) {
    for (int i = 0; i<3; i++) {
      valor = remover(lista, 0);
      inserir(lista, valor, j-i);
    }
    cout<<remover(lista,0)<<endl;
    j--;
  }
}
