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
	cout << "Endereço da variável i: " << &i << endl;
	cout << "Endereço do ponteiro p: " << &p << endl;
    cout << "Endereço apontado por p: " << p << endl;
    cout << "Conteúdo do endereço apontado por p: " << *p << endl;
    
    *p = 200;
    cout << "Valor de i: " << i << endl;
    
	
	return 0;
}