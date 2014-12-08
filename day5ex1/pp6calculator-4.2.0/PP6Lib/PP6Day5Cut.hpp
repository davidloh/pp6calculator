#ifndef CUT_HH
#define CUT_HH

#include <vector>
#include "PP6Particle.hpp"

class Cut{
public:
  virtual ~Cut() {}

  virtual bool select(const Particle& P) = 0;
  virtual std::vector<Particle> select(const std::vector<Particle>& Vp ) = 0;

};

#endif
