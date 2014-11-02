#include <cmath>
#include <iostream>
using namespace std;

class Vektor {
 public:

	double x, y, z;

	 Vektor() {
		x = 0;
		y = 0;
		z = 0;
	} Vektor(const double ix, const double iy, const double iz) {
		x = ix;
		y = iy;
		z = iz;
	}

	double betrag() {
		return sqrt(x * x + y * y + z * z);
	}

	friend ostream & operator<<(ostream & out, const Vektor & v) {
		out << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
		return out;
	}
};

double skalar(const Vektor & a, const Vektor & b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

const Vektor kreuz(const Vektor & a, const Vektor & b)
{
	const Vektor ergebnis((a.y * b.z - a.z * b.y), (a.z * b.x - a.x * b.z), (a.x * b.y - a.y * b.x));

	return ergebnis;
}

int main()
{
	const Vektor u(2, 1, -1);
	const Vektor v(1, 3, 5);
	Vektor w = kreuz(u, v);

	cout << "u=" << u << endl;
	cout << "v=" << v << endl;
	cout << "Skalarprodukt von u und v: " << skalar(u, v) << endl;	// Das Skalarprodukt verschwindet, somit stehen u und v senkrecht aufeinander.
	cout << "Senkrecht auf u und v steht folgender Vektor: " << w << endl;	// Der Vektor [8, -11, 5] ist das Ergebnis des Kreuzprodukts und steht somit senkrecht auf beiden Vektoren.
	cout << "Dieser hat den Betrag: " << w.betrag() << endl;	// Sein Betrag ist 14.4914
}
