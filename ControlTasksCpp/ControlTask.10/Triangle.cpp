#include "Triangle.h"
#include <math.h>
 
//Ęîěďîçčöč˙ 

Triangle::Triangle(Dot a, Dot b, Dot c)
{
	this->z1 = a;
	this->z2 = b;
	this->z3 = c;
}

void Triangle::GetSides(double& lenghtA, double& lenghtB, double& lenghtC)
{
	lenghtA = this->z1.distanceTo(this->z2);
	lenghtB = this->z2.distanceTo(this->z3);
	lenghtC = this->z3.distanceTo(this->z1);
}
double Triangle::GetPerimeter(double a, double b, double c)
{
	return a + b + c;
}
double Triangle::GetArea(double a, double b, double c, double pp)
{
	return sqrt(pp * (pp - a) * (pp - b) * (pp - c));
}
