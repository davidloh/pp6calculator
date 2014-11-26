#include "ParticleInfo.hpp"
#include <map>
#include "FileReader.hpp"
#include <string>
#include "pp6math.hpp"

using std::string;

ParticleInfo::ParticleInfo(string file_)
  :file(file_)
{
  compute_pdg();
}

void ParticleInfo::compute_pdg(){

  FileReader f( file );

  //int Nentries = countlines( file );

  // Only process if the file is open/valid   

  if (f.isValid()) {

    for(int j = 0; f.nextLine(); j++){

      NameIDs[ f.getField<string>(1) ] = f.getField<int>(2);
      ChargeIDs[ f.getField<int>(3) ] = f.getField<int>(2);
      MassIDs[ f.getField<double>(4) ] = f.getField<int>(2);
      IDNames[ f.getField<int>(2) ] = f.getField<string>(1);

    }
  }
    else std::cout <<"Error: Invaid file";
}

int ParticleInfo::getPDGcode(string name){
  
  Name_IDcont::iterator p = NameIDs.find( name );
  
  if(p != NameIDs.end() ){
    return (*p).second;    
  }
  else {
    return 0;
  }
}
  

int ParticleInfo::getCharge(int& pid){

  Charge_IDcont::iterator p = ChargeIDs.find( pid );

  if(p != ChargeIDs.end() ){
    return (*p).second;
  }
  else {
    return 0;
  }
}

string ParticleInfo::getName(int& pid){

  ID_Namecont::iterator p = IDNames.find( pid );

  if(p != IDNames.end() ){
    return (*p).second;
  }
  else {
    return 0;
  }
}


double ParticleInfo::getMass(int& pid){

  Mass_IDcont::iterator p = MassIDs.find( pid );

  if(p != MassIDs.end() ){
    return (*p).second;
  }
  else {
    return 0;
  }
}

