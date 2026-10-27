#ifndef MENU_ENGINE_CPP
#define MENU_ENGINE_CPP

#include "menu_engine.h"
#include "math.h"

MenuEngine::MenuEngine(int selected_car=1){
    set_selected_car(selected_car);
}

void MenuEngine::set_selected_car(int selected_car){
    this->selected_car = selected_car;
    return;
}

int MenuEngine::get_selected_car(){
    return this->selected_car;
}
void MenuEngine::get_start_parameters(){
    return;
}

void MenuEngine::show_header(){
    cout<<"Welcome to break simulator 3.0"<<endl;
    return;
}

void MenuEngine::show_simulation_results(){
    return;
}

void MenuEngine::start(){
    show_header();
    get_start_parameters();
    show_simulation_results();
    return;
}

#endif