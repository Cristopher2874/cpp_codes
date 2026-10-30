#ifndef CAR_H
#define CAR_H

#include "wheel.h"
#include <vector>

class Car : public Shape{
    private:
        Wheel front_left_wheel;
        Wheel front_right_wheel;
        Wheel rear_left_wheel;
        Wheel rear_right_wheel;
        const int window_width = 1000;
        const int window_height = 480;

    public:
        Car(int x = 320, int y = 240, int wheel_width = 30, int wheel_side = 30);

        int get_window_width();
        int get_window_height();

        void draw();
        void erase();

        void moveTo(int x, int y);

        void animate(const std::vector<double>& distances,
                     const std::vector<double>& speeds);

        void show_text_on_window(int x, int y, std::string message);
};

#endif
