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


      double px[N], py[N], pz[N], m[N], E[N], E2[N];

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

      FileReader f( filename );


      double Mmu = 0.105658;

      // Only process if the file is open/valid
      if (f.isValid()) {

	f.nextLine(); // skip the line of titles


        int Event[1000];
        string Name[1000];
        double px[1000], py[1000], pz[1000], E[1000];

	// Loop until out of lines
	for (int j = 0; f.nextLine() ; j++) {

	  Event[j] = f.getFieldAsInt(1);

	  Name[j] = f.getFieldAsString(2);
	  
	  px[j] = f.getFieldAsDouble(3);
          py[j] = f.getFieldAsDouble(4);
          pz[j] = f.getFieldAsDouble(5);

	  E[j] = Energy( Mmu, px[j] , py[j] , pz[j]); //assume all particles have muon mass

	  // Check that input is o.k.
	  if (f.inputFailed()){
	    std::cout <<"Error: Invalid input";
	    break;
	  }
	}
      

	int Np = 0, Nmup = 0, Nmum = 0; 
	
	//count pairs
	
	for (int j = 0; j < 1000; j++){ // loop over all mu+
	  if(Name[j] != "mu+") continue; 
	  Nmup++;
	  
	  for (int i = 0; i < 1000; i++){ // loop over all mu-
	    if(Name[i] != "mu-") continue;
	    Np++;
	  }
	}
	
	Nmum = Np / Nmup; // Nmuons * Nantimuons = Npairs
	
	std::cout<<"\nNumber of muons = " << Nmum <<"\nNumber of antimuons = " << Nmup <<"\nNumber of pairs = " << Np << std::endl;
	//output numbers of particles and pairs
	
	double invmass[Np];

	int mupindex[Np], mumindex[Np], massindex[Np];
	
	int l = 0;
	
	// calculate invariant masses
	for (int j = 0; j < 1000; j++){ // loop over all mu+
	  if(Name[j] != "mu+") continue;
	  
	  for (int i = 0; i < 1000; i++){ // loop over all mu-
	    if(Name[i] != "mu-") continue;
	    
	    
	    invmass[l] = mass( E[i], px[i], py[i], pz[i], E[j], px[j], py[j], pz[j] );
	    
	    mupindex[l] = j;
	    mumindex[l] = i; // index of original muon/antimuon event

	    l++;
	  }
	}

	// Sort Masses
	indexsort( invmass, massindex, Np );
	
	
	std::cout << "\nThe 10 highest masses are:\n";

	for(int j = 0; j < 10; j++){
	  std::cout << invmass[ massindex[j] ] << " (Events "<< Event[ mupindex[ massindex[j] ] ] << " and "<< Event[ mumindex[ massindex[j] ] ] <<")"<<std::endl;
	}


      }
      else std::cout <<"Error: Invaid file";

    }

  std::cin.clear();  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }

}
