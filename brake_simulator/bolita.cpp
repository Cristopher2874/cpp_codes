/ Bolita.cpp

#ifndef BOLITA_CPP
#define BOLITA_CPP

#include "miniwin.h"
#include "Bolita.h"

Bolita::Bolita ()
{
    estableceCoordenadas(100,100);
    estableceRadio(10);
    estableceColor(miniwin::BLANCO);
    estableceRelleno(true);
    estableceVelocidad(2);
    estableceSentido(SE);

}

Bolita::Bolita (int x, int y, int r, int c, bool re, int s, int v)
{
    estableceCoordenadas(x,y);
    estableceRadio(r);
    estableceColor(c);
    estableceRelleno(re);
    estableceVelocidad(v);
    estableceSentido(s);
}

void Bolita::estableceCoordenadas (int x, int y)
{
    this->x = x;
    this->y = y;
}

void Bolita::estableceRadio (int r)
{
    radio_circ = r;
}

void Bolita::estableceColor (int c)
{
    color_circ = c;
}

void Bolita::estableceRelleno (int re)
{
    relleno = re;
}

void Bolita::estableceVelocidad (int v)
{
    velocidad = v;
}

void Bolita::estableceSentido (int s)
{
    if (s==NE || s==NO)
    	sentido_y = -1;
    else
        sentido_y = 1;
        
    if (s==NO || s==SO)
		sentido_x = -1;
	else
		sentido_x = 1;    
}

void Bolita::dibujate ()
{
    miniwin::color (color_circ);
    if (relleno)
    	miniwin::circulo_lleno (x, y, radio_circ);
    else
    	miniwin::circulo (x, y, radio_circ);
}

void Bolita::borrate ()
{
    miniwin::color (miniwin::NEGRO);
    if (relleno)
    	miniwin::circulo_lleno (x, y, radio_circ);
    else
    	miniwin::circulo (x, y, radio_circ);
}

void Bolita::muevete (int nx, int ny)
{
    borrate ();
    x = nx;
    y = ny;
    dibujate ();
}

void Bolita::muevete_en_ventana()
{
	int paso=2, aux_x, aux_y;
	
	if(sentido_x == 1)
	{
		aux_x = x + velocidad;
		if(x >= (639-radio_circ))
			sentido_x = -1;
	}
	else
	{
		aux_x = x - velocidad;
		if (x <= radio_circ)
			sentido_x = 1;
	}

	if(sentido_y == 1)
	{
		aux_y = y + velocidad;
		if(y >= (479-radio_circ))
			sentido_y = -1;
	}
	else
	{
		aux_y = y - velocidad;
		if (y <= radio_circ)
			sentido_y = 1;
	}
 
   muevete(aux_x,aux_y);
}

#endif