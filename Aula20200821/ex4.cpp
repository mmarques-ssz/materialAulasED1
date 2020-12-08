#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	int i = 100;
	int *p;
	
	p = &i;
	
	cout << "Valor de i: " << i << endl;
	cout << "Endere�o da vari�vel i: " << &i << endl;
	cout << "Endere�o do ponteiro p: " << &p << endl;
    cout << "Endere�o apontado por p: " << p << endl;
    cout << "Conte�do do endere�o apontado por p: " << *p << endl;
    
    *p = 200;
    cout << "Valor de i: " << i << endl;
    
	
	return 0;
}