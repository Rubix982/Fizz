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

public:
  hardwareInfo() : cpuCores(0), cpuSpeed(0.0f) {}

  // getters
  std::string getHostname() const { return hostname; }
  std::string getDistribution() const { return distribution; }
  std::string getPlatform() const { return platform; }
  std::string getCPUModel() const { return cpuModel; }
  std::string getReleaseType() const { return releaseType; }

  int getCPUcores() const { return cpuCores; }
  float getCPUSeed() const { return cpuSpeed; }

  // setters
  void setHostname(std::string &const hostname) { this->hostname = hostname; }
  void setDistribution(std::string &const distribution) {
    this->distribution = distribution;
  }
  void setPlatform(std::string &const platform) { this->platform = platform; }
  void setCPUModel(std::string &const cpuModel) { this->cpuModel = cpuModel; }
  void setReleaseType(std::string &const releaseType) {
    this->releaseType = releaseType;
  }

  void setCPUcores(int &const cpuCores) { this->cpuCores = cpuCores; }
  void setCPUSeed(float &const cpuSpeed) { this->cpuSpeed = cpuSpeed; }

  // default information
};

class kernelInfo {

  std::string kernelName;       //! kernel name
  std::string nodeName;         //! nodename
  std::string kernelVersion;    //! kernel version
  std::string machine;          //! machine
  std::string processor;        //! processor
  std::string hardwarePlatform; //! hardware platform
  std::string operatingSystem;  //! the operating system

public:
  kernelInfo() {}

  // getters
  std::string getKernelName(void) const { return kernelName; }

  std::string getNodename(void) const { return nodeName; }

  std::string getKernelVersion(void) const { return kernelVersion; }

  std::string getMachine(void) const { return machine; }

  std::string getProcessor(void) const { return processor; }

  std::string getHardwarePlatform(void) const { return hardwarePlatform; }

  std::string getOperatingSystem(void) const { return operatingSystem; }

  // setters
  void setKernelName(std::string &const kernelName) {
    this->kernelName = kernelName;
  }

  void setNodename(std::string &const nodeName) { this->nodeName = nodeName; }

  void setKernelVersion(std::string &const kernelVersion) {
    this->kernelVersion = kernelVersion;
  }

  void setMachine(std::string &const machine) { this->machine = machine; }

  void setProcessor(std::string &const processor) {
    this->processor = processor;
  }

  void setHardwarePlatform(std::string &const hardwarePlatform) {
    this->hardwarePlatform = hardwarePlatform;
  }

  void setOperatingSystem(std::string &const operatingSystem) {
    this->operatingSystem = operatingSystem;
  }

  // default information
};

#endif