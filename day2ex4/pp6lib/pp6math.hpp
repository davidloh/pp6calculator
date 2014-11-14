#include <iostream>
#include <climits>
#include <cmath>

using std::cout;
using std::cin;

#ifndef EX4_PP6MATH_HH
#define EX4_PP6MATH_HH


double add(double a, double b);

double sub(double a, double b);

double mult(double a, double b);

double div(double a, double b);

void swap(double& a, double& b);

double line(double m, double c);

bool quad(double& a, double& b, double& c);

double vec3(double a, double b, double c);

double vec4(double a, double b, double c, double d);

double mass(double e1, double px1, double py1, double pz1, double e2, double px2, double py2, \
	    double pz2);

double input();

void input4(double& a, double& b, double& c, double& d);

#endif
