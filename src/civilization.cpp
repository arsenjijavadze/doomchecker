#include <iostream>
#include "civilization.h"
#include "diagnostics.h"

int evaluateCivilization() {
  int score = 0;

  double uptime = getSystemUptime();
  bool network = checkNetworkConnection();

  std::cout << "\nAnalyzing civilization status...\n";

  if (uptime > 60) {
    score += 10;
    std::cout << "Stable system uptime detected.\n";
  }

  if (uptime > 3600) {
    score += 20;
    std::cout << "Long-running system detected.\n";
  }

  if (network) {
    score += 30;
    std::cout << "External network reachable.\n";
  }

  std::cout << "Civilization score: " << score << "\n";

  return score;
}
