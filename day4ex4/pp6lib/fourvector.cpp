#include <string>
#include <cmath>
#include "fourvector.hpp"
#include "threevector.hpp"

using std::string;

// constructors

fourvector::fourvector()
  : t(0.0), v()

{
  compute_interval();
  compute_type();
}

fourvector::fourvector(const double t_, const double x_, const double y_, const double z_)
  : t(t_), v(x_, y_, z_)

{
  compute_interval(); //calculate properties of 4 vector when it is constructed
  compute_type();
}


fourvector::fourvector(const double t_,const threevector v_)
  : t(t_), v(v_) 

{ 
  compute_interval(); 
  compute_type();
}

void fourvector::compute_interval(){

  double l = v.getlength();
  interv = t*t - l*l;
}


void fourvector::compute_type(){

  if ( interv > 0.0){
    type = timelike;
  }
  if ( interv < 0.0){  
    type = spacelike;
  }
  else{
    type = null;
  }
}


void fourvector::zboost(double v_){                       

  double z = v.getz();
  
  double gamma = 1 / sqrt( 1 - v_*v_ );                             
  
  double tprime = gamma * ( t - v_*z );
  double zprime = gamma * ( z - v_*t ); // calculate co-ordinates in boosted frame                                                                                                 
  t = tprime;
  
  v.setz(zprime);

}                             

// get functions

double fourvector::gett() const{ 
  return t;
}

double fourvector::getx() const{
  return v.getx();
}

double fourvector::gety() const{
  return v.gety();
}

double fourvector::getz() const{
  return v.getz();
}

type4v fourvector::get4vtype() const{
  return type;
}

double fourvector::get3vlength() const{
  return v.getlength();
}

threevector fourvector::get3v() const{
  return v;
}

double fourvector::getinterval() const{
  return interv;
}


//set functions

void fourvector::sett(double t_){
  t =t_;
  compute_interval();
}

void fourvector::setx(double x_){
  v.setx(x_);
  compute_interval();
}

void fourvector::sety(double y_){
  v.sety(y_);
  compute_interval();
}

void fourvector::setz(double z_){
  v.setz(z_);
  compute_interval();
}



std::ostream& operator<<(std::ostream& stream, fourvector& v){
  stream <<"("<< v.gett() << ", "<< v.getx()<<", "<< v.gety() <<", "<< v.getz() << ")";
  return stream;  
}


double dot4v(const fourvector s1,const fourvector s2){

  threevector v1 = s1.get3v();

  return s1.gett() * s2.gett() - dot3v( s1.get3v() , s2.get3v() );
  
}
