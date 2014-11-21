#include <iostream>
#include <string>
#include <climits>

using std::cout;
using std::cin;
using std::string;

#include "pp6day1.hpp"
#include "pp6day2.hpp"
#include "pp6day3.hpp"

int main()
{

  string o;

  while (true){

    std::cout << "\nChoose day of implementation (Enter o for options)\n";
    std::cin >> o;

    if ( o == "q" ) break; // quit

    if ( o == "o"){ // list possible operations
      std::cout << "\nDay 1: 1\nDay 2: 2\nDay 3: 3\nQuit: q\n";
      continue;
    }
    if ( o != "o" && o != "1" && o != "2" && o!= "3")  std::cout << "User input error: Invalid day";
    

    if (o == "1") day1();
    if (o == "2") day2();
    if (o == "3") day3();

  }


}
