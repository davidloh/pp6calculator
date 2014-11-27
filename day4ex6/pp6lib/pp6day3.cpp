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
      std::cout <<"\nz Boost: zb\nlength: l\nAdd 4-vectors: +\nSubtract 4-vectors: -\nBack: b \n"; 
      continue;
    }

    if(o != "zb" && o != "l" && o != "+" && o != "-"){
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

      fourvector s(t,x,y,z);


      s.zboost(v);      


      std::cout << "The 4-vector in the boosted frame is "<<(s);

    }

    if (o == "l"){

      double t, x, y, z, l;

      std::cout << "For a 4-vector of the form ( t , x , y , z ), \nEnter the values of t, x, y, z:\n";
      input4(t , x , y , z);

      fourvector s(t,x,y,z);
      

      if( s.get4vtype() == timelike){
 	l = sqrt( s.getinterval() );
 	std::cout << "The length of the (time-like) 4-vector is " << l << std::endl;
      }

      if( s.get4vtype() == spacelike){
 	l = sqrt( - s.getinterval() );
 	std::cout << "The length of the (space-like) 4-vector is " << l << std::endl;
      }

      if( s.get4vtype() == null){
 	std::cout << "The length of the (null) 4-vector is 0" << std::endl;
      }
      //destroy4v(s);

    }

    if (o == "+" || o == "-"){

      double t1,t2,x1,x2,y1,y2,z1,z2;

      std::cout << "For 2 4-vectors of the form ( t , x , y , z ), \nEnter the values of t1, x1, y1, z1:\n";
      input4(t1 , x1 , y1 , z1);

      fourvector s1(t1,x1,y1,z1);

      std::cout << "Enter the values of t2, x2, y2, z2\n";
      
      input4(t2 , x2 , y2 , z2);

      fourvector s2(t2,x2,y2,z2);

    }



  std::cin.clear();  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }

}

