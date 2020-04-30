#include <string>
#include <stdio.h>
#include <cholmod_config.h>
#include <unistd.h>
#include <errno.h>
#include "../../include/dashboard/systemInfo.h"

//!< the construtor for the class
systemInfo::systemInfo(void)
{
    printf("[SYSTEM_INFO.CPP] Hello, World!\n");

    resolveHostName();
    // resolvePlatform();
    // resolveDistribution();
    // resolveKernelInfo();
    // resolveCPUModel();
    // resolveCPUCores();
    // resolveCPUSpeed();

}

//!< 
std::string
systemInfo::getHostName(void)
{
    return hostName;
}

//!<
std::string
systemInfo::getPlatform(void)
{
    return platform;
}

//!<
std::string
systemInfo::getDistribution(void)
{
    return distribution;
}

//!<
kernelInfo
systemInfo::getKernelInfo(void)
{
    return kernel_info;
}

//!<
std::string
systemInfo::getCPUModel(void)
{
    return cpuModel;
}

//!<
int
systemInfo::getCPUCores(void)
{
    return cpuCores;
}

//!<
std::string
systemInfo::getCPUSpeed(void)
{
    return cpuSpeed;
}

//!<
void
systemInfo::resolveHostName(void)
{
    printf("[SYSTEM_INFO.CPP] Hello, world, from systemInfo.cpp -> constructor\n");

    char str[255] = {0};
    int val = gethostname(str, 255);

    if ( val == 0 )
    {
        for ( int i = 0; str[i] != '\0' ; ++i )
            printf("%c", str[i]);
        puts("");
    }
    else if ( val != 0 )
    {
        printf("An error occured: %s\n", strerror(errno));
    }

    return ;
}

//!<
void
systemInfo::resolvePlatform(void)
{

}

//!<
void
systemInfo::resolveDistribution(void)
{

}

//!<
void
systemInfo::resolveKernelInfo(void)
{

}

//!<
void
systemInfo::resolveCPUModel(void)
{

}

//!<
void
systemInfo::resolveCPUCores(void)
{

}

//!<
void
systemInfo::resolveCPUSpeed(void)
{

}

//!<
void
systemInfo::testing_public(void)
{
    printf("Hello, World!");

    return ;
}