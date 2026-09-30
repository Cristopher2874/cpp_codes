#include <stdio.h>

int main() {
    int opcionMenu = 2;

    // switch es util cuando un valor puede coincidir con varias opciones fijas.
    switch (opcionMenu) {
        case 1:
            printf("Elegiste: Comenzar el juego\n");
            break; // Detiene el switch para no continuar con el siguiente case.
        case 2:
            printf("Elegiste: Instrucciones\n");
            break;
        case 3:
            printf("Elegiste: Salir\n");
            break;
        default:
            // default se ejecuta cuando opcionMenu no coincide con ningun case.
            printf("Esa no es una opcion valida.\n");
    }

    // Cambia opcionMenu a 1, 3 u 8 para ver otro resultado.

    return 0;
}