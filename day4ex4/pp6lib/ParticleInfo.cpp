#include "ParticleInfo.hpp"
#include <map>
#include "FileReader.hpp"
#include <string>

ParticleInfo::ParticleInfo(string name_)
  :name(name_)
{

  FileReader f( pdg.dat );

  int Nentries;

  // Only process if the file is open/valid                                                                     
  if (f.isValid()) {
   
    for(int j = 0; f.nextLine(); j++){
      
      NameIDs[ f.getField<string>(1) ] = f.getField<int>(2);
      
      ChargeIDs[ f.getField<int>(3) ] = f.getField<int>(2);
      
      MassIDs[ f.getField<double>(4) ] = f.getField<int>(2);
      
      IDNames[ f.getField<int>(2) ] = f.getField<string>(1);      
                                         
    }
    else std::cout <<"Error: Invaid file";
    
  }
  

}

int ParticleInfo::getPDGcode(string& name){
  
  Name_IDcont::iterator p = NameIDs.find( name );
  
  if(p != NameIDs.end() ){
    return (*p).second;    
  }
  else {
    return 0;
  }
}
  

int ParticleInfo::getCharge(int pid){

  Charge_IDcont::iterator p = ChargeIDs.find( pid );

  if(p != ChargeIDs.end() ){
    return (*p).second;
  }
  else {
    return 0;
  }
}

string ParticleInfo::getName(int pid){

  Name_IDcont::iterator p = NameIDs.find( pid );

  if(p != NameIDs.end() ){
    return (*p).second;
  }
  else {
    return 0;
  }
}


string ParticleInfo::getMass(int pid){

  Mass_IDcont::iterator p = MassIDs.find( pid );

  if(p != MassIDs.end() ){
    return (*p).second;
  }
  else {
    return 0;
  }
}

