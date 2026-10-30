#ifndef MENU_ENGINE_H
#define MENU_ENGINE_H

#include "car.h"
#include "2_physics_engine.h"
#include <string>
#include <vector>
#include <iostream>

class MenuEngine{
        private:
                Car current_car; //auto
                PhysicsEngine engine;
                int selected_car;
                std::vector<double> distances;
                std::vector<double> speeds;

	public:
                MenuEngine(int selected_car=1);

                void set_selected_car(int selected_car);

                template<class T>
                T get_value(T value, std::string message){
                        std::cout<<message<<std::endl;
                        std::cin>>value;
                        return value;
                }

                int get_selected_car();
                void get_start_parameters();
        
                void show_header();
                void show_simulation_results();
                void show_simulacion_deacceleration();
                void show_car_animation();
                void start_main();
};

#endif
