#include <iostream>
#include <climits>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::string;

#ifndef EX4_PP6MATH_HH
#define EX4_PP6MATH_HH


double add(double a, double b);

double sub(double a, double b);

double mult(double a, double b);

double div(double a, double b);

void swap(double& a, double& b);

void intswap(int& a, int& b);

double line(double m, double c);

bool quad(double a, double b, double c, double& sol1, double& sol2);

double vec3(double a, double b, double c);

double vec4(double a, double b, double c, double d);

double mass(double e1, double px1, double py1, double pz1, double e2, double px2, double py2, double pz2);

double input();

void input4(double& a, double& b, double& c, double& d);

void sort(double *a, int N);

void indexsort(double *a, int* b, int N);

double Energy(double m, double px, double py, double pz);

double mean(double *a, int N);

double stdev(double *a, int N);

int countlines(string file);

//fourvector zboost(fourvector s, double v);

#endif
