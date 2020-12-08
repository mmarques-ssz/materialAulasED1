#include <iostream>
using namespace std;

void sort_bubble(int t, int *a)
{
	int i;
	int j;
	int s; 
	
	for(i=t-1; i>=1; --i) {
		for(j=0; j<i; ++j) {
			cout << "[" << j << "]: " << a[j] << ", [" << j+1 << "]: " << a[j+1];
			if (a[j] > a[j+1]) {
				s = a[j];
				a[j] = a[j+1];
				a[j+1] = s;
				cout << " - trocou!!!"; 
			}
			cout << endl;
		}
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
	
	sort_bubble(tam , v);
	
	print(tam, v);
	
	return 0;
}