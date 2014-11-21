#include <cmath>
#include "threevector.hpp"


threevector* create3v(double x,double y,double z) {
  return new threevector(x,y,z);
}

void destroy3v(threevector *&v) {
  if(v) {
    delete v;
    v = 0;
  }
}

threevector::threevector(double x_, double y_, double z_)
  : x(x_), y(y_), z(z_)

{
  threevector::length(); //calculate properties of 3 vector when it is constructed
}

double threevector::length(){

  return sqrt( x*x + y*y + z*z );
}


double threevector::getlength(){
  return length();
}

void threevector::setx(double x_){
  x = x_;
}

void threevector::sety(double y_){
  y = y_;
}

void threevector::setz(double z_){
  z = z_;
}



double threevector::getx(){
  return x;
}

double threevector::gety(){
  return y;
}

double threevector::getz(){
  return z;
}


std::ostream& operator<<(std::ostream& stream, threevector& v){
   stream <<"("<< ", "<< v.getx()<<", "<< v.gety() <<", "<< v.getz() << ")";
   return stream;
 }
