// A basic unit of ordinary matter.
class Atom {
public:
  Atom(int protons, int neutrons, int electrons);
  const int m_protons;

  // This is in terms of elementary charge.
  const int charge();
private:
  const int m_neutrons;
  const int m_electrons;
};
  
