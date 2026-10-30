#ifndef MENU_ENGINE_CPP
#define MENU_ENGINE_CPP

#include "1_menu_engine.h"
#include "2_physics_engine.h"
#include <cmath>
#include <string>
#include <iomanip>

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

    std::cout<<"\nStarted values for mu and v0"<<std::endl;
    return;
}

void MenuEngine::show_header(){
    std::cout<<"Welcome to brake simulator 3.0"<<std::endl;
    return;
}

void MenuEngine::show_simulacion_deacceleration(){
    double deacceleration = engine.computeDeAcceleration();

    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::right << std::setw(5) << "\n\nDeacceleration (a): " << deacceleration << std::endl;

    return;
}

void MenuEngine::show_simulation_results(){
    double step=10;
    
    engine.generateTrajectory(distances, speeds, step);

    std::cout << std::fixed << std::setprecision(4);

    std::cout << "Total distance (s): " << distances.back() << std::endl;

    std::cout << std::right << std::setw(15) << "\n\nDistance" << std::setw(15) << "Speed" << std::endl;

    std::cout << "-------------------------------" << std::endl;

    for (std::size_t i = 0; i < distances.size(); i++) {
        std::cout << std::setw(15) << distances[i] << std::setw(15) << speeds[i] << std::endl;
    }

    std::cout << "\n Press RETURN to watch simulation" << std::endl;

    return;
}

void MenuEngine::show_car_animation(){    

    while (miniwin::tecla() != miniwin::RETURN);

    miniwin::vredimensiona(640, 480);
    miniwin::borra();
    miniwin::refresca();

    for (std::size_t i = 0; i < distances.size(); ++i) {
        int x = 50 + int(distances[i]*5.0);
        current_car.moveTo(x, 240);

        miniwin::refresca();
        miniwin::espera(100);
    }

    while (miniwin::tecla() == miniwin::NINGUNA);

    miniwin::vcierra();

    return;
}

void MenuEngine::start_main(){
    show_header();
    get_start_parameters();
    show_simulacion_deacceleration();
    show_simulation_results();
    show_car_animation();
    return;
}

#endif