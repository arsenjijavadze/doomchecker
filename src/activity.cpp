#include "activity.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

namespace fs = std::filesystem;

bool isUserActive() {
  for (const auto& entry : fs::directory_iterator("/proc"))
  {
    if (!entry.is_directory())
      continue;

    std::string pid = entry.path().filename();

    // check number
    if (!std::all_of(pid.begin(), pid.end(), [](unsigned char c) {
          return std::isdigit(c);
          }))
    {
      continue;
    }

    std::ifstream statusFile(entry.path() / "status");

    if (!statusFile.is_open())
      continue;

    std::string line;

    while (std::getline(statusFile, line))
    {
      if (line.find("Uid:") == 0)
      {
        int uid;
        sscanf(line.c_str(), "Uid:\t%d", &uid);

        if (uid != 0)
        {
          return true;
        }
      }
    }
  }
  return false; 
}
