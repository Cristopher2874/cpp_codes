// plantilla

#include <iostream>

using namespace std;

template < class T >

T maximo(T valor1, T valor2, T valor3)
{
	T max  = valor1;
	
	if (valor2 > max)
		max = valor2;
	if (valor2 > max)
		max = valor3;
		
	return max;
}

int main ()
{
	cout << "Maximo: " << maximo(3,8,5) << endl;
	cout << "Maximo: " << maximo('a', 'd', 'f') << endl;
	cout << "Maximo: " << maximo(3.2,8.6,5.3) << endl;
	
	return 0;
}