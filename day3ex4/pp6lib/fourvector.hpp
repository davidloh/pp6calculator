#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP

class fourvector {
public:



  fourvector(double t_, double x_, double y_, double z_);


  void zboost(double v);
  double length();

  double t;
  double x;
  double y;
  double z;

};

enum type4v{
  spacelike,
  timelike,
  null,
};

fourvector* create4v(double t, double x, double y, double z);

void destroy4v( fourvector *&s);

void set4vt (fourvector *s, double t);
void set4vx (fourvector *s, double x);
void set4vy (fourvector *s, double y);
void set4vz (fourvector *s, double z);


double return4vt(fourvector *s);
double return4vz(fourvector *s);


type4v get4vtype(fourvector *s);


#endif
	       
