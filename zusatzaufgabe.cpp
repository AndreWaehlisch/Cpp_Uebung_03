#include <iostream>
using namespace std;

void set_to_two(int x)
{
	x = 2;
}

void set_to_two_ref(int &x)
{
	x = 2;
}

int main()
{

	int a = 1;

	cout << "a = " << a << endl;

	cout << "set_to_two ( a ) ; " << endl;

	set_to_two(a);

	cout << "a = " << a << endl;

	// Der Wert von a wird beim Funktionsaufruf von set_to_two() als Kopie übergeben, innerhalb der Funktion wird der Wert der Kopie auf 2 gesetzt, nach Funktionsende wird die Kopie gelöscht, sodass a  unveränderten den in main() gesetzten Wert a = 1 hat. 

	cout << "set_to_two_ref ( a ) ; " << endl;

	set_to_two_ref(a);

	cout << "a = " << a << endl;

	// Beim Funktionsaufruf wird die Speicheradresse von a an set_to_two_ref() übergeben, innerhalb der Funktion wird diese dereferenziert und auf zwei gesetzt. Nach Funktionsende hat a daher auch in main() den Wert 2. 

}
