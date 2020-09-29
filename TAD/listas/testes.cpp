#include <iostream>
using namespace std;

// //
// void abreEspacoLista(int posicao) {
// 	for(int i = tamanhoLista; i >= posicao; i--)
// 		minhaLista[i] = minhaLista[i-1];
// }

int main() {
  int lista[6] = {2, 3, 4, 5, 6, 7};
  int tamanhoLista = 6;
  int tamanhoMaximo = 10;

  cout<<"******** LISTA ***********"<<endl;
  for(int i = 0 ; i < tamanhoLista; i++){
    cout<<lista[i]<<endl;
  }
}
