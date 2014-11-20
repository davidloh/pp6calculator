#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP

class fourvector {
public:

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

fourvector* create4v();

void destroy4v( fourvector *&s);

void set4vt (fourvector *s, double t);
void set4vx (fourvector *s, double x);
void set4vy (fourvector *s, double y);
void set4vz (fourvector *s, double z);

//void zboost(double v);

double return4vt(fourvector *s);
double return4vz(fourvector *s);


//double tlength(fourvector *s);
//double slength(fourvector *s);

type4v get4vtype(fourvector *s);


#endif
	       
