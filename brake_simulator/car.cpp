#ifndef CAR_CPP
#define CAR_CPP

#include "car.h"

Car::Car(int x, int y, int wheel_width, int wheel_side) : Shape(x, y, miniwin::AZUL),
      front_left_wheel(wheel_width, x - 60, y - 45, wheel_side),
      front_right_wheel(wheel_width, x + 60, y - 45, wheel_side),
      rear_left_wheel(wheel_width, x - 60, y + 45, wheel_side),
      rear_right_wheel(wheel_width, x + 60, y + 45, wheel_side) {}

void Car::draw() {
    front_left_wheel.draw();
    front_right_wheel.draw();
    rear_left_wheel.draw();
    rear_right_wheel.draw();
}

void Car::erase() {
    front_left_wheel.erase();
    front_right_wheel.erase();
    rear_left_wheel.erase();
    rear_right_wheel.erase();
}

void Car::moveTo(int nx, int ny) {
    erase();

    x = nx;
    y = ny;

    front_left_wheel.moveTo(x - 60, y - 45);
    front_right_wheel.moveTo(x + 60, y - 45);
    rear_left_wheel.moveTo(x - 60, y + 45);
    rear_right_wheel.moveTo(x + 60, y + 45);

    draw();
}

void Car::animate(const std::vector<double>& distances, const std::vector<double>& speeds) {
    const int initial_x = 100;
    const int final_x = 900;
    const double scale = distances.back() > 0 ? (final_x - initial_x) / distances.back() : 0;

    moveTo(initial_x, window_height / 2);
    miniwin::refresca();

    for (std::size_t i = 0; i < distances.size(); ++i) {
        int next_x = initial_x + int(distances[i] * scale);
        moveTo(next_x, window_height / 2);
        miniwin::refresca();

        if (i + 1 < distances.size()) {
            double average_speed = (speeds[i] + speeds[i + 1]) / 2.0;
            double distance_step = distances[i + 1] - distances[i];

            // tenemos que agregar un delay para que se tarde más conforme el vehículo va frenando.
            int delay = average_speed > 0 ? int(distance_step / (average_speed / 3.6) * 1000.0) : 0;

            miniwin::espera(delay);
        }
    }
}

int Car::get_window_width(){
    return window_width;
}

int Car::get_window_height(){
    return window_height;
}

void Car::show_text_on_window(int x, int y, std::string message){
    miniwin::color(miniwin::BLANCO);
    miniwin::texto(x, y, message);

    return;
}

#endif
