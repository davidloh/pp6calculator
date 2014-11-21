#include <iostream>

#ifndef THREEVECTOR_HPP
#define THREEVECTOR_HPP



class threevector {
public:

  threevector(double x_, double y_, double z_);

  void setx(double x_);
  void sety(double y_);
  void setz(double z_);

  double getx();
  double gety();
  double getz();

  double getlength();
 

   threevector operator+=(threevector& rhs){
     x += rhs.x;
     y += rhs.y;
     z += rhs.z;
     return *this;
   }

   threevector operator-=(threevector& rhs){
     x -= rhs.x;
     y -= rhs.y;
     z -= rhs.z;
     return *this;
   }

  double operator*=(threevector& rhs){
    return x*rhs.x + y*rhs.y + z*rhs.z;
  }



private:

  double x;
  double y;
  double z;

  double length();

};


threevector* create3v(double x, double y, double z);

void destroy3v( threevector *&v);

 std::ostream& operator<<(std::ostream& stream, threevector& v);


#endif
