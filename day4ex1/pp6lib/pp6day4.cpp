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
#include "FileReader.hpp"

void day4()
{
  string o;


  while (true){

    std::cout << "\nChoose operation (Enter o for options)\n";
    std::cin >> o;

    if( o == "b") break; // quit

    if( o == "o"){ // list possible operations
      std::cout <<"\nOutput PDG data: pdg\nBack: b \n"; 
      continue;
    }

    if(o != "pdg"){
      std::cout <<"User input error: Invalid operation\n"; // error message for invalid operation                
    }


    if (o == "pdg"){

      string filename;

      std::cout <<"\nEnter the input file to be analysed:\n";
      std::cin >> filename;

      FileReader f( filename );

                                       
      int Nentries;

      // Only process if the file is open/valid                      
      if (f.isValid()) {     

        Nentries = countlines( filename );

	std::cout <<"\nNumber of entries: "<< Nentries <<"\n"<< std::endl;

	double mass[Nentries];
	string name[Nentries];
	int pid[Nentries], charge[Nentries];

	for(int j = 0; f.nextLine(); j++){

	  name[j] = f.getField<string>(1);
	  pid[j] = f.getField<int>(2);
	  charge[j] = f.getField<int>(3);
	  mass[j] = f.getField<double>(4);

	  std::cout<< name[j] <<"\t"<< pid[j]<<"\t"<<charge[j]<<"\t"<<mass[j]<<std::endl;
	}


      }
      else std::cout <<"Error: Invaid file";
    }


   

  std::cin.clear();  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }

}

