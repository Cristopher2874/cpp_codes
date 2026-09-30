#include <stdio.h>

int main() {
    int calificacion = 78;

    // if comprueba si una condicion es verdadera.
    if (calificacion >= 90) {
        printf("Excelente! Tu calificacion es una A.\n");
    // else if comprueba otra condicion si la primera era falsa.
    } else if (calificacion >= 60) {
        printf("Aprobaste! Tu calificacion es %d.\n", calificacion);
    // else se ejecuta si ninguna de las condiciones anteriores era verdadera.
    } else {
        printf("Necesitas estudiar un poco mas. Tu calificacion es %d.\n", calificacion);
    }

    // Cambia calificacion a 95, 75 o 40 para ver otro resultado.

    return 0;
}