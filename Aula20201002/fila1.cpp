#include <iostream>
using namespace std;

struct No {
	float dado;
	struct No *prox;
};

struct Fila {
	No *ini;
	No *fim;
};

void mostrarEnderecos(Fila *f) {
	cout << "Fila->ini: " << f->ini << " e Fila-fim: " << f->fim << endl;
}

Fila* init() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

// Função para enfileirar um elemento na fila
void enqueue(Fila *f, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)) {
		f->ini = no;
	}
	else
	{
		f->fim->prox = no;
	}
	f->fim = no;
	mostrarEnderecos(f);
}

// Função para desenfileirar um elemento da fila
float dequeue(Fila *f) {
	float ret;
	No *no = f->ini;
	ret = no->dado;
	f->ini = no->prox;
	if (f->ini == NULL) {
		f->fim = NULL;
	}
	free(no);
	mostrarEnderecos(f);
	return ret;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "---------------------" << endl;
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while (no != NULL) {
		qtde++;
		no = no->prox;
	}
    return qtde;
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
}

int main(int argc, char** argv)
{
	Fila *filaFloat;
	filaFloat = init();
	mostrarEnderecos(filaFloat);
	
	cout << "Fila vazia: " << (isEmpty(filaFloat)?"Sim":"Nao") << endl;
	cout << "Qtde de nos: " << count(filaFloat) << endl;
	
	enqueue(filaFloat, 11.11);
	enqueue(filaFloat, 22.22);
	enqueue(filaFloat, 33.33);
	
	cout << "Fila vazia: " << (isEmpty(filaFloat)?"Sim":"Nao") << endl;
	cout << "Qtde de nos: " << count(filaFloat) << endl;
		
	print(filaFloat);
	
	cout << "Saiu da fila: " << dequeue(filaFloat) << endl;
	cout << "Saiu da fila: " << dequeue(filaFloat) << endl;
	cout << "Saiu da fila: " << dequeue(filaFloat) << endl;
	
    cout << "Fila vazia: " << (isEmpty(filaFloat)?"Sim":"Nao") << endl;
	cout << "Qtde de nos: " << count(filaFloat) << endl;
		
	print(filaFloat);

	freeFila(filaFloat);
	
	return 0;
}

