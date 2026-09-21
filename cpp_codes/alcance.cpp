// muestra cómo acceder variables globales

#include <iostream>

using namespace std;

void alcance ();

int a = 5, b = 10;


int main ()
{
	int a=1;
	cout << :: a << "-" << b << endl;
	alcance ();
}

void alcance ()
{
	int b=2;
	cout << a << "-" <<  :: b << endl;
}