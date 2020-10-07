#include <iostream>
#include <fstream>
#include "handleList2.h"
using namespace std;

int main() {
  Lista LST;

  string line, code; // line para cada linha do arquivo, code para o 1o elemento (codigo da empresa)
  ifstream dadosVoo("dataVoos.txt");
  if (dadosVoo.is_open()) {
    while (getline(dadosVoo, line)) {
      code = line.substr(0, 2); // 0 e o ponto inicial e 2 o final, ja que o código tem 2 caracteres
      LST.inserir(code); // Metodo inserir add na lista (um codigo entra somente 1 vez)
    }
    cout<< "******** INFORMAÇÕES DE VOOS ***********" <<endl;
    LST.imprime(); // Metodo que imprime todas as informacoes

    dadosVoo.close();
  } else cout << "Erro: Nao foi possível abrir o arquivo. Verifique o nome e o diretorio.";

  return 0;
}
