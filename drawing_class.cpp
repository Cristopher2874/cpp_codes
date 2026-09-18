#include "miniwin.h"

using namespace miniwin;

class CirculoSimple {
private:
    int x;
    int y;
    int radio;
    int color_circulo;
    bool relleno;

public:
    CirculoSimple(int x, int y, int radio, int color_circulo, bool relleno = true) {
        this->x = x;
        this->y = y;
        this->radio = radio;
        this->color_circulo = color_circulo;
        this->relleno = relleno;
    }

    void dibujar() {
        color(color_circulo);
        if (relleno)
            circulo_lleno(x, y, radio);
        else
            circulo(x, y, radio);
    }

    void borrar() {
        color(miniwin::NEGRO);
        if (relleno)
            circulo_lleno(x, y, radio);
        else
            circulo(x, y, radio);
    }
};

class CuadradoSimple {
private:
    int x;
    int y;
    int lado;
    int color_cuadrado;
    bool relleno;

public:
    CuadradoSimple(int x, int y, int lado, int color_cuadrado, bool relleno = true) {
        this->x = x;
        this->y = y;
        this->lado = lado;
        this->color_cuadrado = color_cuadrado;
        this->relleno = relleno;
    }

    void dibujar() {
        color(color_cuadrado);
        int izq = x - lado / 2;
        int arr = y - lado / 2;
        int der = x + lado / 2;
        int aba = y + lado / 2;

        if (relleno)
            rectangulo_lleno(izq, arr, der, aba);
        else
            rectangulo(izq, arr, der, aba);
    }

    void borrar() {
        color(miniwin::NEGRO);
        int izq = x - lado / 2;
        int arr = y - lado / 2;
        int der = x + lado / 2;
        int aba = y + lado / 2;

        if (relleno)
            rectangulo_lleno(izq, arr, der, aba);
        else
            rectangulo(izq, arr, der, aba);
    }
};

class LineaSimple {
private:
    int x1;
    int y1;
    int x2;
    int y2;
    int color_linea;

public:
    LineaSimple(int x1, int y1, int x2, int y2, int color_linea) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->color_linea = color_linea;
    }

    void dibujar() {
        color(color_linea);
        linea(x1, y1, x2, y2);
    }

    void borrar() {
        color(miniwin::NEGRO);
        linea(x1, y1, x2, y2);
    }
};

int main() {
    vredimensiona(640, 480);
    borra();

    // círculo relleno en la esquina superior para la luna
    CirculoSimple luna(540, 80, 35, miniwin::AMARILLO, true);

    // se dibuja un círculo completo para la punta del cohete
    // el plan es que el cuadrado del cohete tape la mitad de abajo
    CirculoSimple punta(320, 200, 40, miniwin::ROJO, true);

    // es un cuadrado centrado y tiene que llevar las coordenadas alineadas con el círculo
    CuadradoSimple cuerpo(320, 240, 80, miniwin::BLANCO, true);

    // ventana, un círculo sobre el cuerpo
    CirculoSimple ventana(320, 240, 15, miniwin::AZUL, true);

    // líneas cerca del cuadrado para simular las aletas
    LineaSimple aleta_izq1(280, 240, 230, 280, miniwin::ROJO);
    LineaSimple aleta_izq2(230, 280, 280, 280, miniwin::ROJO);

    LineaSimple aleta_der1(360, 240, 410, 280, miniwin::ROJO);
    LineaSimple aleta_der2(410, 280, 360, 280, miniwin::ROJO);

    // líneas debajo del cuerpo para el fuego del cohete
    LineaSimple fuego1(300, 280, 290, 350, miniwin::AMARILLO);
    LineaSimple fuego2(320, 280, 320, 370, miniwin::AMARILLO);
    LineaSimple fuego3(340, 280, 350, 350, miniwin::AMARILLO);

    // dibujamos en orden para tapar las capas
    luna.dibujar();
    
    punta.dibujar();   
    cuerpo.dibujar();  
    // la ventana hasta el final para que parezca que está dentro del cuadrado
    ventana.dibujar(); 
    
    aleta_izq1.dibujar();
    aleta_izq2.dibujar();
    
    aleta_der1.dibujar();
    aleta_der2.dibujar();
    
    fuego1.dibujar();
    fuego2.dibujar();
    fuego3.dibujar();

    refresca();

    while (tecla() == NINGUNA);

    luna.borrar();
    punta.borrar();   
    cuerpo.borrar();  
    ventana.borrar(); 
    aleta_izq1.borrar();
    aleta_izq2.borrar();
    aleta_der1.borrar();
    aleta_der2.borrar();
    fuego1.borrar();
    fuego2.borrar();
    fuego3.borrar();

    refresca();

    while (tecla() == NINGUNA);

    vcierra();
    return 0;
}
