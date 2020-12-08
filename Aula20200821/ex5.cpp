#include <iostream>
using namespace std;

// Passagem de parâmetro por valor
int incrementar_porValor(int x)
{
	x++;
	return x;
}

// Passagem de parâmetro por referência
void incrementar_porReferencia(int &x)
{
	x++;
}

// Passagem de parâmetro por ponteiro
void incrementar_porPonteiro(int *x)
{
	(*x)++;
}

void qualquer(int &a, int &b)
{
   a = 20;
   b = 30;	
}


int main(int argc, char** argv)
{
	int x=5, y=10;
	
	cout << "Valor de x: " << x << " e y: " << y << endl;
	qualquer(x, y);
	cout << "Valor de x: " << x << " e y: " << y << endl;
	
	/*
	int a = 1;
	
	cout << "Valor de a: " << a << endl;
	cout << "Retorno da função incrementar: " << incrementar_porValor(a) << endl;
	cout << "Valor de a: " << a << endl;
	cout << endl;
	
	cout << "========================" << endl;
	
	cout << "Valor de a: " << a << endl;
	incrementar_porReferencia(a);
	cout << "Valor de a: " << a << endl;
	cout << endl;
	
	cout << "========================" << endl;
	
	cout << "Valor de a: " << a << endl;
	incrementar_porPonteiro(&a);
	cout << "Valor de a: " << a << endl;
	cout << endl;
	*/
	return 0;
}