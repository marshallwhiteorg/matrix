#include "atom.h"
#include <stdexcept>

Atom::Atom(int protons, int neutrons, int electrons)
    :m_protons {protons},
     m_neutrons {neutrons},
     m_electrons {electrons}
{
  if (protons < 0 | neutrons < 0 | electrons < 0) {
    throw std::invalid_argument("Numbers of particles must be positive.");
  }
}

int Atom::charge() {
    return m_protons - m_electrons;
}
      

