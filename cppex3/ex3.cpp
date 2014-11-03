#include <iostream>
#include <string>

using namespace std;

int main()
{

  double a,b,c;
  string o;

  std::cout << "Enter the value of a:\n";
  std::cin >> a;

  std::cout << "Enter the value of b:\n";
  std::cin >> b;
  std::cout << "Choose operation (+, -, *, / )\n";

  std::cin >> o;

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

  if(o != "+" && o != "-" && o != "*" && o != "/"){
    std::cout <<"User input error: Invalid operation\n"; // error message for invalid operation
  }

  if(!std::cin){
    std::cout <<"User input error: Invalid number\n"; // error messsage for invalid input variables
  }

  return 0;
}
