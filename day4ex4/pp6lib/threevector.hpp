#include <iosfwd>

#ifndef THREEVECTOR_HPP
#define THREEVECTOR_HPP



class threevector {
public:

  //default constructor
  threevector();

  //copy constructor
  threevector(const threevector& v3);

  //component constructor
  threevector(const double x_, const double y_, const double z_);

  void setx(double x_);
  void sety(double y_);
  void setz(double z_);

  double getx() const;
  double gety() const;
  double getz() const;
  double getlength() const;
 
  threevector& operator=(const threevector& v3);

  threevector& operator+=(const threevector& rhs);

  threevector& operator-=(const threevector& rhs);

  threevector& operator*=(const double scalar);



private:

  double x;
  double y;
  double z;

  double len;
  void compute_length();

};


// threevector* create3v(double x, double y, double z);


std::ostream& operator<<(std::ostream& stream, const threevector& v);

double dot3v(const threevector v1, const threevector v2);

#endif
