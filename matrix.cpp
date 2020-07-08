// Big bang

#include "atom.h"
#include <iostream>

int main() {
  Atom hydrogen {1, 0, 1};
  std::cout << "Charge: " << hydrogen.charge() << std::endl;
  return 0;
}
