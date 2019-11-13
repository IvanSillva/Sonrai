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
	cout<<"4 - Deletar Tabelas"<<endl;
	cout<<"5 - Sair"<<endl;
	cout<<endl;

	int opc;
	cout<<"Opção: ";
	cin>>opc;

	if(opc == 1)
		construtor();
	else if(opc ==2)
		access_tables();
	else if(opc == 3)
	{
		list_tables();
		tela_return();
	}
	else if(opc == 4)
		delete_tables();
	else if(opc == 5)
		exit(0);


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
		delete_line(name_archive);
	else if(opc == 4)
		//search_line(name_archive);
		cout<<"a";
	else if(opc == 5)
		open_archive(name_archive);
}


void tela_return_tables(string name_archive)
{
	int opc;
	cout<<"1 - Voltar ao Menu          ";
	cout<<"0 - Sair"<<endl;
	cout<<endl;
	cin>>opc;

	if(opc == 1)
	{
		tela_tables(name_archive);
	}
	else
	{
		exit(0);
	}
}


void list_tables()
{	
	cbc();
	system("ls -F -1 Tabelas/");
 	cout << endl;
}


void tela_return()
{

	int opc;
	cout<<"1 - Voltar ao Menu          ";
	cout<<"0 - Sair"<<endl;
	cout<<endl;
	cin>>opc;

	if(opc == 1)
	{
		tela_primary();
	}
	else
	{
		exit(0);
	}

}



void open_archive(string name_archive)
{	
	
	string file = "libreoffice ";
	file += name_archive;
	const char* open = &file[0];
	cout << open;
	system(open);

	cout<<endl;
	cout<<endl;

	 tela_return_tables(name_archive);
}




