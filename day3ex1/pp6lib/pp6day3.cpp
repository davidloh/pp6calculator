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

void day3()
{
  string o;


  while (true){

    std::cout << "\nChoose operation (Enter o for options)\n";
    std::cin >> o;

    if( o == "b") break; // quit

    if( o == "o"){ // list possible operations
      std::cout <<"\nz Boost: zb\nBack: b \n"; 
      continue;
    }

    if(o != "zb"){
      std::cout <<"User input error: Invalid operation\n"; // error message for invalid operation                
    }


    if (o == "zb"){

      double t, x, y, z, v;

      std::cout << "For a 4-vector of the form ( t , x , y , z ), \n\Enter the values of t, x, y, z:\n";
      input4(t , x , y , z);

      std::cout << "Enter the value of the boost in the z direction (c=1):";
      v = input();

      if( abs(v) >=1){
	std::cout << "Error: |v| must be < 1";
	continue;
      }

      zboost(t, x, y, z, v);

      std::cout << "The 4-vector in the boosted frame is ( "<< t<< " , " << x << " , " << y << " , " << z << " )"<< std::endl;

    }

  std::cin.clear();  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }

}
