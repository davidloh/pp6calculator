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

  fourvector();

  fourvector(const double t_, const double x_, const double y_, const double z_);

  fourvector(const double t_,const threevector v_);


  void zboost(double v_);

  double gett() const;
  double getx() const;
  double gety() const;
  double getz() const;

  double getinterval() const;
  type4v get4vtype() const;
  double get3vlength() const;
  threevector get3v() const;

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


private:

  double t;
  threevector v;

  double interv;
  type4v type;

  void compute_interval();
  void compute_type();

};


std::ostream& operator<<(std::ostream& stream, fourvector& v);

double dot4v(const fourvector s1,const fourvector s2);

#endif
	       
