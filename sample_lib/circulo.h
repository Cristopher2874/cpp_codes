#ifndef CIRCULO_H
#define CIRCULO_H

#include <cmath>

const double PI = 3.1415926535;

double perimetro_circulo(double radio){
    return 2*PI*radio;
}

double diametro_circulo(double radio){
    return radio*2;
}

double area_circulo(double radio){
    return PI*radio*radio;
}

#endif