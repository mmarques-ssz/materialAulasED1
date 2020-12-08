#include <iostream>
using  namespace std;

struct No {
	float dado;
	struct No *prox;
};

struct Pilha {
	No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

void push(Pilha *p, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = p->topo;
	p->topo = no;
}

float pop(Pilha *p) {
	float ret;
	No *no = p->topo;
	ret = no->dado;
	p->topo = no->prox;
	free(no);
	return ret;
}

void print(Pilha *p) {
	No *no;
	no = p->topo;
	while(no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "------------------------" << endl;
}

int count(Pilha *p) {
	int qtde = 0;
	No *no;
	no = p->topo;
	while(no != NULL) {
        qtde++;   
		no = no->prox;
	}
	return qtde;
}

void freePilha(Pilha *p) {
	No *no = p->topo;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(p);
}

int main(int argc, char** argv)
{
	Pilha *pilhaFloat;
	pilhaFloat = init();
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"Sim":"Nao") << endl;
	cout << "Qtde de nos: " << count(pilhaFloat) << endl;
	
	push(pilhaFloat, 1.1);
	push(pilhaFloat, 2.2);
	push(pilhaFloat, 3.3);
	
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