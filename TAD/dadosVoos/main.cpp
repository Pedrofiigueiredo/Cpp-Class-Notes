#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string line;
  string code;
  ifstream dadosVoo("testeVoos.txt");
  if (dadosVoo.is_open()) {
    while (getline(dadosVoo, line)) {
      cout<< line <<endl;
      code = line.substr (0, 3); ;
      cout << code <<endl;
    }

    // Quantidade total de empresas aéreas

    // Número de voos de cada empresas

    // Número total de testeVoos

    // Empresa com maior número de testeVoos

    dadosVoo.close();
  } else cout << "Erro: Não foi possível abrir o arquivo";

  return 0;
}
