#include <iostream>
using namespace std;

struct Funcionario
{
	int prontuario;
	string nome;
	double salario;
};

struct Lista
{
	Funcionario *dado;
	struct Lista *prox;
};

Lista* init()
{
	return NULL;
}

int isEmpty(Lista* lista)
{
	return (lista == NULL);
}

Lista* insert(Lista* lista, Funcionario* f)
{
	Lista* novo = new Lista;
	novo->dado = f;
	novo->prox = lista;
	return novo;
}

void print(Lista* lista)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL)
	{
		cout << "Dado: " << aux->dado->prontuario << " | "
		                 << aux->dado->nome       << " | "
          		         << aux->dado->salario    << endl;
		
		aux = aux->prox;
	}
}

Lista* find(Lista* lista, Funcionario* f)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL && aux->dado->prontuario != f->prontuario)
	{
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		aux = new Lista;
		aux->dado->prontuario = -1;
		aux->prox = NULL;
	}
	return aux;
}

Lista* remove(Lista* lista, Funcionario* f)
{
	Lista *ant = NULL;
	Lista *aux;
	
	aux = lista;
	while (aux != NULL && aux->dado->prontuario != f->prontuario)
	{
		ant = aux;
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		return lista;
	}
	if (ant == NULL) // era primeiro
	{
		lista = aux->prox;
	}
	else // estava no meio
	{
		ant->prox = aux->prox;
	}
	free(aux);
	return lista;
}

void freeList(Lista* lista)
{
	Lista *aux;
	aux = lista;
	while (aux != NULL)
	{
		Lista *ant = aux->prox;
		free(aux);
		aux = ant;
	}
}

int main(int argc, char** argv)
{
	Lista *minhaLista;
	minhaLista = init();
	
	cout << "Lista vazia: " << (isEmpty(minhaLista)?"Sim":"Nao") << endl;
	
    Funcionario *umFunc;
    umFunc = new Funcionario;
	umFunc->prontuario = 100;
	umFunc->nome = "Nome do func";
	umFunc->salario = 1000.00; 

	minhaLista = insert(minhaLista, umFunc);
	
    Funcionario *outroFunc;
    outroFunc = new Funcionario;
	outroFunc->prontuario = 200;
	outroFunc->nome = "Nome do outro func";
	outroFunc->salario = 2000.00; 

	minhaLista = insert(minhaLista, outroFunc);
		
	cout << "Lista vazia: " << (isEmpty(minhaLista)?"Sim":"Nao") << endl;
	
	print(minhaLista);
	
	Funcionario *buscado;
	buscado = new Funcionario;
	buscado->prontuario = 200;
	
	Lista *procurado = find(minhaLista, buscado); 
	if (procurado->dado->prontuario > -1)
	{
  	   cout << "Resultado da busca: " << procurado->dado->nome << endl;		
	}
    else
    {
   	   cout <<"Nao encontrado" << endl;
    }
    
    minhaLista = remove(minhaLista, umFunc);
    
    print(minhaLista);  
	
	freeList(minhaLista);  

	return 0;
}