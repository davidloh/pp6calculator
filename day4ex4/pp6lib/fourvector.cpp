#include <cmath>
#include "fourvector.hpp"
#include "threevector.hpp"

fourvector* create4v(double t, double x, double y, double z) {
  
  threevector *v;
  v = create3v(x, y, z);  

  return new fourvector(t, *v);
}


fourvector::fourvector(double t_, threevector v_)
  : t(t_), v(v_) 

{ 
  compute_interval(); //calculate properties of 4 vector when it is constructed
  fourvector::type();
}

void fourvector::compute_interval(){

  double l = v.length();

  interv = t*t - l*l;
}

// double fourvector::interval(){

//   double l = v.length();

//   return t*t - l*l; 
// }

double fourvector::interval(){
  return interv;
}

type4v fourvector::type(){

  if ( interv > 0.0)   return timelike;
  if ( interv < 0.0)   return spacelike;

  else  return null;

}


void fourvector::zboost(double v_){                       

  double z = v.getz();
  
  double gamma = 1 / sqrt( 1 - v_*v_ );                             
  
  double tprime = gamma * ( t - v_*z );
  double zprime = gamma * ( z - v_*t ); // calculate co-ordinates in boosted frame                                                                                                 
  t = tprime;
  
  v.setz(zprime);

}                             


// double fourvector::getinterval() const{
//   return interval;
// }

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

type4v fourvector::get4vtype() {
  return type();
}

double fourvector::get3vlength() {
  return v.length();
}

void fourvector::sett(double t_){
  t =t_;
}

void fourvector::setx(double x_){
  v.setx(x_);
}

void fourvector::sety(double y_){
  v.sety(y_);
}

void fourvector::setz(double z_){
  v.setz(z_);
}



std::ostream& operator<<(std::ostream& stream, fourvector& v){
  stream <<"("<< v.gett() << ", "<< v.getx()<<", "<< v.gety() <<", "<< v.getz() << ")";
  return stream;  
}

void destroy4v(fourvector *&s) {
  if(s) {

        
    delete s;
    s = 0;
  }
}
