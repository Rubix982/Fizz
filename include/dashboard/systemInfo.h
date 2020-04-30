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

        /*!< Methods */
        systemInfo(void);
        void testing_public(void);

        std::string getHostName(void);
        std::string getPlatform(void);
        std::string getDistribution(void);
        kernelInfo getKernelInfo(void);
        std::string getCPUModel(void);
        int getCPUCores(void);
        std::string getCPUSpeed(void);

        void resolveHostName(void);
        void resolvePlatform(void);
        void resolveDistribution(void);
        void resolveKernelInfo(void);
        void resolveCPUModel(void);
        void resolveCPUCores(void);
        void resolveCPUSpeed(void);

    private:

        /*!< Attributes */
    
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

};

#endif