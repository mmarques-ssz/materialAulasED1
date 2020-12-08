#include <iostream>
using namespace std;

struct Lista
{
	int dado;
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

Lista* insert(Lista* lista, int i)
{
	Lista* novo = new Lista;
	novo->dado = i;
	novo->prox = lista;
	return novo;
}

void print(Lista* lista)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL)
	{
		cout << "Dado: " << aux->dado << endl;
		aux = aux->prox;
	}
}

Lista* find(Lista* lista, int i)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL && aux->dado != i)
	{
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		aux = new Lista;
		aux->dado = -1;
		aux->prox = NULL;
	}
	return aux;
}

Lista* remove(Lista* lista, int i)
{
	Lista *ant = NULL;
	Lista *aux;
	
	aux = lista;
	while (aux != NULL && aux->dado != i)
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
	
	minhaLista = insert(minhaLista, 5);
	minhaLista = insert(minhaLista, 10);
	minhaLista = insert(minhaLista, 7);
	
	cout << "Lista vazia: " << (isEmpty(minhaLista)?"Sim":"Nao") << endl;
	
	print(minhaLista);
	
	Lista *procurado = find(minhaLista,10); 
	if (procurado->dado > -1)
	{
  	   cout << "Resultado da busca: " << procurado->dado << endl;		
	}
    else
    {
   	   cout <<"Nao encontrado" << endl;
    }
    
    minhaLista = remove(minhaLista, 5);
    
    print(minhaLista);  
	
	freeList(minhaLista);  
	
	return 0;
}