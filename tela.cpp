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


}

