#include "PP6Day5Cut.hpp"
#include <vector>
#include "PP6Particle.hpp"
#include "PP6Math.hpp"

enum CutType{
  Greater,
  Less,
  Range,
};

class MassCut : public Cut {
public:
  MassCut(const double CutValue, const CutType type);
  MassCut(const double CutMin, const double CutMax, const CutType type);

  virtual ~MassCut();

  virtual bool select(const Particle& P);
  virtual std::vector<Particle> select(const std::vector<Particle>& Vp );

private:
  CutType type_;
  double CutValue1;
  double CutValue2;

};
