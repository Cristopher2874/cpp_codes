// clase con constructor, set y gets

#include <iostream>

using namespace std;

class LibroCalificaciones{
	private:
		string nombreCurso;
	public:
		//explicit LibroCalificaciones (string nombre): nombreCurso(nombre){}
		
		explicit LibroCalificaciones(string nombre){
			establecerNombreCurso(nombre);
		}
		
		void establecerNombreCurso(string nombre)
		{
			nombreCurso = nombre.substr(0,25);
			if (nombre.size()>25)
			cerr << "Se trunco el nombre" << nombre << "a 25 caracteres" << endl;
		}
		
		string obtenerNombreCurso() const
		{
			return nombreCurso;
		}
		void mostrarMensaje()const
		{
			cout << "Libro de calificaciones de " << nombreCurso << endl;
		}
};

int main ()
{
	string nombreDelCurso;
	
	LibroCalificaciones miLibroCalificaciones1 ("Programacion I");
	LibroCalificaciones miLibroCalificaciones2 ("Programacion II");
	
	miLibroCalificaciones1.mostrarMensaje();
	miLibroCalificaciones2.mostrarMensaje();
	
	miLibroCalificaciones1.establecerNombreCurso("P3");
	cout << "Nombre del curso: " << miLibroCalificaciones1.obtenerNombreCurso()<<endl;
	
	return 0;
}