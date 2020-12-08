#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	/*
	int *v1;
	v1 = (int*)malloc(sizeof(int)*10);
		
	for(int i=0; i<10; ++i)
	{
		v1[i] = i + 1;
	}
	
	for(int i=0; i<10; ++i)
	{
		cout << v1[i] << (i<9?", ":".");
	}
	cout << endl << endl;

	free(v1);
	*/
	
	//=================================================================
	
	int *v2;
	v2 = new int[10];
	
    for(int i=0; i<10; ++i)
	{
		v2[i] = i + 1;
	}
	
	for(int i=0; i<10; ++i)
	{
		cout << v2[i] << (i<9?", ":".");
	}
	cout << endl << endl;
	
	delete[] v2;
		
	return 0;

	
}