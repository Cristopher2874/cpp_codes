#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <vector>
#include <iostream>

using namespace std;

class PhysicsEngine{
	private:
                double mu; //coeficiente de friccion cte.
                double v0;
                double g;

	public:
		PhysicsEngine(double mu, double v0);

                void set_mu(double mu);
                void set_v0(double v0);

                double get_mu();
                double get_v0();
                double get_g();

                double computeDeAcceleration();
                double computeStopDistance();
                double computeXSpeed(double x);

                void generateTrajectory(vector<double>& distances, vector<double>& speeds, double step=10);
};

#endif
