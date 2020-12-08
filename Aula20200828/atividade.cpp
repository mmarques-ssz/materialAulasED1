#include <iostream>
#include <ctime>

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
};

class Contato
{
	private:
		string email;
		string nome;
		string telefone;
        Data *dtnasc;  
    public:
    	Contato(string email, string nome, string telefone, Data *dtnasc)
    	{
			this->email = email;
			this->nome = nome;
			this->telefone = telefone;
			this->dtnasc = dtnasc;
		}
		Contato()
    	{
			this->email = "";
			this->nome = "";
			this->telefone = "";
			this->dtnasc = new Data();
		}
		void setEmail(string email)
		{
			this->email = email;
		}
		void setNome(string nome)
		{
			this->nome = nome;
		}
		void setTelefone(string telefone)
		{
			this->telefone = telefone;
		}
		void setDtnasc(Data *dtnasc)
		{
			this->dtnasc = dtnasc;
		}
		string getEmail()
		{
			return this->email;
		}
		string getNome()
		{
			return this->nome;
		}
		string getTelefone()
		{
			return this->telefone;
		}
		Data* getDtNasc()
		{
			return this->dtnasc;
		}
		string getContato()
		{
			return "E-mail: " + this->email + " | " +
			       "Nome: " + this->nome + " | " +
			       "Telefone: " + this->telefone + " | " +
			       "Data de nascimento: " + 
   			          to_string(this->dtnasc->getDia()) + "/" +
  			          to_string(this->dtnasc->getMes()) + "/" +
   			          to_string(this->dtnasc->getAno()) + " | " +
   			       "Idade: " + to_string(this->getIdade());
		}
		int getIdade()
		{
			time_t agora = time(0);
			tm* hoje = localtime(&agora);
			Data *dthoje = new Data(hoje->tm_mday, hoje->tm_mon + 1, hoje->tm_year+1900);
			
			int idade = dthoje->getAno() - this->dtnasc->getAno();
			if (this->dtnasc->getMes() > dthoje->getMes())
			{
				idade--;
			}
			else
			{    cout << endl;

				if (this->dtnasc->getMes() == dthoje->getMes() && 
				    this->dtnasc->getDia() > dthoje->getDia())
				{
					idade--;
				}
			}
			return idade;
		}
};

int main(int argc, char** argv)
{
	Contato *contato = new Contato("a", "b", "c", new Data(1,1,2000)); 
    cout << contato->getContato() << endl;
   
    contato->setEmail("novo a");
    contato->setNome("novo b");
    contato->setTelefone("novo c");
    contato->setDtnasc(new Data(10,11,2010));
	
	cout << endl;
    
    cout << "E-mail  : " << contato->getEmail() << endl;
    cout << "Nome    : " << contato->getNome() << endl;
    cout << "Telefone: " << contato->getTelefone() << endl;
    cout << "Dt nasc.: " << contato->getDtNasc()->getData() << endl;
    cout << "Idade   : " << contato->getIdade() << endl;
    //cout << contato->getContato() << endl;
	       
	return 0;
}

