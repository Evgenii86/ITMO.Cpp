#pragma once
#include "Dot.h"
using namespace std;

class Triangle
{
public:
	Dot *z1, *z2, *z3;
	Triangle(Dot *a, Dot *b, Dot *c);
	void GetSides(double& lenghtA, double& lenghtB, double& lenghtC);
	double GetPerimeter(double a, double b, double c);
	double GetArea(double a, double b, double c, double pp);

};
