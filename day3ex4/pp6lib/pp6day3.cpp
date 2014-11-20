#include <iostream>
#include <string>
#include <climits> 
#include <cmath>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;


#include "pp6math.hpp"
#include "fourvector.hpp"


void day3()
{
  string o;


  while (true){

    std::cout << "\nChoose operation (Enter o for options)\n";
    std::cin >> o;

    if( o == "b") break; // quit

    if( o == "o"){ // list possible operations
      std::cout <<"\nz Boost: zb\nlength: l\nBack: b \n"; 
      continue;
    }

    if(o != "zb" && o != "l"){
      std::cout <<"User input error: Invalid operation\n"; // error message for invalid operation                
    }


    if (o == "zb"){

      double t, x, y, z, v;

      std::cout << "For a 4-vector of the form ( t , x , y , z ), \nEnter the values of t, x, y, z:\n";
      input4(t , x , y , z);

      while(true){
	std::cout << "Enter the value of the boost in the z direction (c=1):\n";
	v = input();

	if( abs(v) >=1){
	  std::cout << "Error: |v| must be < 1\n";
	}
	else break;
	
      }

      fourvector *s;
      s = create4v(t,x,y,z);


      s->zboost(v);      

      t = return4vt(s);
      z = return4vz(s);

      std::cout << "The 4-vector in the boosted frame is ( "<< t << " , " << x << " , " << y << " , " << z << " )"<< std::endl;

      destroy4v(s);

    }

    if (o == "l"){

      double t, x, y, z, l;

      std::cout << "For a 4-vector of the form ( t , x , y , z ), \nEnter the values of t, x, y, z:\n";
      input4(t , x , y , z);

      fourvector *s;
      s = create4v(t,x,y,z);

      if( get4vtype(s) == timelike){
	l = sqrt( s->length() );
	std::cout << "The length of the (time-like) 4-vector is " << l << std::endl;
      }

      if( get4vtype(s) == spacelike){
	l = sqrt( - s->length() );
	std::cout << "The length of the (space-like) 4-vector is " << l << std::endl;
      }

      if( get4vtype(s) == null){
	std::cout << "The length of the (null) 4-vector is 0" << std::endl;
      }
    }

   

  std::cin.clear();  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }

}

