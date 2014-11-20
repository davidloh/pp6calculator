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
{}


// void set4vt (fourvector *s, double t){
//   s->t = t;
// }

// void set4vx (fourvector *s, double x){
//   s->x = x;
// }

// void set4vy (fourvector *s, double y){
//   s->y = y;
// }

// void set4vz (fourvector *s, double z){
//   s->z = z;
// }

void fourvector::zboost(double v){                       

     double gamma = 1 / sqrt( 1 - v*v );                             

     double tprime = gamma * ( t - v*z );
     double zprime = gamma * ( z - v*t ); // calculate co-ordinates in boosted frame                                                                                                 
     t = tprime;
     z = zprime;

}                             

double l2(fourvector *s){
  return s->t * s->t - s->x * s->x - s->y * s->y - s->z * s->z;
}

type4v get4vtype(fourvector *s){

  double s2 = s->t * s->t - s->x * s->x - s->y * s->y - s->z * s->z;

  if ( s2 > 0.0)   return timelike;
  
  if ( s2 < 0.0)   return spacelike;
  
  else  return null;
  
}

double return4vt(fourvector *s){
  return s->t;
}

double return4vz(fourvector *s){
  return s->z;
}


// double tlength(fourvector *s){
//   return sqrt( s->t * s->t - s->x * s->x - s->y * s->y - s->z * s->z );
// }

// double slength(fourvector *s){
//   return sqrt(- s->t * s->t + s->x * s->x + s->y * s->y + s->z * s->z );
// }


double fourvector::length(){

  return t*t - x*x - y*y - z*z;

}
