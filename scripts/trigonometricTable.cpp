#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14159265

// Converts X rad for degrees for sin function
double sinFunction (float param)
{
  double result;
  result = sin (param*PI/180);
  return result;
}

// Converts X rad for degrees for cos function
double cosFunction (float param)
{
	double result;
	result = cos(param*PI/180);
	return result;
}

// Converts X rad for degrees for tan function
double tanFunction (float param)
{
	double result;
	result = tan(param*PI/180);
	return result;
}

void space () {
	cout <<"         ";
}

int main ()
{
	float deg;
	cout <<"Ângulo     Seno       Cosseno      Tangente"<<endl;
	for(deg=0;deg<90;deg+=3){
		cout <<deg;
		space();
		cout <<sinFunction(deg);
		space();
		cout <<cosFunction(deg);
		space();
		cout <<tanFunction(deg)<<endl;
	}
}
