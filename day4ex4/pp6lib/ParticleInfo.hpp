#ifndef PARTICLEINFO_HPP
#define PARTICLEINFO_HPP

class ParticleInfo{
public:

  ParticleInfo(string& name_);

  int getPDGcode(string& name);
  int getCharge(int pid);
  string getName(int pid); 
  double getMass(int pid);


private:

  ParticleInfo(const ParticleInfo& rhs);
  ParticleInfo operator=(const ParticleInfo& rhs);

  typedef std::map<string, int> Name_IDcont;
  Name_IDcont NameIDs;

  typedef std::map<int, int> Charge_IDcont;
  Charge_IDcont ChargeIDs;

  typedef std::map<double, int> Mass_IDcont;
  Mass_IDcont MassIDs;

  typedef std::map<int, string> ID_Namecont;
  ID_Namecont IDNames;



}


#endif
