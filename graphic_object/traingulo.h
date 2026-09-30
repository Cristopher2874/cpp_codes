#include "miniwin.h"

#ifndef TRIANGULO_H
#define TRIANGULO_H

class Triangulo
{
    private:
        int tamanio;
        int x;
        int y;
        
    public:
        Triangulo (int x, int y, int tamanio);
        void dibujate ();
};

#endif