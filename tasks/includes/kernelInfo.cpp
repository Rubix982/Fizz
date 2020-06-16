#include "systemInfoClasses.hpp"
#include <iostream>
#include <string>

kernelInfo::kernelInfo() {
    this->setDefaultValues();
}

// getters
std::string kernelInfo::getKernelName(void) const { return kernelName; }

std::string kernelInfo::getNodename(void) const { return nodeName; }

std::string kernelInfo::getKernelVersion(void) const { return kernelVersion; }

std::string kernelInfo::getMachine(void) const { return machine; }

std::string kernelInfo::getProcessor(void) const { return processor; }

std::string kernelInfo::getOperatingSystem(void) const { return operatingSystem; }

// setters
void kernelInfo::setKernelName(std::string &const kernelName) {
  this->kernelName = kernelName;
}

void kernelInfo::setNodename(std::string &const nodeName) { this->nodeName = nodeName; }

void kernelInfo::setKernelVersion(std::string &const kernelVersion) {
  this->kernelVersion = kernelVersion;
}

void kernelInfo::setMachine(std::string &const machine) { this->machine = machine; }

void kernelInfo::setProcessor(std::string &const processor) { this->processor = processor; }

void kernelInfo::setOperatingSystem(std::string &const operatingSystem) {
  this->operatingSystem = operatingSystem;
}

//! default information
void kernelInfo::setDefaultValues(void) {

    this->resolveKernelName();
    this->resolveNodeName();
    this->resolveKernelVersion();
    this->resolveMachine();
    this->resolveProcessor();
    this->resolveOperatingSystem();

    std::cout << "Kernel Info default resolutions set";
}

//! find resolutions for the default values
void kernelInfo::resolveKernelName(void) {
  std::string flag = "s";
  this->setKernelName(getBashOutput(flag));
  return ;
}

void kernelInfo::resolveNodeName(void) {
  std::string flag = "n";
  this->setNodename(getBashOutput(flag));
  return ;
}

void kernelInfo::resolveKernelVersion(void) {
  std::string flag = "r";
  this->setKernelRelease(getBashOutput(flag));
  return ;
}

void kernelInfo::resolveMachine(void) {
  std::string flag = "v";
  this->setKernelVersion(getBashOutput(flag));
  return ;
}

void kernelInfo::resolveProcessor(void) {
  std::string flag = "m";
  this->setMachine(getBashOutput(flag));
  return ;
}

void kernelInfo::resolveOperatingSystem(void) {
  std::string flag = "o";
  this->setOperatingSystem(flag);
  return ;
}

std::string& getBashOutput(std::string & const commandAddition) {

  FILE *fp;
  char path[1035];
  std::string bashCommand = "/bin/uname -" + commandAddition;

  /* Open the command for reading. */
  fp = popen(bashCommand.c_str(), "r");
  if (fp == NULL) {
    printf("[ KERNEL_INFO.CPP ] Failed to run command with the commandAddition %c ... \n", commandAddition.c_str() );
    std::string empty = "";
    return empty;
  }

  std::string holdBashOutput{""};

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path), fp) != NULL) {
    holdBashOutput += path;
  }

  /* close */
  pclose(fp);

  return holdBashOutput;
}