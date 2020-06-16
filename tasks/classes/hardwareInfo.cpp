#include "systemInfoClasses.hpp"
#include "helperFuncs.hpp"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>

hardwareInfo::hardwareInfo() : cpuCores(0), cpuSpeed(0.0f) {}

// hardwareInfo::getters
std::string hardwareInfo::getHostname() const { return hostname; }
std::string hardwareInfo::getDistribution() const { return distribution; }
std::string hardwareInfo::getPlatform() const { return platform; }
std::string hardwareInfo::getCPUModel() const { return cpuModel; }
std::string hardwareInfo::getReleaseType() const { return releaseType; }

int hardwareInfo::getCPUcores() const { return cpuCores; }
float hardwareInfo::getCPUSeed() const { return cpuSpeed; }

// setters
void hardwareInfo::setHostname(std::string &const hostname) { this->hostname = hostname; }
void hardwareInfo::setDistribution(std::string &const distribution) {
  this->distribution = distribution;
}
void hardwareInfo::setPlatform(std::string &const platform) { this->platform = platform; }
void hardwareInfo::setCPUModel(std::string &const cpuModel) { this->cpuModel = cpuModel; }
void hardwareInfo::setReleaseType(std::string &const releaseType) {
  this->releaseType = releaseType;
}

void hardwareInfo::setCPUcores(int &const cpuCores) { this->cpuCores = cpuCores; }
void hardwareInfo::setCPUSeed(float &const cpuSpeed) { this->cpuSpeed = cpuSpeed; }

//! default information
void hardwareInfo::setDefaultValues(void) {

  std::ofstream __Outfile("lscpu.log");

  FILE *fp;
  char path[1035];

  /* Open the command for reading. */
  fp = popen("/bin/lscpu", "r");
  if (fp == NULL) {
    printf("[ HARDWARD_INFO.CPP ] Failed to run command lscpu ... \n" );
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path), fp) != NULL)
    __Outfile << path;

  /* close */
  pclose(fp);

  this->resolveHostname();
  this->resolveDistribution();
  this->resolvePlatform();
  this->resolveCPUModel();
  this->resolveReleaseType();
  this->resolveCPUCores();
  this->resolveCPUSpeed();

}

//! resolution for the default values
void hardwareInfo::resolveHostname(void) {
  std::string commandBuffer = "hostname";
  this->setHostname(getBashOutput(commandBuffer));
  return ;
}

void hardwareInfo::resolveDistribution(void) {
  std::string commandBuffer = "cat /usr/lib/os-release";
  std::string commandOutput = getBashOutput(commandBuffer);
  std::string delimiter = "\n";
  std::vector<std::string> parsedLines;

  size_t pos = 0;

  while ((pos = commandOutput.find(delimiter)) != std::string::npos) {
    parsedLines.push_back(commandBuffer.substr(0, pos));
    commandOutput.erase(0, pos + delimiter.length());
  }

  std::smatch sm;
  for ( const auto & line : parsedLines ) {
    if ( std::regex_match(line, std::regex("(NAME)(.*)"))) {

      std::regex regexStringExpr("(.*)(\")(*)(\")");
      std::cout << "[ HARDWARE_INFO.CPP ] Found a regex match in \'" << line << "\' ... \n";
      std::regex_search( line, sm, regexStringExpr );
    }
  }

  std::string distroName = "";
  if ( sm.length() == 1 )
    distroName = sm[0];

  this->setDistribution(distroName);
  return ;
}

void hardwareInfo::resolvePlatform(void) {
  std::string platform = getBashOutput("uname -s") + " " + getBashOutput("uname -m");
  this->setPlatform(platform);
  return ;
}

void hardwareInfo::resolveCPUModel(void) {
  std::string commandBuffer = "hostname";
  this->setCPUModel(getBashOutput(commandBuffer));
  return ;
}

void hardwareInfo::resolveReleaseType(void) {
  std::string commandBuffer = "hostname";
  this->setReleaseType(getBashOutput(commandBuffer));
  return ;
}

void hardwareInfo::resolveCPUCores(void) {
  std::string commandBuffer = "hostname";
  int temp = getBashOutputInt(commandBuffer);
  // this->setCPUcores(getBashOutput(commandBuffer));
  return ;
}

void hardwareInfo::resolveCPUSpeed(void) {
  std::string commandBuffer = "hostname";
  float temp = getBashOutputFloat(commandBuffer);
  // this->setCPUSeed(getBashOutput(commandBuffer));
  return ;
}