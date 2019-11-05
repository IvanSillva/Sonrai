#include <iostream>

#include <string>

#include <fstream>

#include <stdlib.h>

#include "dtbase.hpp"

using namespace std;

void cbc()
{
	system("clear");
	cout<<"████████████████████████████████████████████\n";
	cout<<"███      █      █  ███  █      █       █  ██\n";
	cout<<"███  █████  ██  █   ██  █  ██  █  ███  █  ██\n";
	cout<<"███      █  ██  █  █ █  █      █       █  ██\n";
	cout<<"███████  █  ██  █  ██   █  █  ██  ███  █  ██\n";
	cout<<"███      █      █  ███  █  ██  █  ███  █  ██\n";
	cout<<"████████████████████████████████████████████\n\n";
}

void list_tables()
{
	ifstream database;
	database.open("database.txt");
	string line;

	while(!database.eof())
	{
		getline(database, line);
		cout << line << endl;
	}
	database.close();
}

void tela_tables(string name_archive)
{
	cbc();
	int opc;

	cout<<"1 - Adicionar"<<endl;
	cout<<endl;

	cout<<"Opção: ";
	cin>>opc;
	cout<<endl;

	if(opc == 1)
		add_line(name_archive);

}

void tela_primary()
{
	cbc();

	cout<<"1 - Criar Tabela"<<endl;
	cout<<"2 - Acessar Tabela"<<endl;
	cout<<"3 - Listar Tabela"<<endl;
	cout<<"4 - Sair"<<endl;
	cout<<endl;

	int opc;
	cout<<"Opção: ";
	cin>>opc;

	if(opc == 1)
		construtor();
	else if(opc ==2)
		access_tables();
	else if(opc == 3)
		list_tables();


}



