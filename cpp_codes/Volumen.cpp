// volumen cubo ejercicio

#include <iostream>

using namespace std;

int volumen_cubo (int a=1, int b=1, int c=1);

int main ()
{
	cout << "Volumen: " << volumen_cubo() << endl;
	cout << "Volumen: " << volumen_cubo(2) << endl;
	cout << "Volumen: " << volumen_cubo(2,2) << endl;
	cout << "Volumen: " << volumen_cubo(2,2,2) << endl;
	
	return 0;
	
}

int volumen_cubo (int a, int b, int c)
{
	return a*b*c;
}