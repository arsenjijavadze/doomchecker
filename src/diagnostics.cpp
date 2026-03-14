#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "diagnostics.h"

double getSystemUptime() {
  std::ifstream uptimeFile("/proc/uptime");
  
  if (!uptimeFile.is_open()) {
    std::cerr << "Error: cannot read /proc/uptime\n";
  }
  
  double uptime{};
  uptimeFile >> uptime;
  return uptime;
}

bool checkNetworkConnection() {
  int result = system("ping -c 1 -W 1 8.8.8.8 > /dev/null 2>&1");

  if (result == 0) {
    return true;
  }

  return false;
}

int getSystemYear() {
  std::time_t now = std::time(nullptr);
  std::tm *local = std::localtime(&now);

  return 1900 + local->tm_year;
}

void runDiagnostics() {
    std::cout << "Running system diagnostics...\n\n";

    std::cout << "Checking operating system...\n";
    std::cout << "Linux detected.\n\n";

    double uptime = getSystemUptime();
    std::cout << "System uptime: " << uptime << " second\n\n";

    if (uptime < 60) {
      std::cout << "System recently started.\n";
    } else if (uptime < 3600) {
      std::cout << "System uptime stable.\n";
    } else {
      std::cout << "Long running system detected.\n";
    }

    int year = getSystemYear();

    std::cout << "System year: " << year << "\n\n";

    bool network = checkNetworkConnection();
    std::cout << "Checking network connection...\n";
    if (network) {
      std::cout << "network reachable.\n";
    } else {
      std::cout << "Network unreachable.\n";
    }

    std::cout << "Diagnostics complete.\n";

}
