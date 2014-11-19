#include <cmath>
#include "fourvector.hpp"


class fourvector {
public:



  double t;
  double x; 
  double y;
  double z;

};

fourvector* create4v() {
  return new fourvector;
}

void destroy4v(fourvector *&s) {
  if(s) {
    delete s;
    s = 0;
  }
}

void set4vt (fourvector *s, double t){
  s->t = t;
}

void set4vx (fourvector *s, double x){
  s->x = x;
}

void set4vy (fourvector *s, double y){
  s->y = y;
}

void set4vz (fourvector *s, double z){
  s->z = z;
}

void zboost( fourvector *s, double v){                       

     double gamma = 1 / sqrt( 1 - v*v );                             

     double tprime = gamma * ( s->t - v*s->z );
     double zprime = gamma * ( s->z - v*s->t ); // calculate co-ordinates in boosted frame                                                                                                 
     s->t = tprime;
     s->z = zprime;

}                             

double l2(fourvector *s){
  return s->t * s->t - s->x * s->x - s->y * s->y - s->z * s->z;
}

type4v get4vtype(fourvector *s){

  double s2 = s->t * s->t - s->x * s->x - s->y * s->y - s->z * s->z;

  if ( s2 > 0.0){
      return timelike;
  }
  if ( s2 < 0.0){
      return spacelike;
  }
  if ( s2 == 0.0){
    return null;
  }
}

double return4vt(fourvector *s){
  return s->t;
}

double return4vz(fourvector *s){
  return s->z;
}


double tlength(fourvector *s){
  return sqrt( s->t * s->t - s->x * s->x - s->y * s->y - s->z * s->z );
}

double slength(fourvector *s){
  return sqrt(- s->t * s->t + s->x * s->x + s->y * s->y + s->z * s->z );
}
