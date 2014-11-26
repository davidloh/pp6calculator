#include <cmath>
#include "fourvector.hpp"
#include "threevector.hpp"
#include "particle.hpp"
#include "ParticleInfo.hpp"


particle::particle()
  : pdgcode(0), mass(0.0), P()
{}

particle::particle(const int pdgcode_)
  : pdgcode(pdgcode_), mass(0.0), P()
{
  compute_mass();
  compute_E();
}

particle::particle(const int pdgcode_, const double px_, const double py_, const double pz_)
  : pdgcode(pdgcode_), mass(0.0), P(0, px_, py_, pz_)
{
  compute_mass();
  compute_E();
}


void particle::setpdgcode(int pdgcode_){
   pdgcode = pdgcode_;
   compute_mass();
   compute_E();
}

void particle::setpx(double px_){
  P.setx(px_);
  compute_mass();
  compute_E();
}

void particle::setpy(double py_){
  P.sety(py_);
  compute_mass();
  compute_E();
}

void particle::setpz(double pz_){
  P.setz(pz_);
  compute_mass();
  compute_E();
}

double particle::getE() const{
  return P.gett();
}

int particle::getpdgcode() const{
  return pdgcode;
}

double particle::getmass()const {
  return mass;
}

fourvector particle::get4v() const{
  return P;
}

void particle::compute_E(){

  double p = P.get3vlength();
  double E = sqrt( mass * mass + p*p );

  P.sett( E );
}

void particle::compute_mass(){

  ParticleInfo PDG("pdg.dat");
  mass = PDG.getMass(pdgcode);
}


double invmass(const particle p1, const particle p2){

  double m1 = p1.getmass();
  double m2 = p2.getmass();

  return sqrt( m1*m1 + m2*m2 + 2*dot4v( p1.get4v() , p2.get4v() ) );

}
