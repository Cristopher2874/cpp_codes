#include "miniwin.h"
#include "traingulo.h"

#ifndef TRIANGULO_CPP
#define TRIANGULO_CPP

Triangulo::Triangulo(int x, int y, int tamanio)
{
   
    // Si tamanio es par, sumar uno para hacerlo impar
    if (tamanio%2 == 0)
       tamanio++;
    
    this->tamanio = tamanio;
    this->x = x;
    this->y = y;
}

void Triangulo::dibujate()
{
    int x1, x2, y1, y2;
    x1 = x - (tamanio-1)/2;
    x2 = x + (tamanio-1)/2;
    y1 = y - (tamanio-1)/2;
    y2 = y;
    
    
    miniwin::color(miniwin::ROJO);
    
    while (x1 <= x2)
    {
        miniwin::linea(x1,y2,x2,y2);
        x1++;
        x2--;
        y2--;
    }
    
    x1 = x - (tamanio-1)/2;
    x2 = x + (tamanio-1)/2;
    y2 = y;
    
    miniwin::color(miniwin::AMARILLO);
    miniwin::linea(x1,y2,x2,y2);
    miniwin::linea(x1,y2,x,y1);
    miniwin::linea(x2,y2,x,y1);
    
}

#endif