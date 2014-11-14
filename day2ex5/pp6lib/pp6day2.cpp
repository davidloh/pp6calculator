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

void day2()
{
  double a,b;
  string o;


  while (true){

    std::cout << "\nChoose operation (Enter o for options)\n";
    std::cin >> o;

    if( o == "b") break; // quit

    if( o == "o"){ // list possible operations
      std::cout <<"\nSort: so\nSwap: s\nRandom particle stats: rps\nBack: b \n"; 
      continue;
    }

    if(o != "so" && o != "s" && o != "rps"){
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

       int k = 0;

       while(k < N-1){

	 for(int j = 0; j < N-1; j++){
 	  sort(array[j] , array[j+1] ); // loop over array, swap if next element is larger
 	}

 	for(int j = 0; j < N-1; j++){ // check if entries are sorted
 	  checksort(array[j] ,  array[j + 1], k); 
 	}
       }


       std::cout << "The elements in descending order are: ";
       for(int j = 0; j < N; j++){ 
	 std::cout << array[j] << ", ";
      }

    }

    if (o == "rps"){ // random particle stats

      double px[100], py[100], pz[100], m[100], p[100], E[100], E2[100];

      double sum = 0, sum2 = 0;


      int Eindex[100];

      for(int j = 0; j < 100; j++){

	px[j] = rand()%100;
	py[j] = rand()%100;
	pz[j] = rand()%100;

	m[j] = rand()%100;

	p[j] = vec3( px[j], py[j], pz[j] );

	E[j] = sqrt( p[j]*p[j] + m[j]*m[j] );

	sum = sum + E[j];

	sum2 = sum2 + E[j]*E[j];

	Eindex[j] = j; //index of entry

	E2[j] = E[j]; // remember original entries

      }


      double mean = sum/100;

      double sd = sqrt( sum2/100 - mean*mean );

      int k = 0;

      while(k < 99){

	for(int j = 0; j < 99; j++){
          indexsort( E[j] , E[j+1] , Eindex[j], Eindex[j+1]); // loop over array, swap if next element is larger
        }

        for(int j = 0; j < 99; j++){ // check if entries are sorted
          checksort(E[j] ,  E[j + 1], k);
        }
      }

      std::cout<< "For 100 random momenta and masses,\nThe mean energy is " << mean << "\nThe Standard deviation is "<< sd << "\nThe largest energy is "<< E2[ Eindex[0] ]<<std::endl;

      // print value from original array with index of largest value




    }


  std::cin.clear();  // clear the fail flag
  std::cin.ignore(INT_MAX, '\n'); // clear the cin buffer
  }

}
