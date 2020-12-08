#include <iostream>
using  namespace std;

#define MAX 50

struct Pilha {
	int qtde;
	float nos[MAX];
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->qtde == 0);
}

int count(Pilha *p) {
	return p->qtde;
}

int push(Pilha *p, float v) {
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->nos[p->qtde] = v;
		p->qtde++;
	}
	return podeEmpilhar;
}

float pop(Pilha *p) {
	float ret;
	int podeDesempilhar = (p->qtde > 0);
	if (podeDesempilhar) {
		ret = p->nos[p->qtde - 1];
		p->qtde--;
	}
	else
	{
		ret = -1;
	}
	return ret;
}

void print(Pilha *p) {
	for(int i = p->qtde-1; i >= 0; --i) {
		cout << p->nos[i] << endl;
	} 
	cout << "------------------" << endl;
}

void freePilha(Pilha *p)
{
	free(p);
}

int main(int argc, char** argv)
{
	Pilha *pilhaFloat;
	pilhaFloat = init();
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"Sim":"Nao") << endl;
	cout << "Qtde de nos: " << count(pilhaFloat) << endl;
	
	cout << (push(pilhaFloat, 1.1)?"OK":"Pilha cheia") << endl;
	cout << (push(pilhaFloat, 2.2)?"OK":"Pilha cheia") << endl;
	cout << (push(pilhaFloat, 3.3)?"OK":"Pilha cheia") << endl;
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"Sim":"Nao") << endl;
	cout << "Qtde de nos: " << count(pilhaFloat) << endl;
	
	print(pilhaFloat);
	
	cout << "Removi o dado: " << pop(pilhaFloat) << endl;
	
    cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"Sim":"Nao") << endl;
	cout << "Qtde de nos: " << count(pilhaFloat) << endl;
	
	print(pilhaFloat);	
	
	cout << "Removi o dado: " << pop(pilhaFloat) << endl;
	
    cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"Sim":"Nao") << endl;
	cout << "Qtde de nos: " << count(pilhaFloat) << endl;

	
	print(pilhaFloat);	
	
	freePilha(pilhaFloat);
	
	return 0;
}


