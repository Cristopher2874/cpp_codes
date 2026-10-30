#ifndef CAR_CPP
#define CAR_CPP

#include "car.h"

Car::Car(int x, int y, int wheel_width, int wheel_side) : Shape(x, y, miniwin::AZUL),
      front_left_wheel(wheel_width, x - 60, y - 45, wheel_side),
      front_right_wheel(wheel_width, x + 60, y - 45, wheel_side),
      rear_left_wheel(wheel_width, x - 60, y + 45, wheel_side),
      rear_right_wheel(wheel_width, x + 60, y + 45, wheel_side),
      chassis(x, y, 80, miniwin::AZUL),
      cockpit(x - 10, y, 30, miniwin::ROJO),
      front_wing_left(x + 76, y - 24, 16, miniwin::AMARILLO),
      front_wing_right(x + 76, y + 24, 16, miniwin::AMARILLO),
      rear_wing_left(x - 70, y - 24, 20, miniwin::MAGENTA),
      rear_wing_right(x - 70, y + 24, 20, miniwin::MAGENTA),
      nose(x + 58, y, 42, miniwin::AZUL, 0) {}

void Car::draw() {
    front_left_wheel.draw();
    front_right_wheel.draw();
    rear_left_wheel.draw();
    rear_right_wheel.draw();
    rear_wing_left.draw();
    rear_wing_right.draw();
    chassis.draw();
    cockpit.draw();
    nose.draw();
    front_wing_left.draw();
    front_wing_right.draw();
}

void Car::erase() {
    front_wing_left.erase();
    front_wing_right.erase();
    nose.erase();
    cockpit.erase();
    chassis.erase();
    rear_wing_left.erase();
    rear_wing_right.erase();
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

    chassis.moveTo(x, y);
    cockpit.moveTo(x - 10, y);
    front_wing_left.moveTo(x + 76, y - 24);
    front_wing_right.moveTo(x + 76, y + 24);
    rear_wing_left.moveTo(x - 70, y - 24);
    rear_wing_right.moveTo(x - 70, y + 24);
    nose.moveTo(x + 58, y);

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
