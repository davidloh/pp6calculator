#ifndef PARTICLEINFO_HPP
#define PARTICLEINFO_HPP

class ParticleInfo{
public:

  ParticleInfo(string& name);

  int getPDGcode(string& name);
  int getCharge(int pid);
  string getName(int pid); 
  double getMass(int pid);


private:

  ParticleInfo(const ParticleInfo& rhs);
  ParticleInfo operator=(const ParticleInfo& rhs)

}


#endif
