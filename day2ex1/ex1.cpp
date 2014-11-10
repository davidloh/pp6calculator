#include <iostream>
#include <string>
#include <climits> 
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;


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

double swap(double& a, double& b){
  double c = a; // remember the value of "a" before asigning "b" to it
  a = b;
  b = c;
}

double line(double m, double c){
  return  - c / m;
}

double quadp(double a, double b, double c){
  return ( -b + sqrt( b*b -4*a*c) )/ (2*a);
}  
double quadm(double a, double b, double c){
  return ( -b - sqrt( b*b -4*a*c) )/ (2*a);
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

  

int main()
{

  double a,b,c,d,e,a2,b2,c2,d2;
  string o;
  int i = 0;


  while (i == 0){

    std::cout << "\nChoose operation (Enter o for options)\n";
    std::cin >> o;

    if( o == "q") break; // quit

    if( o == "o"){ // list possible operations
      std::cout <<"\nAddition: + \nSubtraction: - \nMultiplication: * \nDivision: /\nSwap: s  \nx intercept: xi \nQuadratic Equation: qe\n3 Vector: 3v\n4 Vector: 4v\nInvariant Mass: im\nQuit: q \n"; 
      continue;
    }

    if(o != "+" && o != "-" && o != "*" && o != "/" && o != "o" && o != "xi" && o != "qe" && o != "3v" && o != "4v" && o != "im" && o != "s"){
      std::cout <<"User input error: Invalid operation\n"; // error message for invalid operation                
    }


    if(o == "+" || o == "-" || o == "*" || o == "/" || o == "s"){ // enter a and b if user chooses a binary operation
      
      std::cout <<"\nEnter the value of a:\n";
      std::cin >> a;
    
      if(!std::cin){
	std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables  

	std::cin.clear();  // clear the fail flag
	std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
	
	continue;
      }
      
      std::cout << "\nEnter the value of b:\n";
      std::cin >> b;
      
      if(!std::cin){
	std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables    
	
	std::cin.clear();  // clear the fail flag
	std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

	continue;      
      }
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
      c = div( a , b );
      std::cout << "\nThe value of a / b is " << c << std::endl;
    }

    if (o == "s"){ // swap

      swap( a , b );
      std::cout << "\nThe value of a is now " << a << "\nThe value of b is now " << b << std::endl;
    }

    if (o == "xi"){ // line intercept
	std::cout << "For a line of the form y = mx + c,\nEnter the value of m:\n";
	std::cin >> a;

	if(!std::cin){
	  std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables

	  std::cin.clear();  // clear the fail flag
	  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

	  continue;
	}

	std::cout << "\nEnter the value of c:\n";
	std::cin >> b;

	if(!std::cin){
	  std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables

	  std::cin.clear();  // clear the fail flag
	  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

	  continue;
	}

	c = line( a , b );
	std:: cout << "\nThe value of the x intercept is " << c << std::endl;
      }

    if(o == "qe"){ // quadratic equation
      std::cout <<"For a quadratic equation of the form ax^2 + bx + c = 0,\nEnter the value of a:\n";
      std::cin >> a;

      if(!std::cin){
	std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables

	std::cin.clear();  // clear the fail flag
	std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

        continue;
      }

      std::cout << "\nEnter the value of b:\n";
      std::cin >> b;


      if(!std::cin){
	std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables

	std::cin.clear();  // clear the fail flag
	std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

        continue;
      }

      std::cout << "\nEnter the value of c:\n";
      std::cin >> c;


      if(!std::cin){
	std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables

	std::cin.clear();  // clear the fail flag
	std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

        continue;
      }

      double disc = b*b - 4*a*c;
      if( disc >= 0){ // check if solutions are real
	d = quadp( a, b, c);
	e = quadm( a, b, c);

	std::cout << "The values of x are " << d << " and " << e <<std::endl; 
      }
      else std::cout << "Error: solutions are not real";
    }

    if(o == "3v"){ // length of 3 vector
      std::cout <<"For a 3 vector of the form ( a , b , c ),\nEnter the value of a:\n";
      std::cin >> a;

      if(!std::cin){
	std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables

	std::cin.clear();  // clear the fail flag
	std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

        continue;
      }

      std::cout << "\nEnter the value of b:\n";
      std::cin >> b;


      if(!std::cin){
	std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables

	std::cin.clear();  // clear the fail flag
	std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

        continue;
      }

      std::cout << "\nEnter the value of c:\n";
      std::cin >> c;


      if(!std::cin){
	std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables

	std::cin.clear();  // clear the fail flag
	std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

        continue;
      }

        d = vec3( a, b, c);

	std::cout << "The length of the 3 vector is " << d <<std::endl;
    }


    if (o == "4v"){ //4 vector

      std::cout << "For a 4-vector of the form ( t , x , y , z ), \nEnter the values of t, x, y, z:\n";
      std::cin >> a >> b >> c >> d;

      if(!std::cin){
	std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables

	std::cin.clear();  // clear the fail flag
	std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

        continue;
      }

      double e2 = vec4(a,b,c,d);

      if(e2 >= 0){
      
	e = sqrt(e2);
	std::cout << "The length of the 4 vector is " << e << std::endl;

      }
      else std::cout << "Error: length is not real";
    }


    if(o == "im"){ // invariant mass
      std::cout << "For 2 4-vectors of the form ( E , px , py , pz ), \nEnter the values of E1, px1, px1, pz1:\n";
      std::cin >> a >> b >> c >> d;

      if(!std::cin){
	std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables

	std::cin.clear();  // clear the fail flag
	std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

        continue;
      }

      std::cout << "\nEnter the values of E2, px2, py2, pz2:\n";
      std::cin >> a2 >> b2 >> c2 >> d2;

      if(!std::cin){
	std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables

	std::cin.clear();  // clear the fail flag
	std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer

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
  std::cin.clear();  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }
  return 0;
}
