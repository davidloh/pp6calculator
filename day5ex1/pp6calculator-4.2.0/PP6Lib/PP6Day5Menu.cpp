// PP6Day5Menu.cpp : Definitions for PP6Day5Menu functions                                                                                                                                                               
#include "PP6Day5Menu.hpp"

// Standard Library                                                                                           
#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>
#include <string>

// Third party                                                                                                
#include "FileReader.hpp"

#include "PP6Particle.hpp"
#include "PP6Day5MassCut.hpp"
#include "PP6Day5Cut.hpp"

int pp6day5_MC(){

  std::vector<Particle> Input;

  FileReader File("particles.dat");

  if (!File.isValid()) {
    std::cerr << "[pp6day5_MC:error] "
              << " is not a valid file"
              << std::endl;
    return 1;
  }
  else{
    
    while(File.nextLine() ){
      Input.push_back( File.getLine<Particle>() );
    }
    
    std::string type;
    double cut1;
    std::cout << "Enter the type of cut to be used: ( >, <, R)" << std::endl;
    std::cin >> type;
    
    if (type != "R"){
      std::cout << "Enter the cut value:" << std::endl;
      std::cin >> cut1;
      

      if(type == ">"){
	MassCut cuts(cut1, Greater);      
	std::vector<Particle> output = cuts.select(Input);
	std::copy (output.begin(), output.end(), std::ostream_iterator<Particle>(std::cout, "\n") );

      }
      if(type == "<"){
	MassCut cuts(cut1, Less);
	std::vector<Particle> output = cuts.select(Input);
	std::copy (output.begin(), output.end(), std::ostream_iterator<Particle>(std::cout, "\n") );
      }
      
    }
    else{
      double cut2;
      std::cout << "Enter the minimum cut value:" << std::endl;
      std::cin >> cut1;
      
      std::cout << "Enter the Maximum cut value:" << std::endl;
      std::cin >> cut2;
      
      int s = 1;
      if(cut1>cut2){
	s = swap(cut1, cut2);
      }

      if (s == 0){
	std::cout << "Warning: maximum value entered is less than minimum value. Values have been swapped" << std::endl;
      }
      
      MassCut cuts(cut1, cut2, Range);
      std::vector<Particle> output = cuts.select(Input);
      std::copy (output.begin(), output.end(), std::ostream_iterator<Particle>(std::cout, "\n") );
    }



  }
  return 0;
}



void pp6day5_menu() {

  double resultCode(0);
  char op('\0');
  
  while (true)
    {
      // Ask the user what they want to do                                                                      
      std::cout << "PP6Calculator - Day 4 Menu" << std::endl;
      std::cout << "==========================" << std::endl;
      std::cout << "Enter the operation you would like to perform:" << std::endl;
      std::cout << "1)  Data mass cut" << std::endl;
      std::cout << "q)  Quit" << std::endl;
      std::cout << ">> ";

      std::cin >> op;

      // check for bad input                                                                                    
      if(!std::cin)
	{
	  std::cerr << "[error] Error in input" << std::endl;

	  // clear the buffer                                                                                     
	  std::cin.clear();
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  continue;
	}

      // Handle menu operation                                                                                  
      if (op == 'q')
	{
	  break;
	}
      else if (op == '1')
	{
	  resultCode = pp6day5_MC();
	}
      else
	{
	  std::cerr << "[error] Operation '" << op << "' not recognised."
		    << std::endl;
	  continue;
	}

      // Handle any errors                                                                                      
      if (resultCode)
	{
	  std::cerr << "[error] Operation '" << op
		    << "' returned a non-zero code '" << resultCode
		    << "'. Please check parameters."
		    << std::endl;
	  resultCode = 0;
	  continue;
	}



    }  
}
