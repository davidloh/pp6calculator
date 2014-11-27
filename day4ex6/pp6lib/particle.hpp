#include <iostream>
#include "threevector.hpp"
#include "fourvector.hpp"
#include <string>

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

using std::string;

class particle {
public:


  particle();
  particle(const int pdgcode_);
  particle(const int pdgcode_, const double px_, const double py_, const double pz_);



  double getE() const;
  double getmass() const;
  int getpdgcode() const;
  fourvector get4v() const;


  void setpdgcode(int pdgcode_);
  void setpx(double px_);
  void setpy(double py_);
  void setpz(double pz_);


private:

  int pdgcode;
  double mass;
  fourvector P;

  void compute_E();
  void compute_mass();

}; 
  
double invmass(const particle p1, const particle p2);


#endif
