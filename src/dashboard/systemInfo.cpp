#include <regex>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cholmod_config.h>
#include <unistd.h>
#include <errno.h>
#include "../../include/dashboard/systemInfo.h"

#define BUFFER 255

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

    char str[BUFFER] = {0};
    int val = gethostname(str, 255);

    if ( val == 0 )
    {
        for ( int i = 0; str[i] != '\0' ; ++i )
            printf("%c", str[i]);
        puts("");
    }
    else
    {
        printf("An error occured: %s\n", strerror(errno));
        exit(errno);
    }

    hostName = str;

    return ;
}

//!<
void
systemInfo::resolvePlatform(void)
{
    if ( execl("/usr/bin/uname", "uname -m > ./buffer.txt", (char*)NULL) == -1 ) 
    {
        printf("[SYSTEMINFO.CPP] execl execution, error occured: %s", strerror(-1));
        exit(-1);
    }    

    platform = getDataFromBuffer();

    return ;
}

//!<
void
systemInfo::resolveDistribution(void)
{
    if ( ( execl("/usr/bin/lsb_release", "lsb_release -d > ./buffer.txt", (char *) NULL ) ) )   
    {
        printf("[SYSTEMINFO.CPP] execl execution for platform, error occured: %s\n", strerror(-1));
        exit(-1);
    }

    std::string description = getDataFromBuffer();

    std::stringstream ss(description);
    std::vector<std::string> container;
    std::string token;

    std::getline(ss, token, ':');
    distribution = std::regex_replace(token, std::regex("^ +"), "");

    if ( ( execl("/usr/bin/lsb_release", "lsb_release -r > ./buffer.txt", (char *) NULL ) ) )   
    {
        printf("[SYSTEMINFO.CPP] execl execution for platform, error occured: %s\n", strerror(-1));
        exit(-1);
    }

    description = getDataFromBuffer();
    
    ss.clear();
    ss << description;
    std::string token;

    std::getline(ss, token, ':');
    releaseType = std::regex_replace(token, std::regex("^ +"), "");

    return ;

}

//!<
void
systemInfo::resolveKernelInfo(void)
{
    std::vector<std::string> kernel_information_get{"s", "n", "v", "m", "p", "i", "o"};
    std::vector<std::string> store_info{7, ""};

    for ( int i = 0 ; i < 7 ; ++i )
    {
        std::string string = "uname -" + kernel_information_get[i] + " > ./buffer.txt";
        if ( ( execl("/usr/bin/uname", string.c_str(), (char *) NULL ) ) == -1 )   
        {
            printf("[SYSTEMINFO.CPP] execl execution for platform, error occured: %s\n", strerror(-1));
            exit(-1);
        }

        store_info[i] = getDataFromBuffer();
    }

    kernel_info.kernelName = store_info[0];
    kernel_info.nodename = store_info[1];
    kernel_info.kernel_version = store_info[2];
    kernel_info.machine = store_info[3];
    kernel_info.processor = store_info[4];
    kernel_info.hardware_platform = store_info[5];
    kernel_info.operating_system = store_info[6];

    return ;
}

//!<
void
systemInfo::resolveCPUModel(void)
{
    if ( execl("/usr/bin/lscpu", "lscpu > buffer.txt", (char *) NULL ) == -1 )
    {
        printf("[SYSTEMINFO.CPP] execl execution for resolveCPUModel, error occured: %s\n", strerror(-1));
        exit(-1);
    }
    else if ( execl("/usr/bin/grep", "grep 'Model name' buffer.txt > buffer.txt", (char *) NULL) == -1 ) 
    {
        printf("[SYSTEMINFO.CPP] execl execution for grep, error occured: %s\n", strerror(-1));
        exit(-1);
    }

    std::string temp = getDataFromBuffer(), token;
    std::stringstream ss(temp);

    std::getline(ss, token, ':');

    cpuModel = std::regex_replace(token, std::regex("^ +"), "");

    return ;
    
}

//!<
void
systemInfo::resolveCPUCores(void)
{
    if ( execl("/usr/bin/lscpu", "lscpu > buffer.txt", (char *) NULL ) == -1 )
    {
        printf("[SYSTEMINFO.CPP] execl execution for resolveCPUModel, error occured: %s\n", strerror(-1));
        exit(-1);
    }
    else if ( execl("/usr/bin/grep", "grep 'CPU(s)' buffer.txt > buffer.txt", (char *) NULL) == -1 ) 
    {
        printf("[SYSTEMINFO.CPP] execl execution for grep, error occured: %s\n", strerror(-1));
        exit(-1);
    }

    std::string temp = getDataFromBuffer(), token;
    std::stringstream ss(temp);

    std::getline(ss, token, ':');

    token = std::regex_replace(token, std::regex("^ +"), "");
    cpuCores = std::atoi(token.c_str());

    return ;

}

//!<
void
systemInfo::resolveCPUSpeed(void)
{

    if ( execl("/usr/bin/lscpu", "lscpu > buffer.txt", (char *) NULL ) == -1 )
    {
        printf("[SYSTEMINFO.CPP] execl execution for resolveCPUModel, error occured: %s\n", strerror(-1));
        exit(-1);
    }
    else if ( execl("/usr/bin/grep", "grep 'CPU MHz' buffer.txt > buffer.txt", (char *) NULL) == -1 ) 
    {
        printf("[SYSTEMINFO.CPP] execl execution for grep, error occured: %s\n", strerror(-1));
        exit(-1);
    }

    std::string temp = getDataFromBuffer(), token;
    std::stringstream ss(temp);

    std::getline(ss, token, ':');

    token = std::regex_replace(token, std::regex("^ +"), "");
    cpuCores = std::strtof(token.c_str(), 0);

    return ;
}

//!<
void
systemInfo::testing_public(void)
{
    printf("Hello, World!");

    return ;
}