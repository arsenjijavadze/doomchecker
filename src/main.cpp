#include <iostream>
#include "diagnostics.h"
#include "civilization.h"

int main() {
   std::cout << "================================\n";
   std::cout << "    SURVIVAL ASSISTANT SYSTEM\n";
   std::cout << "================================\n\n";

   runDiagnostics();

   int score = evaluateCivilization();

   if (score < 20) {
     std::cout << "WARNING: civilization status uncertain.\n";
   } else {
     std::cout << "Civilization appears operational.\n";
   }

   return 0;

}
