#include <iostream>
#include <string>
#include <climits> 
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>

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
      std::cout <<"\nOutput PDG data: pdg\nRandom vector stats: rv\nBack: b \n"; 
      continue;
    }

    if(o != "pdg" && o != "rv"){
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

        // Nentries = countlines( filename );

	// std::cout <<"\nNumber of entries: "<< Nentries <<"\n"<< std::endl;

	std::vector<double> mass;
	std::vector<string> name;
	std::vector<int> pid, charge;

	for(int j = 0; f.nextLine(); j++){

	  name.push_back( f.getField<string>(1) );
	  pid.push_back( f.getField<int>(2) );
	  charge.push_back( f.getField<int>(3) );
	  mass.push_back( f.getField<double>(4) );
	
	  //	 std::cout<< name[j] <<"\t"<< pid[j]<<"\t"<<charge[j]<<"\t"<<mass[j]<<std::endl;
	}	
      
	std::vector<string>::iterator iter = name.begin();
	std::vector<string>::iterator nameEnd = name.end();


	std::cout<<"\nNames:\n";
	for(;iter != nameEnd; ++iter){

	  std::cout<< *iter << std::endl;
	}

	Nentries = name.size();

	std::cout <<"\nNumber of entries: "<< Nentries <<"\n"<< std::endl; 

      }
      else std::cout <<"Error: Invaid file";
    }

    if(o == "rv"){
     


      std::vector<int> vec10(10);
      std::generate (vec10.begin(), vec10.end(), randint );

      std::cout<<"\nVector contains: \n";
      std::copy (vec10.begin(), vec10.end(), std::ostream_iterator<int>(std::cout, "\n") );
      
      std::cout<<"\nLargest element: "<< *std::max_element( vec10.begin() , vec10.end() );
      std::cout<<"\nSmallest element:"<< *std::min_element( vec10.begin() , vec10.end() );


      std::sort (vec10.begin(), vec10.end());
      std::cout<<"\n\nSorted vector:\n";
      std::copy (vec10.begin(), vec10.end(), std::ostream_iterator<int>(std::cout, "\n") );
      

      


    }

  std::cin.clear();  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }

}

