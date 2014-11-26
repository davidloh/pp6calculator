#include <string>
#include <map>

#ifndef PARTICLEINFO_HPP
#define PARTICLEINFO_HPP

using std::string;

class ParticleInfo{
public:

  ParticleInfo(string file_);

  int getPDGcode(string name);
  int getCharge(int& pid);
  string getName(int& pid); 
  double getMass(int& pid);


private:

  ParticleInfo(const ParticleInfo& rhs);
  ParticleInfo operator=(const ParticleInfo& rhs);

  typedef std::map<string, int> Name_IDcont;
  typedef std::map<int, int> Charge_IDcont;
  typedef std::map<double, int> Mass_IDcont;
  typedef std::map<int, string> ID_Namecont;

  Name_IDcont NameIDs;
  Charge_IDcont ChargeIDs;
  Mass_IDcont MassIDs;
  ID_Namecont IDNames;

  void compute_pdg();

  string file;

};


#endif
