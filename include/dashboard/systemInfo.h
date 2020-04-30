#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

#include <QString>
#include <string>
#include <cpuid.h>

struct systemInfoData {
    // some info here
};

struct kernelInfo {

    std::string kernelName;         //! kernel name
    std::string nodename;           //! nodename
    std::string kernel_version;     //! kernel version
    std::string machine;            //! machine
    std::string processor;          //! processor
    std::string hardware_platform;  //! hardware platform
    std::string operating_system;   //! the operating system

};

class systemInfo
{

    public:

        systemInfo(void);

        //! the system hostname
        std::string hostName;    
        
        //!  the platform / architecture
        std::string platform;

        //! The linux distro
        std::string distribution;

        //! kernel info
        kernelInfo kernel_info;
        
        //! the cpu model
        std::string cpuModel;

        //! the number of cpu cores
        int cpuCores;

        //! the CPU speed
        std::string cpuSpeed;

        void testing_public(void);

    private:
    
        void testing(void);
};

void systemInfo::testing_public(void)
{



}

#endif