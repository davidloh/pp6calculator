#include <iostream>
#include <climits>
#include <cmath>
#include "pp6math.hpp"

using std::cout;
using std::cin;



double add(double a, double b){
  return a + b ;
}

double sub(double a, double b){
  return a - b;
}

double mult(double a, double b){
  return a * b;
}

double div(double a, double b){
  return a / b;
}

void swap(double& a, double& b){
  double c = a; // remember the value of "a" before asigning "b" to it
  a = b;
  b = c;
}

double line(double m, double c){
  return  - div(c , m);
}

bool quad(double& a, double& b, double& c){
  double disc = b*b - 4*a*c;
  double a1 = a, b1 = b, c1 = c; // remember original values

  if(disc >= 0){
    a = (-b1 + sqrt( disc) )/ (2*a1);
    b = (-b1 - sqrt( disc) )/ (2*a1);
    return 1;
  }
  else return 0;
}


double vec3(double a, double b, double c){
  return sqrt(a*a + b*b + c*c);
}

double vec4(double a, double b, double c, double d){
  double l = vec3(b,c,d);
  return a*a - l*l;
}

double mass(double e1, double px1, double py1, double pz1, double e2, double px2, double py2, \
\
            double pz2){
  double E = e1 + e2;
  double px = px1 + px2;
  double py = py1 + py2;
  double pz = pz1 + pz2;
  return sqrt( vec4(E,px,py,pz) );
}

double input(){
  double a(0);

  std::cin >> a;

  while (!std::cin){

    std::cout<< "User inpur error: Invalid number. Please retry:\n";

    std::cin.clear(); // clear fail flag
    std::cin.ignore(INT_MAX, '\n'); // clear cin buffer

    std::cin >> a;
  }
}

void input4(double& a, double& b, double& c, double& d){
  a = input();
  b = input();
  c = input();
  d = input();
}
