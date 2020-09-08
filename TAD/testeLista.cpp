#include <iostream>
#include "lista.h"

int main () {
  Lista lst; // Inicializa o objeto (!)
  int add[6] = {1,2,3,4,5,6};
  int r;

  cout<< "Adicionando 6 elementos"<<endl;
  for (int e = 0; e < 6; e++)
    lst.insert(add[e]);

  lst.imprimeLista ();
  cout<<endl<<endl;

  cout<< "Removendo um elemento"<<endl;
  lst.remove(3); // Posição 3, elemento 4
  lst.imprimeLista();
  cout<<endl<<endl;

  cout<< "Buscando por um elemento específico"<<endl;
  r = lst.busca(5);
  cout<<"Resultado: "<<r<<endl;
}
