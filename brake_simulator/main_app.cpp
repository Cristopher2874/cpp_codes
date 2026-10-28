#include "menu_engine.h"
#include "miniwin.h"

int main(){
    MenuEngine main_engine = MenuEngine();

    main_engine.start_main();

    while (miniwin::tecla() == miniwin::NINGUNA);

    miniwin::vcierra();
    
    return 0;
}