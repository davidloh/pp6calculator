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
#include "particle.hpp"
#include "ParticleInfo.hpp"

void day4()
{
  string o;


  while (true){

    std::cout << "\nChoose operation (Enter o for options)\n";
    std::cin >> o;

    if( o == "b") break; // quit

    if( o == "o"){ // list possible operations
      std::cout <<"\nOutput PDG data: pdg\nRandom vector stats: rv\nMuon Analysis: mu\nBack: b \n"; 
      continue;
    }

    if(o != "pdg" && o != "rv" && o != "mu"){
      std::cout <<"User input error: Invalid operation\n"; // error message for invalid operation                
    }


    if (o == "pdg"){

      string filename;

      std::cout <<"\nEnter the input file to be analysed:\n";
      std::cin >> filename;

      //for faster testing, use
      //filename = pdg.dat

      FileReader f( filename );

                                       
      int Nentries;

      // Only process if the file is open/valid                      
      if (f.isValid()) {     

        
	std::vector<double> mass;
	std::vector<string> name;
	std::vector<int> pid, charge;

	for(int j = 0; f.nextLine(); j++){

	  name.push_back( f.getField<string>(1) );
	  pid.push_back( f.getField<int>(2) );
	  charge.push_back( f.getField<int>(3) );
	  mass.push_back( f.getField<double>(4) );
	
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

    if( o == "mu"){

      string filename;

      std::cout <<"\nEnter the input file to be analysed:\n";
      std::cin >> filename;

      // for faster testing, use
      // filename = "observedparticles.dat";

      FileReader f( filename );
      int Nentries;

      // Only process if the file is open/valid
      if (f.isValid()) {

        Nentries = countlines( filename ) -1; // subtract line of titles

	std::cout <<"\nNumber of entries: "<< Nentries << std::endl;

	std::vector<int> Event;
	std::vector<string> run;
	std::vector<particle> P_;

        ParticleInfo PDG("pdg.dat"); //database of particles

        f.nextLine(); // skip the line of titles

	// Loop until out of lines
        for (int j = 0; f.nextLine() ; j++) {

          Event.push_back( f.getField<int>(1) );

          particle inputP; //new particle class to enter data into

          //get particle name, lookup PDG code, set PDGcode
          inputP.setpdgcode( PDG.getPDGcode( f.getField<string>(2) ) );

          inputP.setpx( f.getField<double>(3) );
          inputP.setpy( f.getField<double>(4) );
          inputP.setpz( f.getField<double>(5) );

          P_.push_back( inputP );

          run.push_back( f.getField<string>(6) );

          // Check that input is o.k.
          if (f.inputFailed()){
	    std::cout <<"Error: Invalid input";
            break;
          }
        }

        // find code for muons
        int mucode = PDG.getPDGcode("mu-");

	std::vector<double> imass;

        // calculate invariant masses
        for (int j = 0; j < Nentries; j++){ // loop over all mu+
          if(run[j] != "run4.dat" || P_[j].getpdgcode() != -mucode) continue;

          for (int i = 0; i < Nentries; i++){ // loop over all mu-
            if(run[i] != "run4.dat" || P_[i].getpdgcode() != mucode) continue;

            imass.push_back( invmass(P_[i] , P_[j]) );

          }
        }

        // Sort Masses
	std::sort( imass.begin(), imass.end() );
	std::reverse( imass.begin(), imass.end() ); // sort in ascending order then reverse

	std::cout << "\nThe 10 highest masses are:\n";
	std::copy(imass.begin(), imass.begin()+10,  std::ostream_iterator<double>(std::cout, "\n"));

      }
    }

  std::cin.clear();  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }

}

