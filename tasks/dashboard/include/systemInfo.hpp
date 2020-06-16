#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

#include "../../includes/systemInfoClasses.hpp"
#include <string>
#include <cpuid.h>

class systemInfo
{

    public:

        /*!< Methods */
        systemInfo(void);
        void testing_public(void);

        void resolveHostName(void);
        void resolvePlatform(void);
        void resolveDistribution(void);
        void resolveKernelInfo(void);
        void resolveCPUModel(void);
        void resolveCPUCores(void);
        void resolveCPUSpeed(void);

        /*!< helper functions */
        std::string getDataFromBuffer(void);

        ~systemInfo();

    private:

        /*!< Attributes */

        //! kernel info
        kernelInfo *kernelInfoData;

        //! Stacer and hardware related info
        hardwareInfo *hardwareInfoData;
};

#endif