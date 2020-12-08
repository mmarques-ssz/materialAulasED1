#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
	int i;
	double d;
	
    cout << "Digite valor int: ";
	cin >> i;
	
	cout << "Digite valor double: ";
	cin >> d;
	
	// Formatação para largura (width) definida
	cout << "Valor int   : " << setw(10) << i << endl;
	cout << "Valor double: " << setw(10) << d << endl;

	cout << endl;
	
	// Precisão geral
	cout << "Valor double: " << setprecision(2) << setw(10) << d << endl;
	cout << "Valor double: " << setprecision(3) << setw(10) << d << endl;
	cout << "Valor double: " << setprecision(4) << setw(10) << d << endl;
	
	cout << endl;

    // Precisão fixa	
	cout << fixed;
	cout << setprecision(4);
	cout << "Valor double: " << setw(10) << d << endl;
	cout << "Valor double: " << setw(10) << d << endl;
	cout << "Valor double: " << setprecision(2) << setw(10) << d << endl;
	
	cout << endl;
	
	return 0;
}