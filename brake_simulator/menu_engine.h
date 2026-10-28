#ifndef MENU_ENGINE_H
#define MENU_ENGINE_H

#include "car.h"
#include <vector>
#include <iostream>

using namespace std;

class MenuEngine{
	private:
        Car current_car; //auto
        int selected_car; 

	public:
		MenuEngine(int selected_car);

        void set_selected_car(int selected_car);

        int get_selected_car();
        void get_start_parameters();
        
        void show_header();
        void show_simulation_results();
        void start();
};

#endif
