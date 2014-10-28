#include <iostream>
#include <cmath>
using namespace std;

class Cluster {
 public:

	double mstars;		// Masse der Sterne
	double mtotal;		// Gesamtmasse
	double eps;		// Sternenstehungseffiziens

	 Cluster(double iMtotal, double iEps) {
		mstars = 0.;
		mtotal = iMtotal;
		eps = iEps;
	} double fraction()	// Anteil der Sternmasse
	{
		return (mstars / mtotal) * 100;
	}

	void starform() {
		mstars += eps * (mtotal - mstars);
	}
};

int main()
{
	Cluster A(1e8, 0.3);
	Cluster B(1e9, 0.1);

	for (int i = 0; i < 15; i++) {
		A.starform();
		B.starform();
	}

	cout << "Anteil der Sternmasse (in Sonnenmassen) von Cluster A (nach 15 Zeitschritten) = " << A.fraction() << "%" << endl;	//99.5% der Masse liegen nach 15 Zeitschritten in Sternen vor
	cout << "Anteil der Sternmasse (in Sonnenmassen) von Cluster B (nach 15 Zeitschritten) = " << B.fraction() << "%" << endl;	//79.4% der Masse liegen nach 15 Zeitschritten in Sternen vor
}
