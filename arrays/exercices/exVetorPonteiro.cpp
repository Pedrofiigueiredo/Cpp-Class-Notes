/*
  (2)
  Crie uma função que receba um vetor de
  inteiros como ponteiro e o tamanho do
  vetor e que inicialize o vetor com valores
  aleatórios entre 0 e 100.
  Use para isto a  rand do C++ da biblioteca stdlib.

  (3)
  Leia um valor inteiro entre 0 e 100 do
  teclado e escreva uma função que retorne
  a quantidade de valores no vetor que são
  maiores que o valor entrado pelo teclado.
*/

#include <iostream>
#include "vetor.hpp" // Importar depois de todas as libs (usadas NESSE arquivo)
using namespace std;

int main () {
  int tamanho, entrada, count;
  int *vetor;

  // (1)
  cout<< "// Exercício 1"<<endl;
  cout<< "Digite o tamanho do vetor desejado: ";
  cin>> tamanho;
  vetor = alocaVetor(tamanho);
  cout<<vetor<<endl<<endl;

  // (2)
  cout<< "// Exercício 2"<<endl;
  criaVetor(vetor, tamanho);
  cout<< "Vetor inicializado"<<endl<<endl;

  // (3)
  cout<< "// Exercício 3"<<endl;
  cout<< "Número entre 0 e 100: ";
  cin>> entrada;
  count = verificaVetor(entrada, vetor, tamanho);
  cout<< count<<endl<<endl;

  // (4)
  cout<< "// Exercício 4"<<endl;
  verificaSoma(vetor, tamanho);

  return 0;
}
