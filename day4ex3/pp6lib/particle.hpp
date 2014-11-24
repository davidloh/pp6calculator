#include <iostream>
#include "threevector.hpp"
#include "fourvector.hpp"
#include <string>

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

using std::string;

class particle {
public:

  particle(double mass_, fourvector P_, string type_);

//   void setType(string type_);

//   void setpx(double px_);
//   void setpy(double py_);
//   void setpz(double pz_);

  double getE();
  double getmass();
  string getType();

  void setType(string type_);
  void setpx(double px_);
  void setpy(double py_);
  void setpz(double pz_);

  double operator*=(particle& rhs){

    return sqrt( mass*mass + rhs.getmass() * rhs.getmass() + 2 * (P *= rhs.P) ); 

  }


private:

  double mass;
  fourvector P;
  string type;

}; 
  

particle* createparticle(string type, double px, double py, double pz);

void destroyparticle( particle *&p);


#endif
