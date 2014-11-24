#include <iostream>
#include <climits>
#include <cmath>
#include "pp6math.hpp"
#include "FileReader.hpp"
#include <string>

using std::cout;
using std::cin;



double add(double a, double b){
  return a + b ;
}

double sub(double a, double b){
  return a - b;
}

double mult(double a, double b){
  return a * b;
}

double div(double a, double b){
  return a / b;
}

void swap(double& a, double& b){
  double c = a; // remember the value of "a" before asigning "b" to it
  a = b;
  b = c;
}

void intswap(int& a, int& b){
  int c =a;
  a = b;
  b = c;
}

double line(double m, double c){
  return  - div(c , m);
}

bool quad(double a, double b, double c, double& sol1, double& sol2){
  double disc = b*b - 4*a*c;

  if(disc >= 0){
    sol1 = (-b + sqrt( disc) )/ (2*a);
    sol2 = (-b - sqrt( disc) )/ (2*a);
    return 1;
  }
  else return 0;
}


double vec3(double a, double b, double c){
  return sqrt(a*a + b*b + c*c);
}

double vec4(double a, double b, double c, double d){
  double l = vec3(b,c,d);
  return a*a - l*l;
}

double mass(double e1, double px1, double py1, double pz1, double e2, double px2, double py2, double pz2){
  double E = e1 + e2;
  double px = px1 + px2;
  double py = py1 + py2;
  double pz = pz1 + pz2;
  return sqrt( vec4(E,px,py,pz) );
}

double input(){
  double a(0);

  std::cin >> a;

  while (!std::cin){

    std::cout<< "User inpur error: Invalid number. Please retry:\n";

    std::cin.clear(); // clear fail flag
    std::cin.ignore(INT_MAX, '\n'); // clear cin buffer

    std::cin >> a;
  }

  return a;
}

void input4(double& a, double& b, double& c, double& d){
  a = input();
  b = input();
  c = input();
  d = input();
}


void sort(double *a, int N){

  int k = 0;

  while(k < N-1){

    for(int j = 0; j < N-1; j++){
      if( a[j] < a[j+1] ) swap( a[j], a[j+1] ); // loop over array, swap if next element is larger
    }

    for(int j = 0; j < N-1; j++){ // check if entries are sorted
      if(a[j] >= a[j + 1]) k++; // If entry is larger than next one, increment k
      else k = 0; //only if all entries are sorted will k reach N-1 and while loop will exit
    }

  }
}

void indexsort(double* a, int* b, int N){

  int k = 0;
  double c[N];

  for(int j = 0; j < N; j++){
    c[j] = a[j]; // work with duplicate array
    b[j] = j; // array of indexes
  }

  while(k < N-1){

    for(int j = 0; j < N-1; j++){
      if( c[j] < c[j+1] ){
	swap( c[j], c[j+1] ); // loop over array, swap if next element is larger
	intswap( b[j] , b[j+1] ); // also swap indexes
      }
    }
    for(int j = 0; j < N-1; j++){ // check if entries are sorted
      if(c[j] >= c[j + 1]) k++; // If entry is larger than next one, increment k
      else k = 0; //only if all entries are sorted will k reach N-1 and while loop will exit
    }
    
  }
}



double Energy(double m, double px, double py, double pz){

  double p = vec3(px, py, pz);

  return sqrt(p*p + m*m);

}

double mean(double* a, int N){

  double sum = 0;

  for(int j = 0; j < N; j++){
    sum = sum +a[j];
  }

  return sum / N;

}

double stdev(double* a, int N){

  double a2[N];

  for(int j = 0; j < N; j++){
    a2[j] = a[j]*a[j];
  }

  double abar = mean( a , N );
  double abar2 = mean( a2 , N);

  return sqrt( abar2 - abar*abar );

}

int countlines(string file){

  int Nlines = 0;
  FileReader f( file);

  if (f.isValid() ){

    
    while( f.nextLine() ){
      Nlines++;
    }
  }
  else std::cout <<"Error: Invaid file";

  return Nlines;
}

// fourvector zboost(fourvector s, double v){

//   double gamma = 1 / sqrt( 1 - v*v );

//   double tprime = gamma * ( s.t - v*s.z );
//   double zprime = gamma * ( s.z - v*s.t ); // calculate co-ordinates in boosted frame

//   s.t = tprime;
//   s.z = zprime;

//   return s;

// }
