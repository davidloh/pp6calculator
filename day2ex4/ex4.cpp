#include <iostream>
#include <string>
#include <climits> 
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;


#include "pp6math.hpp"

int main()
{

  double a,b,c,d,e,a2,b2,c2,d2;
  string o;
  int N = 0;


  while (true){

    std::cout << "\nChoose operation (Enter o for options)\n";
    std::cin >> o;

    if( o == "q") break; // quit

    if( o == "o"){ // list possible operations
      std::cout <<"\nAddition: + \nSubtraction: - \nMultiplication: * \nDivision: /\nSwap: s  \nx intercept: xi \nQuadratic Equation: qe\n3 Vector: 3v\n4 Vector: 4v\nInvariant Mass: im\nSort: so\nQuit: q \n"; 
      continue;
    }

    if(o != "+" && o != "-" && o != "*" && o != "/" && o != "o" && o != "xi" && o != "qe" && o != "3v" && o != "4v" && o != "im" && o != "s" && o != "so"){
      std::cout <<"User input error: Invalid operation\n"; // error message for invalid operation                
    }


    if(o == "+" || o == "-" || o == "*" || o == "/" || o == "s"){ // enter a and b if user chooses a binary operation
      
      std::cout <<"\nEnter the value of a:\n";
     
      a = input();
      
      std::cout << "\nEnter the value of b:\n";
      b = input();
        
    }
  

    if(o == "+"){ //Addition
      
   c = add ( a , b );
      std::cout << "\nThe value of a + b is " << c << std::endl;
    }
	
    if(o == "-"){ //Subtraction                                       
      c = sub( a , b );
      std::cout << "\nThe value of a - b is " << c << std::endl;
    }

    
    if(o == "*"){ //Multiplication                                    
      c = mult( a , b );
      std::cout << "\nThe value of a * b is " << c << std::endl;
    }
    
    if(o == "/"){ //Division                                          

      if(b == 0){
	std::cout << "Error: division by zero";
	continue;
      }

      c = div( a , b );

      std::cout << "\nThe value of a / b is " << c << std::endl;
    }

    if (o == "s"){ // swap

      swap( a , b );
      std::cout << "\nThe value of a is now " << a << "\nThe value of b is now " << b << std::endl;
    }


    if (o == "xi"){ // line intercept
	std::cout << "For a line of the form y = mx + c,\nEnter the value of m:\n";
	
	a = input ();

	std::cout << "\nEnter the value of c:\n";
	
	b = input ();

	if(a != 0){
	c = line( a , b );
	std:: cout << "\nThe value of the x intercept is " << c << std::endl;
	}
	else std::cout << "Error: This line does not intercept the x axis";

    }


    if(o == "qe"){ // quadratic equation
      std::cout << "For a quadratic equation of the form ax^2 + bx + c = 0,\nEnter the value of a:\n";
      a = input();

      std::cout << "\nEnter the value of b:\n";
      b = input();


      std::cout << "\nEnter the value of c:\n";
      c = input();


      if(quad(a , b , c) == 1){
	if(a == b) std::cout <<"\nThe value of x is " << a << " (Solutions are degenerate)" << std::endl;
	else std::cout << "The values of x are " << a << " and " << b <<std::endl; 
	}
      else std::cout << "Error: solutions are not real";
    }



    if(o == "3v"){ // length of 3 vector
      std::cout <<"For a 3 vector of the form ( a , b , c ),\nEnter the value of a:\n";
      a = input();

      std::cout << "\nEnter the value of b:\n";
      b = input();


      std::cout << "\nEnter the value of c:\n";
      c = input();

      d = vec3( a, b, c);
      
      std::cout << "The length of the 3 vector is " << d <<std::endl;
    }


    if (o == "4v"){ //4 vector

      std::cout << "For a 4-vector of the form ( t , x , y , z ), \nEnter the values of t, x, y, z:\n";
      input4(a , b , c , d);


      double e2 = vec4(a,b,c,d);

      if(e2 >= 0){
      
	e = sqrt(e2);
	std::cout << "The length of the 4 vector is " << e << std::endl;

      }
      else std::cout << "Error: length is not real";
    }


    if(o == "im"){ // invariant mass
      std::cout << "For 2 4-vectors of the form ( E , px , py , pz ), \nEnter the values of E1, px1, px1, pz1:\n";
      input4(a , b , c , d);


      std::cout << "\nEnter the values of E2, px2, py2, pz2:\n";
      input4(a2, b2, c2, d2);


      if( a < 0 || a2 < 0){
	std::cout << "Error: Energies must be positive";
	continue;
      }

      double m1 = vec4(a,b,c,d);
      double m2 = vec4(a2,b2,c2,d2);

      if(m1 >=0 && m2 >=0){ // check masses are real
	e = mass(a,b,c,d,a2,b2,c2,d2);
	std::cout << "The invariant mass is "<< e << std::endl;
      }
      else std::cout << "Error: 1 or more masses are not real";

    }

    if(o == "so"){ // Sorting Algorithm

      std::cout <<"\nEnter the number of elements:\n";
      N = input();

      double array[N]; 

      for(int j = 0; j < N; j++){// loop over j to input elements
	
	std::cout << "Enter element " << j <<":"<<std::endl;
	array[j] = input();
      }

      int k = 0;

      while(k < N-1){

	for(int j = 0; j < N-1; j++){
	  if(array[j] < array[j+1] )  swap (array[j] , array[j+1]); // loop over array, swap if next element is larger
	}

	for(int j = 0; j < N-1; j++){ // check if entries are sorted
	  if(array[j] >=  array[j + 1]) k++; // If entry is larger than next one, increment k
	  else k = 0; // only if all entries are sorted k will reach N-1 and while loop will exit
	  }
      }

      std::cout << "The elements in descending order are: ";
      for(int j = 0; j < N; j++){ 
	std::cout << array[j] << ", ";
      }

    }


  std::cin.clear();  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }
  return 0;
}
