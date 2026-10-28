#ifndef MENU_ENGINE_CPP
#define MENU_ENGINE_CPP

#include "menu_engine.h"
#include "physics_engine.h"
#include "math.h"
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
    double mu, v0;
    mu = get_value(mu, "Enter the mu value different from 0: ");
    v0 = get_value(v0, "Enter the v0 value in km/h different from 0: ");
    engine.set_mu(mu);
    engine.set_v0(v0);

    cout<<"Started values for mu and v0"<<endl;
    return;
}

void MenuEngine::show_header(){
    cout<<"Welcome to break simulator 3.0"<<endl;
    return;
}

void MenuEngine::show_simulation_results(){
    vector<double> distances;
    vector<double> speeds;
    double step=10;
    
    engine.generateTrajectory(distances, speeds, step);

    cout<<"Distance "<<"Speed"<<endl;

    for(size_t i = 0; i<distances.size(); i++){
        cout<<distances[i]<<" "<<speeds[i]<<endl;
    }

    cout<<"end"<<endl;

    return;
}

void MenuEngine::start_main(){
    show_header();
    get_start_parameters();
    show_simulation_results();
    return;
}

#endif