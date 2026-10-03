#include "miniwin.h"
#include "fish.h"
#include "bubble.h"
#include "seaweed.h"
#include "jellyfish.h"
#include "coral.h"

using namespace miniwin;

int main() {
    vredimensiona(640, 480);
    borra();

    Fish pez_amarillo(220, 220, 45, miniwin::AMARILLO);
    Fish pez_cyan(440, 320, 30, miniwin::CYAN);
    Bubble burbuja_grande(120, 120, 18);
    Bubble burbuja_pequena(155, 170, 9);
    Bubble burbuja_pez_1(500, 245, 11);
    Bubble burbuja_pez_2(555, 285, 7);
    Bubble burbuja_pez_3(515, 385, 14);
    Bubble burbuja_pez_4(465, 415, 6);
    Bubble burbuja_pez_5(590, 350, 9);
    Seaweed alga(570, 430, 100, miniwin::VERDE);
    Jellyfish medusa(330, 130, 28, miniwin::MAGENTA);
    Coral coral(90, 430, 90, miniwin::ROJO);

    pez_amarillo.draw();
    pez_cyan.draw();
    burbuja_grande.draw();
    burbuja_pequena.draw();
    burbuja_pez_1.draw();
    burbuja_pez_2.draw();
    burbuja_pez_3.draw();
    burbuja_pez_4.draw();
    burbuja_pez_5.draw();
    alga.draw();
    medusa.draw();
    coral.draw();

    refresca();

    while (tecla() == NINGUNA);

    pez_amarillo.erase();
    pez_cyan.erase();
    burbuja_grande.erase();
    burbuja_pequena.erase();
    burbuja_pez_1.erase();
    burbuja_pez_2.erase();
    burbuja_pez_3.erase();
    burbuja_pez_4.erase();
    burbuja_pez_5.erase();
    alga.erase();
    medusa.erase();
    coral.erase();

    refresca();

    while (tecla() == NINGUNA);

    vcierra();
    return 0;
}
