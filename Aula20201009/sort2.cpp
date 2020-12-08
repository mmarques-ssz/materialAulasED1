#include <iostream>
using namespace std;

void sort_bubble_recurs(int t, int *a)
{
	int i;
	int j;
	int s; 
	
	for(j=0; j<(t-1); ++j) {
		cout << "[" << j << "]: " << a[j] << ", [" << j+1 << "]: " << a[j+1];
        if (a[j] > a[j+1]) {
			s = a[j];
			a[j] = a[j+1];
			a[j+1] = s;
			cout << " - trocou!!!"; 
		}
		cout << endl;
	}
	
	if (t>1) {
   	   sort_bubble_recurs(t-1, a);
	}
}

void print(int t, int *a) {
	int i;
	for(i=0; i<t; ++i) {
		cout << "Elemento: " << i << " = " << a[i] << endl;
	}
	cout << "------------------------" << endl;
}

int main(int argc, char** argv)
{
	int v[8] = {26,49,38,13,58,87,34,93};
	int tam = sizeof(v)/sizeof(int);
	
	print(tam , v);
	
	sort_bubble_recurs(tam , v);
	
	print(tam, v);
	
	return 0;
}