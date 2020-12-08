#include <iostream>
using namespace std;

#define MAX 10

struct Fila {
	int ini;
	int fim;
	float nos[MAX];
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = 0;
	f->fim = 0;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == f->fim);
}

int incrementa(int i) {
	if (i == MAX-1) {
		return 0;
	}
	else {
		return i+1;
	}
}

int enqueue(Fila *f, float v) {
	int podeEnfileirar = (incrementa(f->fim) != f->ini);
	if (podeEnfileirar) {
		f->nos[f->fim] = v;
		f->fim = incrementa(f->fim);
	}
	return podeEnfileirar;
}

float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		ret = f->nos[f->ini];
		f->ini = incrementa(f->ini);
	}
	return ret;
}

void print(Fila *f) {
	int i = f->ini;
	while (i != f->fim) {
		cout << f->nos[i] << endl;
		i = incrementa(i);
	}
	cout << "---------------------" << endl;
}

int count(Fila *f) {
	int qtde = 0;
	int i = f->ini;
	while (i != f->fim) {
		cout << i << ", ";
		qtde++;
		i = incrementa(i);
	}
	cout << endl;
	return qtde;
}

void freeFila(Fila *f) {
	free(f);
}

int main(int argc, char** argv)
{
	Fila *filaFloat;
	filaFloat = init();
	
	cout << "Fila vazia: " << (isEmpty(filaFloat)?"Sim":"Nao") << endl;
	cout << "Qtde nos: " << count(filaFloat) << endl;
		
	cout << "Conseguiu: " << (enqueue(filaFloat, 11.11)?"Sim":"Nao") << endl;
    cout << "Conseguiu: " << (enqueue(filaFloat, 22.22)?"Sim":"Nao") << endl;
	cout << "Conseguiu: " << (enqueue(filaFloat, 33.33)?"Sim":"Nao") << endl;
    cout << "Conseguiu: " << (enqueue(filaFloat, 44.44)?"Sim":"Nao") << endl;
	cout << "Conseguiu: " << (enqueue(filaFloat, 55.55)?"Sim":"Nao") << endl;
    cout << "Conseguiu: " << (enqueue(filaFloat, 66.66)?"Sim":"Nao") << endl;
	cout << "Conseguiu: " << (enqueue(filaFloat, 77.77)?"Sim":"Nao") << endl;
    cout << "Conseguiu: " << (enqueue(filaFloat, 88.88)?"Sim":"Nao") << endl;
	cout << "Conseguiu: " << (enqueue(filaFloat, 99.99)?"Sim":"Nao") << endl;
	
	cout << "Fila vazia: " << (isEmpty(filaFloat)?"Sim":"Nao") << endl;
	cout << "Qtde nos: " << count(filaFloat) << endl;
		
	print(filaFloat);
	
	cout << "Saiu da fila: " << dequeue(filaFloat) << endl;
	cout << "Saiu da fila: " << dequeue(filaFloat) << endl;
	
	cout << "Conseguiu: " << (enqueue(filaFloat, 100.01)?"Sim":"Nao") << endl;
	cout << "Conseguiu: " << (enqueue(filaFloat, 100.01)?"Sim":"Nao") << endl;
	
	cout << "Saiu da fila: " << dequeue(filaFloat) << endl;
	cout << "Saiu da fila: " << dequeue(filaFloat) << endl;
	
    cout << "Fila vazia: " << (isEmpty(filaFloat)?"Sim":"Nao") << endl;
	cout << "Qtde nos: " << count(filaFloat) << endl;
		
	print(filaFloat);

	freeFila(filaFloat);
	
	return 0;
}

