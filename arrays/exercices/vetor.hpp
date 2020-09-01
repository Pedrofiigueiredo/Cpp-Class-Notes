#include <iostream>
#include <stdlib.h>
using namespace std;

int rand(void);

// (1)
int *alocaVetor (int tamanho) {
  int *vetor; // Cria um ponteiro para inteiros
  vetor = new int[tamanho]; // Aloca [tamanho] espaços
  return vetor; // Endereço do ponteiro vector
}

// (2)
int *criaVetor(int *vetor, int tamanho) {
  // Inicializa o vetor com valores aleatórios de 0 a 100
  for(int i = 0; i < tamanho; i++) {
    vetor[i] = rand() % 100 + 1;
  }

  // Imprime o vetor
  for(int i = 0; i < tamanho; i++)
    cout<< vetor[i]<<endl;
  cout<<endl;

  return vetor;
}

// (3)
int verificaVetor (int entrada, int *vetor, int tamanho) {
  int count = 0;
  for (int i = 0; i < tamanho; i++) {
    if (vetor[i] > entrada)
      count = count + 1;
    }

  return count;
}

// (4)
void verificaSoma (int *vetor, int tamanho) {
  int entrada, soma, i = 0, count = 0;
  cout<< "Número entre 50 e 200: ";
  cin>> entrada;
  while (i < 5) {
    for (int j = i+1; j < 5; j++) {
      soma = vetor[i] + vetor[j];
      if (soma == entrada) {
        count++;
        cout<< "("<<vetor[i]<<", "<<vetor[j]<<")"<<endl;
      }
    }
    i++;
  }
  if (count == 0)
    cout<< "(-1, -1)";
}
