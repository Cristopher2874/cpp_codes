// sobrecarga de funciones

#include <iostream>

using namespace std;

int cuadrado (int x);
double cuadrado (double x);

int main ()
{
	cout << "cuadrado de 7: " << cuadrado (7) << endl;
	cout << "cuadrado de 7.5: " << cuadrado (7.5) << endl;
	
	return 0;
	
}

int cuadrado (int x)
{
	return x * x;
}

double cuadrado (double x)
{
	return x * x;
}