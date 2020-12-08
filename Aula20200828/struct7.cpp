#include <iostream>
using namespace std;

class Data
{
	private: 	
	   int dia;
	   int mes;
	   int ano;	
    public:
    	Data(int dia, int mes, int ano)
		{
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}
		Data()
		{
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
		}
    	void setDia(int dia)
    	{
			this->dia = dia;
		}
		void setMes(int mes)
    	{
			this->mes = mes;
		}
		void setAno(int ano)
    	{
			this->ano = ano;
		}
		int getDia()
		{
			return this->dia;
		}
		int getMes()
		{
			return this->mes;
		}
		int getAno()
		{
			return this->ano;
		}
		string getData()
		{
		    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
		}
		Data* dia_seguinte()
		{
			int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			Data *d1 = new Data(this->dia, this->mes, this->ano);
			
			if (d1->ano%4 == 0)
			{
				diasNoMes[1]++;
			}
			
			d1->dia++;
			if (d1->dia > diasNoMes[d1->mes-1])
			{
				d1->dia = 1;
				if (++d1->mes > 12)
				{
					d1->mes = 1;
					d1->ano++;
				}
			}
			
			return d1;
		}
};


int main(int argc, char** argv)
{
    Data *hoje = new Data(28, 8, 2020);
    cout << hoje->getData() << endl;
    
    Data *amanha = hoje->dia_seguinte();
    cout << amanha->getData() << endl;
    
    Data *datas[5];
    for (int i=0; i<5; ++i)
	{
		datas[i] = new Data(i+1, 8, 2020);
	}
	
    for (int i=0; i<5; ++i)
	{
		cout << datas[i]->getData() << endl;
	}
	 
	return 0;
}
