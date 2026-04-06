#include <iostream>
#include "civilization.h"
#include "diagnostics.h"
#include "activity.h"

int evaluateCivilization() {
  int score = 0;

  double uptime = getSystemUptime();
  bool network = checkNetworkConnection();
  int year = getSystemYear();

  std::cout << "\nAnalyzing civilization status...\n";

  if (uptime > 60) {
    score += 10;
    std::cout << "Stable system uptime detected.\n";
  }

  if (uptime > 3600) {
    score += 20;
    std::cout << "Long-running system detected.\n";
  }

  if (year >= 2020 && year <= 2100) {
    score += 20;
    std::cout << "System time appears valid.\n";
  } else {
    std::cout << "Suspicious system time detected.\n";
  }

  if (network) {
    score += 30;
    std::cout << "External network reachable.\n";
  }

  if (isUserActive()) {
    score += 20;
    std::cout << "User activity detected.\n";
  } else {
    std::cout << "No user activity detected.\n";
  }
  
  std::cout << "Civilization score: " << score << "\n";

  return score;
}
