#include "miniwin.h"

using namespace miniwin;

// clase abstracta
class Figura {
    protected:
        int x;
        int y;
        int color_figura;
        bool relleno;

    public:
        Figura(int x, int y, int color_figura, bool relleno = true) {
            this->x = x;
            this->y = y;
            this->color_figura = color_figura;
            this->relleno = relleno;
        }

        virtual ~Figura() {}

        // using virtual to keep general usage =0 to init as default
        virtual void dibujar() = 0;
        virtual void borrar() = 0;
};

// herencia desde figura
class Circulo : public Figura {
    private:
        int radio;

    public:
        Circulo(int x, int y, int radio, int color_figura, bool relleno = true)
            : Figura(x, y, color_figura, relleno) {
            this->radio = radio;
        }

        void dibujar() {
            color(color_figura);
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

class Cuadrado : public Figura {
    private:
        int lado;

    public:
        Cuadrado(int x, int y, int lado, int color_figura, bool relleno = true)
            : Figura(x, y, color_figura, relleno) {
            this->lado = lado;
        }

        void dibujar() {
            color(color_figura);
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
            int izq = this->x - this->lado / 2;
            int arr = this->y - this->lado / 2;
            int der = this->x + this->lado / 2;
            int aba = this->y + this->lado / 2;

            if (this->relleno)
                rectangulo_lleno(izq, arr, der, aba);
            else
                rectangulo(izq, arr, der, aba);
        }
};

class Linea : public Figura {
    private:
        int x2;
        int y2;

    public:
        Linea(int x1, int y1, int x2, int y2, int color)
            : Figura(x1, y1, color, false) {
            this->x2 = x2;
            this->y2 = y2;
        }

        void dibujar() {
            color(color_figura);
            linea(x, y, x2, y2);
        }

        void borrar() {
            color(miniwin::NEGRO);
            linea(x, y, x2, y2);
        }
};

int main() {
    vredimensiona(640, 480);
    borra();

    // 1. La Luna
    Circulo luna(540, 80, 35, miniwin::AMARILLO, true);

    // 2. Punta del cohete (se dibuja primero para quedar bajo el cuadrado)
    Circulo punta(320, 200, 40, miniwin::ROJO, true);

    // 3. Cuerpo del cohete
    Cuadrado cuerpo(320, 240, 80, miniwin::BLANCO, true);

    // 4. Ventana del astronauta
    Circulo ventana(320, 240, 15, miniwin::AZUL, true);

    // 5. Aletas (Líneas)
    Linea aleta_izq1(280, 240, 230, 280, miniwin::ROJO);
    Linea aleta_izq2(230, 280, 280, 280, miniwin::ROJO);
    
    Linea aleta_der1(360, 240, 410, 280, miniwin::ROJO);
    Linea aleta_der2(410, 280, 360, 280, miniwin::ROJO);

    // 6. Fuego del propulsor
    Linea fuego1(300, 280, 290, 350, miniwin::AMARILLO);
    Linea fuego2(320, 280, 320, 370, miniwin::AMARILLO);
    Linea fuego3(340, 280, 350, 350, miniwin::AMARILLO);

    // Vamos dibujando por capas
    luna.dibujar();
    
    punta.dibujar();
    cuerpo.dibujar();
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
