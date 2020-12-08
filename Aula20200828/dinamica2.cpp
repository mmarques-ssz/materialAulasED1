#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define LIN 5
#define COL 3

int main()
{   
    int i;
    int j;

	/*
	int **mat;

	mat = (int**)malloc(LIN * sizeof(int)); // alocação do vetor de ponteiros
	for(i = 0; i < LIN; ++i)
	{
		mat[i] = (int*)malloc(COL * sizeof(int)); // alocação de cada elemento
	}

    for(i=0; i<LIN; ++i)
	{
		for(j=0; j<COL; ++j)
	    {
	    	mat[i][j]=i+j;
	    }
	}
	
	for(i=0; i<LIN; ++i)
	{
	    for(j=0; j<COL; ++j)
	    {
            cout << mat[i][j] << " | ";
		}
		cout << endl; 
	}
	cout << "-----------" << endl;
	
	//Liberando cada elemento
	for(i = 0; i < LIN; ++i)
	{
		free(mat[i]);
	}
	
	// Liberando a matriz
	free(mat);
	*/
	
	// ===== Alocação dinâmica com new =========================================
	
	int **mat2;
	
	mat2 = new int*[5];
	
	for(i=0; i<5; ++i)
	{
		mat2[i] = new int[3];
	}
	
	for(i=0; i<5; ++i)
	{
		for(j=0; j<3; ++j)
	    {
	    	mat2[i][j]=i+j;
	    }
	}
		
	for(i=0; i<5; ++i)
	{
	    for(j=0; j<3; ++j)
	    {
            cout << mat2[i][j] << " | ";
		}
		cout << endl; 
	}	
	
	delete[] mat2;

	return 0;
}