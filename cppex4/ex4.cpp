#include <iostream>
#include <string>
#include <climits> 

using namespace std;

int main()
{

  double a,b,c;
  string o;
  int i = 0;


  while (i == 0){

    std::cout << "Enter the value of a:\n";
    std::cin >> a;
    
    if(!std::cin){
      std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables  
    }
      
    std::cout << "Enter the value of b:\n";
    std::cin >> b;
      
    if(!std::cin){
      std::cout <<"User input error: Invalid number\n"; // error message for invalid input variables                                       
    }
    
    std::cout << "Choose operation (+, -, *, / )\n";
    std::cin >> o;
	

    if(o == "q") break;
  

    if(o != "+" && o != "-" && o != "*" && o != "/"){
      std::cout <<"User input error: Invalid operation\n"; // error message for invalid operation                                           
    }


    if(o == "+"){ //Addition
      c = a + b;
      std::cout << "The value of a + b is " << c << std::endl;
    }
	
    if(o == "-"){ //Subtraction                                       
      c = a - b;
      std::cout << "The value of a - b is " << c << std::endl;
    }
    
    if(o == "*"){ //Multiplication                                    
      c = a * b;
      std::cout << "The value of a * b is " << c << std::endl;
    }
    
    if(o == "/"){ //Division                                          
      c = a / b;
      std::cout << "The value of a / b is " << c << std::endl;
    }
	

  std::cin.clear();
  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }
  return 0;
}
