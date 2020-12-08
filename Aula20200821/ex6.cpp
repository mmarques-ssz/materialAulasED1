#include <iostream>
using namespace std;

void mostra_array1(int x[])
{
	for(int i=0; i<5; ++i)
	{
       cout << *x << " no endereço: " << x << endl;
	   ++x; 
	}
}

void mostra_array2(int x[])
{
	for(int i=0; i<5; ++i)
	{
       cout << x[i] << endl;
	}
}

void dobra_array(int x[])
{
	for(int i=0; i<5; ++i)
	{
       x[i] *= 2;
	}
}


int main(int argc, char** argv)
{
	int a[5] = {10, 20, 30, 40, 50};

    mostra_array1(a);
    cout << endl;
    dobra_array(a);
    mostra_array2(a);
		
	return 0;
}