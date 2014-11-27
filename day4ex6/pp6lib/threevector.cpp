#include <cmath>
#include "threevector.hpp"
#include <iostream>

// constructors

threevector::threevector() // default (zero) constructor
  : x(0.0), y(0.0), z(0.0)
{
  compute_length();
}

threevector::threevector(const threevector& v3) // copy constructor
  : x( v3.getx() ), y( v3.gety() ), z( v3.getz() )
{
  compute_length();
}

threevector::threevector(const double x_,const double y_,const double z_)
  : x(x_), y(y_), z(z_)
{
  compute_length(); //calculate properties of 3 vector when it is constructed
}

// operators
threevector& threevector::operator=(const threevector& v3){
  if( this != &v3){
    x = v3.getx();
    y = v3.gety();
    z = v3.getz();
  }
  return *this;
}

threevector& threevector::operator+=(const threevector& rhs){
  x += rhs.getx();
  y += rhs.gety();
  z += rhs.getz();
  return *this;
}

threevector& threevector::operator-=(const threevector& rhs){
  x -= rhs.getx();
  y -= rhs.gety();
  z -= rhs.getz();
  return *this;
}

threevector& threevector::operator*=(const double scalar){
  x *= scalar;
  y *= scalar;
  z *= scalar;
  return *this;
}



void threevector::compute_length(){

  len = sqrt( x*x + y*y + z*z );
}

//set functions

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

// get functions

double threevector::getx() const{
  return x;
}

double threevector::gety() const{
  return y;
}

double threevector::getz() const{
  return z;
}

double threevector::getlength() const{
  return len;
}

double threevector::getr() const{
  return len;
}

double threevector::getphi() const{
  double xylen = sqrt( x*x + y*y);
  return atan(xylen / z);
}

double threevector::gettheta() const{
  return atan(y / x);
}


std::ostream& operator<<(std::ostream& stream, const threevector& v){
   stream <<"("<< v.getx()<<", "<< v.gety() <<", "<< v.getz() << ")";
   return stream;
 }

double dot3v(const threevector v1, const threevector v2){

  return v1.getx() * v2.getx() + v1.gety() * v2.gety() + v1.getz() * v2.getz();

}
