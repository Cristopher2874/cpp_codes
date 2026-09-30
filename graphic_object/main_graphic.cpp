#include "miniwin.h"
#include "fish.h"

using namespace miniwin;

int main() {
    vredimensiona(640, 480);
    borra();

    Fish pez_amarillo(220, 220, 45, miniwin::AMARILLO);
    Fish pez_cyan(440, 320, 30, miniwin::CYAN);

    pez_amarillo.draw();
    pez_cyan.draw();

    refresca();

    while (tecla() == NINGUNA);

    pez_amarillo.erase();
    pez_cyan.erase();

    refresca();

    while (tecla() == NINGUNA);

    vcierra();
    return 0;
}
