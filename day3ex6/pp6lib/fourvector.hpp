#include <iostream>

#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP



enum type4v{
  spacelike,
  timelike,
  null,
};



class fourvector {
public:

  fourvector(double t_, double x_, double y_, double z_);


  void zboost(double v);

  double gett();
  double getx();
  double gety();
  double getz();

  double getinterval();
  type4v get4vtype();

  fourvector operator+=(fourvector& rhs){
    t += rhs.t;
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
   }

  fourvector operator-=(fourvector& rhs){
    t -= rhs.t;
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }



private:

  double t;
  double x;
  double y;
  double z;

  double interval();
  type4v type();

};


fourvector* create4v(double t, double x, double y, double z);

void destroy4v( fourvector *&s);

std::ostream& operator<<(std::ostream& stream, fourvector& v);


#endif
	       
