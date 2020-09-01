/*
	Esse programa calcula um número perfeito
	entre 1 e Max. Números perfeitos são tais 
	que	a soma dos divisores menores que o 
	próprio número é igual a ele mesmo.
*/

#include <iostream>
using namespace std;

void print(int value) {
	if(value<10){
		cout<<"   "<<value<<" é um número perfeito."<<endl;
	}
	else if(value<100){
		cout<<"  "<<value<<" é um número perfeito."<<endl;
	}
	else if(value<1000){
		cout<<" "<<value<<" é um número perfeito."<<endl;
	}
	else if(value<10000){
		cout<<value<<" é um número perfeito."<<endl;
	}
}

int main() {
	// i é o número testado | u são os divisores
	int i=1, u=1, sum=0, Max=10000;
	while(i<=Max){
		while(u<i){
			if(i%u==0){
				sum=sum+u;
			}
			u++;
		}
		if(sum == i){
			print(i);
		}
		i++;
		u=1; sum=0;
	}
	return 0;
}
