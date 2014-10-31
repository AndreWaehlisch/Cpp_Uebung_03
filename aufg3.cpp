#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

class IMF {
 public:

	// Auf 1 normierte Initial Mass Function
	double operator() (double m) {
		if (m < 0.08) {
			return 0.251189 * pow(m, -0.3);
		} else if (m < 0.5) {
			return 0.02 * pow(m, -1.3);
		} else {
			return 0.01 * pow(m, -2.3);
		}
	}
};

int main()
{
	const int N = 2000;	// Anzahl der gewünschten Funktionswerte
	const double m_min = 0.01;	// Startwert
	const double m_max = 100;	// Endwert
	const double dm = (m_max - m_min) / N;	// Inkrement

	ofstream file("werte.txt", ios::trunc);	// Datei öffnen (und überschreiben)

	IMF A;			// Wahrscheinlichkeitsverteilung für Sternmassen (Wahrscheinlichkeit in Abhängigkeit der Masse)

	for (int i = 0; i < N; i++) {
		const double m = m_min + (dm * i);	// Aktueller Massen-Wert
		file << m << '\t' << A(m) << '\n';	// Zur Datei hinzufügen
	}

	file.close();		// Datei schließen

	cout << "Output wurde in die Datei werte.txt geschrieben." << endl;

	// ZU AUFGABE 4:
	// Die (doppelt) logarithmische Darstellung erleichtert das Überblicken des gesamten Intervalls, da über die Hälfte der Funktionswerte kleiner als 10^(-5) sind (bei auf 1 normierter Funktion).
}
