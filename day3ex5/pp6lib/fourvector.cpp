#include <cmath>
#include "fourvector.hpp"



fourvector* create4v(double t,double x,double y,double z) {
  return new fourvector(t,x,y,z);
}

void destroy4v(fourvector *&s) {
  if(s) {
    delete s;
    s = 0;
  }
}

fourvector::fourvector(double t_, double x_, double y_, double z_)
  : t(t_), x(x_), y(y_), z(z_) 

{ 
  fourvector::interval(); //calculate properties of 4 vector when it is constructed
  fourvector::type();
}

double fourvector::interval(){

  return t*t - x*x - y*y - z*z;
}

type4v fourvector::type(){

  if ( interval() > 0.0)   return timelike;
  if ( interval() < 0.0)   return spacelike;

  else  return null;

}


void fourvector::zboost(double v){                       

     double gamma = 1 / sqrt( 1 - v*v );                             

     double tprime = gamma * ( t - v*z );
     double zprime = gamma * ( z - v*t ); // calculate co-ordinates in boosted frame                                                                                                 
     t = tprime;
     z = zprime;

}                             


double fourvector::getinterval(){
  return interval();
}

double fourvector::gett(){ 
  return t;
}

double fourvector::getx(){
  return x;
}

double fourvector::gety(){
  return y;
}

double fourvector::getz(){
  return z;
}

type4v fourvector::get4vtype(){
  return type();
}
