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

void tela_primary()
{
	cbc();

	cout<<"1 - Criar Tabela"<<endl;
	cout<<"2 - Acessar Tabela"<<endl;
	cout<<"3 - Listar Tabela"<<endl;
	cout<<"4 - Sair"<<endl;
	int opc;
	cout<<"Opção:";
	cin>>opc;
	if(opc == 1)
		construtor();
	else if(opc == 3)
		list_tables();


}

