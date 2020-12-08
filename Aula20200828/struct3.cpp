#include <iostream>
using namespace std;

struct data
{
   int dia;
   int mes;
   int ano;	
};

/*
// Passagem de par�metro por valor
void mostra_data(data d)
{
    cout << "Hoje eh " << d.dia << "/" << d.mes << "/" << d.ano << endl;
}
*/

// Passagem de par�metro por refer�ncia
void mostra_data(data &d)
{
    cout << "Hoje eh " << d.dia << "/" << d.mes << "/" << d.ano << endl;
}

// Passagem de par�metro atrav�s de ponteiro
void mostra_data(data *d)
{
    cout << "Hoje eh " << d->dia << "/" << d->mes << "/" << d->ano << endl;
}


int main(int argc, char** argv)
{
	data hoje;
	data *phoje;
	
	hoje.dia = 28;
	hoje.mes = 8;
	hoje.ano = 2020;
	
	mostra_data(&hoje);
	
	data amanha;
	
	amanha = hoje;
	amanha.dia++;
	
	mostra_data(amanha);
	
	
	/*
	phoje = &hoje;
	cout << "Hoje eh " << (*phoje).dia << "/" << (*phoje).mes << "/" << (*phoje).ano << endl;
	cout << "Hoje eh " << phoje->dia << "/" << phoje->mes << "/" << phoje->ano << endl;
	*/
	
	return 0;
}