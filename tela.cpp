#include <iostream>

#include <string>

#include <string.h>

#include <fstream>

#include <stdlib.h>

#include "dtbase.hpp"

#include "tela.hpp"

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
	else if(opc == 4)
		exit(0);


}

void list_tables()
{
	cbc();
	cout<<"TABELAS"<<endl;
	ifstream database;
	cout<<endl;
	database.open("database.txt");
	string line;

	while(!database.eof())
	{
		getline(database, line);
		cout << line << endl;
	}
	
	database.close();

	tela_return();

}

void tela_return()
{

	int opc;
	cout<<"1 - Voltar ao Menu"<<endl;
	cout<<"0 - Sair"<<endl;
	cout<<endl;
	cin>>opc;

	if(opc == 1)
	{
		tela_tables();
	}
	else
	{
		exit(0);
	}

}

void tela_return_tables()
{
	int opc;
	cout<<"1 - Voltar ao Menu"<<endl;
	cout<<"0 - Sair"<<endl;
	cout<<endl;
	cin>>opc;

	if(opc == 1)
	{
		tela_tables();
	}
	else
	{
		exit(0);
	}
}

void tela_tables(string name_archive)
{
	cbc();
	int opc;

	cout<<"1 - Adicionar"<<endl;
	cout<<"2 - Printar Tabela" << endl;
	cout<<"3 - Deletar Valores"<<endl;
	cout<<"4 - Pesquisar Valor"<<endl;
	cout<<"5 - Abrir Tabela em Planilha"<<endl;
	cout<<endl;

	cout<<"\nOpção: ";
	cin>>opc;
	cout<<endl;

	if(opc == 1)
		add_line(name_archive);
	else if(opc == 2)
		print_archive(name_archive);
	else if(opc == 3)
		//delete_line(name_archive);
		cout << "a";
	else if(opc == 4)
		//search_line(name_archive);
		cout<<"a";
	else if(opc == 5)
		open_archive(name_archive);
}

void open_archive(string name_archive)
{	
	
	string file = "libreoffice ";
	file += name_archive;
	const char* open = &file[0];
	cout << open;
	system(open);

	 tela_return_tables();
}




