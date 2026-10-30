#include "menu_engine.h"
#include "car.h"
#include "miniwin.h"

int main(){
    MenuEngine main_engine = MenuEngine();

    miniwin::vredimensiona(10, 10);
    miniwin::borra();
    
    miniwin::refresca();
    
    main_engine.start_main();
    
    miniwin::vredimensiona(640, 480);
    miniwin::borra();
    
    Car main_car = Car(10,10, 3, 2);
    main_car.draw();

    miniwin::refresca();

    while (miniwin::tecla() == miniwin::NINGUNA);

    miniwin::vcierra();
    
    return 0;
}