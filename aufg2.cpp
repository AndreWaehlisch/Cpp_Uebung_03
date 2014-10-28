#include <cmath>
#include <iostream>
using namespace std;

class Vektor
{
public:

  double x, y, z;

    Vektor ()
  {
    x = 0;
    y = 0;
    z = 0;
  }

  Vektor (double ix, double iy, double iz)
  {
    x = ix;
    y = iy;
    z = iz;
  }

  double betrag ()
  {
    return sqrt (x * x + y * y + z * z);
  }

  friend ostream & operator<< (ostream & out, const Vektor & v)
  {
    out << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
    return out;
  }
};

double
skalar (Vektor & a, Vektor & b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vektor
kreuz (Vektor & a, Vektor & b)
{
  Vektor ergebnis;

  ergebnis.x = (a.y * b.z - a.z * b.y);
  ergebnis.y = (a.z * b.x - a.x * b.z);
  ergebnis.z = (a.x * b.y - a.y * b.x);

  return ergebnis;
}

int
main ()
{
  Vektor u (2, 1, -1);
  Vektor v (1, 3, 5);
  Vektor w = kreuz (u, v);

  cout << "Skalarprodukt von u und v: " << skalar (u, v) << endl;	// Das Skalarprodukt verschwindet, u und v sind somit senkrecht.
  cout << "Senkrecht auf u und v steht folgender Vektor: " << w << endl;	// Der Vektor [8, -11, 5] ist das Ergebnis des Kreuzprodukts.
  cout << "Dieser hat den Betrag: " << w.betrag () << endl;	// Sein Betrag ist 14.4914

  return 0;
}
