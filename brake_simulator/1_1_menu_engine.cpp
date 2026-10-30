#ifndef MENU_ENGINE_CPP
#define MENU_ENGINE_CPP

#include "1_menu_engine.h"
#include "2_physics_engine.h"
#include <cmath>
#include <string>
#include <iomanip>
#include <limits>

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
    int step = 0;
    mu = get_value(mu, "Enter the mu value different from 0: ");
    v0 = get_value(v0, "Enter the v0 value in km/h different from 0: ");
    step = get_value(step, "Enter the simulation step as positive value different from 0");
    engine.set_mu(mu);
    engine.set_v0(v0);
    engine.set_step(step);

    std::cout<<"\nStarted values for mu and v0"<<std::endl;
    return;
}

void MenuEngine::show_header(){
    std::cout<<"Welcome to brake simulator 3.0 by Cristopher :)"<<std::endl;
    return;
}

void MenuEngine::show_simulacion_deacceleration(){
    double deacceleration = engine.computeDeAcceleration();

    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::right << std::setw(5) << "\n\nDeacceleration (a): " << deacceleration << " m/s2" << std::endl;

    return;
}

void MenuEngine::show_simulation_results(){

    engine.generateTrajectory(distances, speeds);

    std::cout << std::fixed << std::setprecision(4);

    std::cout << "Total distance (s): " << distances.back() << " m."<< std::endl;

    std::cout << std::right << std::setw(15) << "\n\nDistance" << std::setw(15) << "Speed" << std::endl;

    std::cout << "-------------------------------" << std::endl;

    for (std::size_t i = 0; i < distances.size(); i++) {
        std::cout << std::setw(15) << distances[i] << std::setw(15) << speeds[i] << std::endl;
    }

    std::cout << "\nSimulation results are ready." << std::endl;

    return;
}

void MenuEngine::show_car_animation(){    
    std::cout << "\nPress ENTER in this console to open the MiniWin simulation..."<< std::endl;
    //ignoramos todo hasta el salto de línea
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // ahora sí leemos el enter
    std::cin.get();

    const int window_width = current_car.get_window_width();
    const int window_height = current_car.get_window_height();

    miniwin::vredimensiona(window_width, window_height);
    miniwin::borra();

    current_car.show_text_on_window(20, 30, "Brake simulation");
    current_car.show_text_on_window(20, 50, "The car is braking according to the generated trajectory.");

    int key;

    do {
        current_car.animate(distances, speeds);

        current_car.show_text_on_window(20, window_height - 40,"Press R to repeat or any other key to close.");
        miniwin::refresca();

        do {
            key = miniwin::tecla();
        } while (key == miniwin::NINGUNA);

    } while (key == 'r' || key == 'R');

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