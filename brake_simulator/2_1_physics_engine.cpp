#ifndef PHYSICS_ENGINE_CPP
#define PHYSICS_ENGINE_CPP

#include "2_physics_engine.h"
#include <algorithm>
#include <cmath>
#include <limits>

PhysicsEngine::PhysicsEngine(double mu, double v0){
    set_mu(mu);
    set_v0(v0);
    this->g = 9.81;
}

void PhysicsEngine::set_mu(double mu){
    if(mu<=0){
        mu=1;
        std::cerr<<"mu = 1 as default since it cannot be 0 or negative"<<std::endl;
    }
    this->mu = mu;
    return;
}

void PhysicsEngine::set_v0(double v0){
    if(v0<=0){
        v0=1;
        std::cerr<<"V0 = 1 as default since it cannot be 0 or negative"<<std::endl;
    }
    this->v0 = v0/3.6; // pasamos a ms
    return;
}

void PhysicsEngine::set_step(int step){
    if(step <=0){
        step = 10;
        std::cerr<<"step = 10 as default since it cannot be 0 or negative"<<std::endl;
    }
}

double PhysicsEngine::get_mu(){
    return this->mu;
}
double PhysicsEngine::get_v0(){
    return this->v0;
}

double PhysicsEngine::get_g(){
    return this->g;
}

int PhysicsEngine::get_step(){
    return this->step;
}

double PhysicsEngine::computeDeAcceleration(){
    return -(get_mu() * get_g());
}

double PhysicsEngine::computeStopDistance(){
    double v02 = get_v0() * get_v0();
    double den = 2 * (computeDeAcceleration());

    return std::abs(v02/den); // la distancia siempre es positiva
}

double PhysicsEngine::computeXSpeed(double x){
    double v02 = get_v0() * get_v0();
    double second = 2 * (computeDeAcceleration()) * x;
    double square_speed = v02+second;

    if(square_speed<0){
        square_speed=0;
    }

    double vx = std::sqrt(square_speed);
    return vx*3.6; // a km/h
}

void PhysicsEngine::generateTrajectory(std::vector<double>& distances, std::vector<double>& speeds){
    double total_distance = computeStopDistance();
    double temp_speed;

    if (step <= 0) {
        step = 10;
    }

    distances.clear();
    speeds.clear();
    
    for(double i = 0; i<total_distance; i+=step){
        temp_speed = computeXSpeed(i);
        distances.push_back(i);
        speeds.push_back(temp_speed);
    }

    if(distances.empty() || (distances.back()-total_distance) > step){
        distances.push_back(total_distance);
        speeds.push_back(0.0);
    }else {
        distances.back() = total_distance;
        speeds.back() = 0.0;
    }

    return;
}

#endif