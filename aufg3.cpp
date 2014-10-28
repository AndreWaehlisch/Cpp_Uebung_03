#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

class IMF
{
public:

  double operator () (double m)
  {
    double a;

    if (m < 0.08)
      {
	return 1 * pow (m, -a);
      }
    else if (m < 0.5)
      {
	return 1 * pow (m, -1.3);
      }
    else
      {
	return 1 * pow (m, -2.3);
      }
  }
};

int
main ()
{
  const int N = 2000;
  const double m_min = 0.01;
  const double m_max = 100;
  const double dm = (m_max - m_min) / N;

  ofstream file ("werte.txt", ios::trunc);

  IMF A;

  for (int i = 0; i < N; i++)
    {
      const double m = m_min + (dm * i);
      file << m << '\t' << A (m) << '\n';
    }

  file.close ();

  cout << "Output in die Datei werte.txt geschrieben!" << endl;

  return 0;
}
