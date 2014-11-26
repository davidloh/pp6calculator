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
#include "FileReader.hpp"
#include "particle.hpp"
#include "ParticleInfo.hpp"

void day2()
{
  double a,b;
  string o;


  while (true){

    std::cout << "\nChoose operation (Enter o for options)\n";
    std::cin >> o;

    if( o == "b") break; // quit

    if( o == "o"){ // list possible operations
      std::cout <<"\nSort: so\nSwap: s\nRandom particle stats: rps\nMuonAnalysis: mu\nBack: b \n"; 
      continue;
    }

    if(o != "so" && o != "s" && o != "rps" && o != "mu"){
      std::cout <<"User input error: Invalid operation\n"; // error message for invalid operation                
    }

    if (o == "s"){ // swap
      
      std::cout <<"\nEnter the value of a:\n";
      a = input();

      std::cout << "\nEnter the value of b:\n";
      b = input();
      
      swap( a , b );
      std::cout << "\nThe value of a is now " << a << "\nThe value of b is now " << b << std::endl;
    }


    if(o == "so"){ // Sorting Algorithm

      int N = 0;

      std::cout <<"\nEnter the number of elements:\n";
      N = input();

      double array[N]; 

      for(int j = 0; j < N; j++){// loop over j to input elements
	
	std::cout << "Enter element " << j+1 <<":"<<std::endl;
	array[j] = input();
      }

      sort(array, N);

       std::cout << "The elements in descending order are: ";
       for(int j = 0; j < N; j++){ 
	 std::cout << array[j] << ", ";
      }

    }

    if (o == "rps"){ // random particle stats

      int N = 0;

      std::cout<<"\nEnter Number of particles: ";

      N = input();


      double px[N], py[N], pz[N], m[N], E[N];

      int Eindex[N];

      for(int j = 0; j < N; j++){

	px[j] = rand()%100;
	py[j] = rand()%100;
	pz[j] = rand()%100;

	m[j] = rand()%100;

	E[j] = Energy( m[j], px[j], py[j], pz[j] );

      }


      double Ebar = mean( E , N);

      double sd = stdev( E , N );

      indexsort(E, Eindex, N);


      std::cout<< "\nFor " <<N<<" random momenta and masses,\nThe mean energy is " << Ebar << "\nThe Standard deviation is "<< sd << "\nThe largest energy is "<< E[ Eindex[0] ]<<std::endl;

      // print value from original array with index of largest value


    }


    if (o == "mu"){ // muon analysis

      string filename;

      std::cout <<"\nEnter the input file to be analysed:\n";
      std::cin >> filename;

      // for faster testing, use
      // filename = "observedparticles.dat";

      FileReader f( filename );

      int Nentries;

      // Only process if the file is open/valid
      if (f.isValid()) {

	f.nextLine(); // skip the line of titles

	Nentries = countlines( filename ) -1; // subtract line of titles

	std::cout <<"\nNumber of entries: "<< Nentries << std::endl;

        int Event[Nentries];
        string run[Nentries];
       

	particle P_[Nentries];

	ParticleInfo PDG("pdg.dat"); //database of particles

	// Loop until out of lines
	for (int j = 0; f.nextLine() ; j++) {

	  Event[j] = f.getFieldAsInt(1);	  

	  //get particle name, lookup PDG code, set PDGcode
	  P_[j].setpdgcode( PDG.getPDGcode( f.getField<string>(2) ) );

	  P_[j].setpx( f.getField<double>(3) );
          P_[j].setpy( f.getField<double>(4) );
          P_[j].setpz( f.getField<double>(5) );

	  run[j] = f.getField<string>(6);

	  // Check that input is o.k.
	  if (f.inputFailed()){
	    std::cout <<"Error: Invalid input";
	    break;
	  }
	}

	// find code for muons
	int mucode = PDG.getPDGcode("mu-");
      
	std::cout<<"\nEvents containing muons/anti-muons in run4.dat:\n";
	for(int j = 0; j < Nentries; j++){
	  if( run[j] != "run4.dat") continue;
	  if (P_[j].getpdgcode() == -mucode || P_[j].getpdgcode() == mucode){
	    std::cout<<Event[j]<<", ";
	  }

	}

	int Nmum = 0, Nmup = 0; 
       
	//count pairs in run4.dat
	
	for (int j = 0; j < Nentries; j++){ // loop over all entries
	  if(run[j] != "run4.dat") continue;
	  else{
	    if(P_[j].getpdgcode() == -mucode){
	      Nmup++;
	    }
	    if(P_[j].getpdgcode() == mucode){
	      Nmum++;
	    }
	  }
	}
	
	
	int Np = Nmum * Nmup;
	
	std::cout<<"\n\nIn run4.dat:\nNumber of muons = " << Nmum <<"\nNumber of antimuons = " << Nmup <<"\nNumber of pairs = " << Np << std::endl;
	//output numbers of particles and pairs
	
	double imass[Np];
	int mupindex[Np], mumindex[Np], massindex[Np];
	int l = 0;
	
	// calculate invariant masses
	for (int j = 0; j < Nentries; j++){ // loop over all mu+
	  if(run[j] != "run4.dat" ||P_[j].getpdgcode() != -mucode) continue;

	  for (int i = 0; i < Nentries; i++){ // loop over all mu-
	    if(P_[i].getpdgcode() != mucode || run[i] != "run4.dat") continue;
	    
	    imass[l] = invmass(P_[i] , P_[j]);
	    
	    mupindex[l] = j;
	    mumindex[l] = i; // index of original muon/antimuon event
	
	    l++;
	  }
	}
	
	// Sort Masses
	indexsort( imass, massindex, Np );
	
	
	std::cout << "\nThe 10 highest masses are:\n";

	for(int j = 0; j < 10; j++){
	  std::cout << imass[ massindex[j] ] << " (Events "<< Event[ mupindex[ massindex[j] ] ] << " and "<< Event[ mumindex[ massindex[j] ] ] <<")"<<std::endl;
	}


      }
      else std::cout <<"Error: Invaid file";

    }

  std::cin.clear();  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }

}
