#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a;
	int *pa;
	int b;
	int *pb;
	int c;
	int *pc;
	
	pa = &a;
	pb = &b;
	pc = &c;
	
	a = 10;
	b = *pa * 2;
	
	*pc = *pa + b;
	
    cout << "Valor de a: " << a << endl;
    cout << "Valor de b: " << b << endl;
    cout << "Valor de c: " << c << endl;
    
    cout << endl;
    
	return 0;
}