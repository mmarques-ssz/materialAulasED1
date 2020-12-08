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
string gera_data(data &d)
{
    return to_string(d.dia) + "/" + to_string(d.mes) + "/" + to_string(d.ano);
}

data dia_seguinte(data d)
{
	int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	data d1;
	d1 = d;
	
	if (d1.ano%4 == 0)
	{
		diasNoMes[1]++;
	}
	
	d1.dia++;
	if (d1.dia > diasNoMes[d1.mes-1])
	{
		d1.dia = 1;
		if (++d1.mes > 12)
		{
			d1.mes = 1;
			d1.ano++;
		}
	}
	
	return d1;
}

int main(int argc, char** argv)
{
	data hoje;
	data amanha;
	
	cria_data(&hoje, 28, 8, 2020);
	cout << "Hoje eh " << gera_data(hoje) << endl;
	cout << endl;
	
	amanha = dia_seguinte(hoje);
	cout << "Amanha sera " << gera_data(amanha) << endl;
	cout << endl;
	
	
	return 0;
}