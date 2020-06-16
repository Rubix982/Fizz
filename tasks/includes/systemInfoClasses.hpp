#ifndef __SYSTEM_INFO_CLASSES
#define __SYSTEM_INFO_CLASSES

#include <string>

class hardwareInfo {
  // Contains the stacer and hardware info

  std::string hostname;
  std::string distribution;
  std::string platform;    // the platform
  std::string cpuModel;    // the cpu model
  std::string releaseType; // The release type
  int cpuCores;            // the number of cpu cores
  float cpuSpeed;          // the cpu speed

  //! default information
  void setDefaultValues(void);

  //! resolution for the default values
  void resolveHostname(void);
  void resolveDistribution(void);
  void resolvePlatform(void);
  void resolveCPUModel(void);
  void resolveReleaseType(void);
  void resolveCPUCores(void);
  void resolveCPUSpeed(void);

public:

  //! constructor
  hardwareInfo();

  //! getters
  std::string getHostname() const;
  std::string getDistribution() const;
  std::string getPlatform() const;
  std::string getCPUModel() const;
  std::string getReleaseType() const;
  int getCPUcores() const;
  float getCPUSeed() const;

  //! setters
  void setHostname(std::string &const hostname);
  void setDistribution(std::string &const distribution);
  void setPlatform(std::string &const platform);
  void setCPUModel(std::string &const cpuModel);
  void setReleaseType(std::string &const releaseType);
  void setCPUcores(int &const cpuCores);
  void setCPUSeed(float &const cpuSpeed);
};

class kernelInfo {

  std::string kernelName;       //! kernel name
  std::string nodeName;         //! nodename
  std::string kernelRelease;    //! Kernel release
  std::string kernelVersion;    //! kernel version
  std::string machine;          //! machine
  std::string processor;        //! processor
  std::string operatingSystem;  //! the operating system

  //! default information
  void setDefaultValues(void);

  //! find resolutions for the default values
  void resolveKernelName(void);
  void resolveNodeName(void);
  void resolveKernelRelease(void);
  void resolveKernelVersion(void);
  void resolveMachine(void);
  void resolveProcessor(void);
  void resolveOperatingSystem(void);

public:
  //! constructors
  kernelInfo() {}

  // getters
  std::string getKernelName(void) const;
  std::string getNodename(void) const;
  std::string getKernelRelease(void) const;
  std::string getKernelVersion(void) const;
  std::string getMachine(void) const;
  std::string getProcessor(void) const;
  std::string getOperatingSystem(void) const;

  //! setters
  void setKernelName(std::string &const kernelName);
  void setNodename(std::string &const nodeName);
  void setKernelRelease(std::string &const kernelRelease);
  void setKernelVersion(std::string &const kernelVersion);
  void setMachine(std::string &const machine);
  void setProcessor(std::string &const processor);
  void setOperatingSystem(std::string &const operatingSystem);

  //! default information
};

#endif