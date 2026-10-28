#ifndef MENU_ENGINE_CPP
#define MENU_ENGINE_CPP

#include "menu_engine.h"
#include "physics_engine.h"
#include <cmath>
#include <string>

MenuEngine::MenuEngine(int selected_car) : engine(1.0, 1.0){
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
    double mu=0.0, v0=0.0;
    mu = get_value(mu, "Enter the mu value different from 0: ");
    v0 = get_value(v0, "Enter the v0 value in km/h different from 0: ");
    engine.set_mu(mu);
    engine.set_v0(v0);

    std::cout<<"Started values for mu and v0"<<std::endl;
    return;
}

void MenuEngine::show_header(){
    std::cout<<"Welcome to brake simulator 3.0"<<std::endl;
    return;
}

void MenuEngine::show_simulation_results(){
    std::vector<double> distances;
    std::vector<double> speeds;
    double step=10;
    
    engine.generateTrajectory(distances, speeds, step);

    std::cout<<"Distance "<<"Speed"<<std::endl;

    for(std::size_t i = 0; i<distances.size(); i++){
        std::cout<<distances[i]<<" "<<speeds[i]<<std::endl;
    }

    return;
}

void MenuEngine::start_main(){
    show_header();
    get_start_parameters();
    show_simulation_results();
    return;
}

#endif