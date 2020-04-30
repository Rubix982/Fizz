// Standard CXX files
#include <iostream>
#include <string>
#include <stdio.h>

// *nix header files
#include <sys/types.h>
#include <sys/sysinfo.h>

static unsigned long long
    lastTotalUser, lastTotalUserLow, lastTotalSys, lastTotalIdle;

void init()
{
    FILE * file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu",
            &lastTotalUser,  &lastTotalUserLow, &lastTotalSys, &lastTotalIdle );
    fclose(file);
}

double getCurrentValue()
{
    double percent;
    FILE * file;
    unsigned long long totalUser, totalUserLow,
        totalSys, totalIdle, total;

    file = fopen("/proc/stat" ,"r");
    fscanf(file, "cpu %llu %llu %llu %llu",
            &totalUser, &totalUserLow, &totalSys, &totalIdle );
    fclose(file);

    if ( totalUser < lastTotalUser || totalUserLow < lastTotalUserLow ||
        totalSys < lastTotalSys || totalIdle < lastTotalIdle)
    {
        percent = -1.0;
    }
    else {
        total = (totalUser - lastTotalUser) + (totalUserLow - lastTotalUserLow)
                +   (totalIdle - lastTotalIdle) + (totalSys - lastTotalSys);
        percent = total;
        total += (totalIdle - lastTotalIdle);
        percent /= total;
        percent *= 100;
    }

    lastTotalUser = totalUser;
    lastTotalSys = totalSys;
    lastTotalUserLow = totalUserLow;
    lastTotalIdle = totalIdle;

    return percent;
}

int main(void)
{
    init();

    std::cout << "Hello, World!\n";
    std::cout << getCurrentValue() << "\n";

    return 0;
}