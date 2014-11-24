#include <iostream>
#include "threevector.hpp"


#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP



 enum type4v{
   spacelike,
   timelike,
   null,
 };



class fourvector {
public:



  fourvector(double t_, threevector v_);


  void zboost(double v_);

  double gett() const;
  double getx() const;
  double gety() const;
  double getz() const;

  double interval();
  type4v get4vtype();
  double get3vlength();

  void sett(double t_);
  void setx(double x_);
  void sety(double y_);
  void setz(double z_);

  fourvector operator+=(fourvector& rhs){
      t += rhs.t;
      v += rhs.v;
      return *this;
  }

  fourvector operator-=(fourvector& rhs){
      t -= rhs.t;
      v -= rhs.v;
      return *this;
  }

  double operator*=(fourvector& rhs){
    double r2 = v *= rhs.v;
    return t*rhs.t - r2;
  }

private:

  double t;
  threevector v;

  double interv;
  void compute_interval();
  type4v type();

};


fourvector* create4v(double t, double x, double y, double z);

void destroy4v( fourvector *&s);

std::ostream& operator<<(std::ostream& stream, fourvector& v);


#endif
	       
