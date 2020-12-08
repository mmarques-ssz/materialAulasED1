#include <iostream>
using namespace std;

struct data
{
   int dia;
   int mes;
   int ano;	
};

void cria_data(data *d, int dia, int mes, int ano)
{
	d->dia = dia;
	d->mes = mes;
	d->ano = ano;
}

// Passagem de parâmetro por referência
void mostra_data(data &d)
{
    cout << "Hoje eh " << d.dia << "/" << d.mes << "/" << d.ano << endl;
}

int main(int argc, char** argv)
{
	data hoje;
	cria_data(&hoje, 28, 8, 2020);
	mostra_data(hoje);
	return 0;
}