#include "PP6Day5MassCut.hpp"
#include "PP6Math.hpp"

MassCut::MassCut(const double CutValue, const CutType type)
  :type_(type), CutValue1(CutValue), CutValue2(0)
{}

MassCut::MassCut(const double CutMin, const double CutMax, const CutType type)
  :type_(type), CutValue1(CutMin), CutValue2(CutMax)
{
  // if(CutMin > CutMax){
  //   int s = swap(CutMin, CutMax);
  // }x
}

 bool MassCut::select(const Particle& P){

  if (type_ == Greater){

    if(P.getMassGeV() > CutValue1){
      return true;
    }
    else{
      return false;
    }
  }

  if (type_ == Less){

    if(P.getMassGeV() < CutValue1){
      return true;
    }
    else{
      return false;
    }
  }

  if (type_ == Range){

    if (P.getMassGeV() > CutValue1 && P.getMassGeV() < CutValue2){
      return true;
    }
    else{
      return false;
    }

  }
  else{
    return false;
  }
 }


 std::vector<Particle> MassCut::select(const std::vector<Particle>& Vp ){

  std::vector<Particle> output;

  for(unsigned int j = 0; j < Vp.size(); j++){

    if( type_ == Greater){
      if(Vp[j].getMassGeV() > CutValue1){
	output.push_back(Vp[j]);
      }
    }

    if( type_ == Less){
      if(Vp[j].getMassGeV() < CutValue1){
        output.push_back(Vp[j]);
      }
    }

    if (type_ == Range){
      if (Vp[j].getMassGeV() > CutValue1 && Vp[j].getMassGeV() < CutValue2){
        output.push_back(Vp[j]);
      }
    }

  }

  return output;
}


MassCut::~MassCut() {}
