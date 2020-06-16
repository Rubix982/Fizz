#ifndef __HELPER_FUNCS_1
#define __HELPER_FUNCS_1

#include <string>
#include <iostream>
#include <fstream>

std::string& getFileOutput(std::string & const fileName ) {
    std::ifstream __Infile("lscpu.log");

    while ( __Infile. )

    std::string temp = "";
    return temp;
}

// generic implementation
std::string& getBashOutput(std::string & const command) {

  FILE *fp;
  char path[1035];

  /* Open the command for reading. */
  fp = popen(command.c_str(), "r");
  if (fp == NULL) {
    printf("[ KERNEL_INFO.CPP ] Failed to run command with the command %c ... \n", command.c_str() );
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

// the int implementation
int getBashOutputInt(std::string & const command) {

  FILE *fp;
  char path[1035];

  /* Open the command for reading. */
  fp = popen(command.c_str(), "r");
  if (fp == NULL) {
    printf("[ KERNEL_INFO.CPP ] Failed to run command with the command %c ... \n", command.c_str() );
    std::string empty = "";
    return -1;
  }

  std::string holdBashOutput{""};

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path), fp) != NULL) {
    holdBashOutput += path;
  }

  /* close */
  pclose(fp);

  return 0;
}

// The float implementation
float getBashOutputFloat(std::string & const command) {

  FILE *fp;
  char path[1035];

  /* Open the command for reading. */
  fp = popen(command.c_str(), "r");
  if (fp == NULL) {
    printf("[ KERNEL_INFO.CPP ] Failed to run command with the command %c ... \n", command.c_str() );
    std::string empty = "";
    return -1.0f;
  }

  std::string holdBashOutput{""};

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path), fp) != NULL) {
    holdBashOutput += path;
  }

  /* close */
  pclose(fp);

  return 0.0f;
}

#endif