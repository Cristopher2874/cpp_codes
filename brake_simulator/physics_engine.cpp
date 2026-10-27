#ifndef PHYSICS_ENGINE_CPP
#define PHYSICS_ENGINE_CPP

#include "physics_engine.h"
#include "math.h"

PhysicsEngine::PhysicsEngine(double mu, double v0){
    set_mu(mu);
    set_v0(v0);
    this->g = 9.81;
}

void PhysicsEngine::set_mu(double mu){
    this->mu = mu;
    return;
}

void PhysicsEngine::set_v0(double v0){
    this->v0 = v0;
    return;
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

double PhysicsEngine::computeDeAcceleration(){
    return -(get_mu() * get_g());
}

double PhysicsEngine::computeStopDistance(){
    double v02 = get_v0() * get_v0();
    double den = 2 * (computeDeAcceleration());

    return abs(v02/den); // la distancia siempre es positiva
}

double PhysicsEngine::computeXSpeed(double x){
    double v02 = get_v0() * get_v0();
    double second = 2 * (computeDeAcceleration()) * x;
    double vx = sqrt(v02 + second);
    return vx*3.6; // a km/h
}

void PhysicsEngine::generateTrajectory(vector<double>& distances, vector<double>& speeds, double step=10){
    double total_distance = computeStopDistance();
    double temp_speed;
    
    for(int i = 0; i<=total_distance; i+=step){
        temp_speed = computeXSpeed(i);
        distances.push_back(total_distance-i);
        speeds.push_back(temp_speed);
    }

    return;
}

#endif