#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <vector>
#include <iostream>

class PhysicsEngine{
	private:
                double mu; //coeficiente de friccion cte.
                double v0;
                double g;

                int step = 10;

	public:
		PhysicsEngine(double mu, double v0);

                void set_mu(double mu);
                void set_v0(double v0);
                void set_step(int step);

                double get_mu();
                double get_v0();
                double get_g();
                int get_step();

                double computeDeAcceleration();
                double computeStopDistance();
                double computeXSpeed(double x);

                void generateTrajectory(std::vector<double>& distances, std::vector<double>& speeds);
};

#endif
