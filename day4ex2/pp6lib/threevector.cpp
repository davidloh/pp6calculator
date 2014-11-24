#include <cmath>
#include "threevector.hpp"
#include <iostream>

threevector* create3v(double x,double y,double z) {
  return new threevector(x,y,z);
}


threevector::threevector(double x_, double y_, double z_)
  : x(x_), y(y_), z(z_)

{
  compute_length(); //calculate properties of 3 vector when it is constructed
}

void threevector::compute_length(){

  len = sqrt( x*x + y*y + z*z );
}


double threevector::length(){
  return len;
}

void threevector::setx(double x_){
  x = x_;
  compute_length();
}

void threevector::sety(double y_){
  y = y_;
  compute_length();
}

void threevector::setz(double z_){
  z = z_;
  compute_length();
}



double threevector::getx() const{
  return x;
}

double threevector::gety() const{
  return y;
}

double threevector::getz() const{
  return z;
}


std::ostream& operator<<(std::ostream& stream, threevector& v){
   stream <<"("<< ", "<< v.getx()<<", "<< v.gety() <<", "<< v.getz() << ")";
   return stream;
 }
