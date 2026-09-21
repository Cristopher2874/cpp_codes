// Clase persona.cpp

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


	class Persona {
		private: 
			string nombre;
			int edad;
			bool genero; //TRUE = masculino , FALSE = femenino
		public:
			Persona(string n, int e, bool g);
			void saluda ();
			~Persona();
	};
	
	
Persona :: Persona (string n, int e, bool g)
{
	this->nombre = n;
	this->edad = e;
	this->genero = g;
}

void Persona :: saluda()
{
	cout << "Hola soy " << nombre << " , ";
	cout << "tengo " << edad << " anios y " ;
	(genero == true) ? cout << "soy hombre" <<endl : cout << "soy mujer"<< endl;
	
}

Persona :: ~Persona()
{
	cout << "soy " << nombre << ", Adios !!" << endl;
}

int main ()
{
	Persona pepe ("Pepe", 50, true);
	Persona cosa ("Tio Cosa", 109, true);
	pepe.saluda();
	cosa.saluda();
	
	system ("PAUSE");
	
	return EXIT_SUCCESS;
}

