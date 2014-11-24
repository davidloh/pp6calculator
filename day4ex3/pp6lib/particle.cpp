#include <cmath>
#include "fourvector.hpp"
#include "threevector.hpp"
#include "particle.hpp"

particle* createparticle(string type, double px, double py, double pz){
 
  double mass = 0;

  double E = 0;


  fourvector *P;
  P = create4v(E,px,py,pz);


    return new particle(mass, *P, type);
}

particle::particle(double mass_, fourvector P_, string type_)
  : mass(mass_), P(P_), type(type_)

{}



void particle::setType(string type_){
  type = type_;

  //also find mass given particle type
  if(type == "mu+" || "mu-"){
    mass = 0.105658;
  }
}

void particle::setpx(double px_){
  P.setx(px_);
}

void particle::setpy(double py_){
  P.sety(py_);
}

void particle::setpz(double pz_){
  P.setz(pz_);
}

double particle::getE(){
  return P.gett();
}

string particle::getType(){
  return type;
}

double particle::getmass(){
  return mass;
}


void destroyparticle(particle *&p) {
  if(p) {
    delete p;
    p = 0;
  }
}


