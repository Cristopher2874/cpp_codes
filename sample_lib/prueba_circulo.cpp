#include <iostream>

#include "circulo.h"

using namespace std;

int main(){
    double radio;
    cout<<"Ingrese radio: ";
    cin>>radio;

    cout<<"Diámetro: "<<diametro_circulo(radio)<<endl;
    cout<<"Perímetro: "<<perimetro_circulo(radio)<<endl;
    cout<<"Área: "<<area_circulo(radio)<<endl;

    return 0;
}