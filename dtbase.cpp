#include <iostream>

#include <string>

#include <fstream>

#include <stdlib.h>

#include "dtbase.hpp"

#include "tela.hpp"


void Tabela::setPK(string PK)
{
   this->PK = PK;
}
string Tabela::getPK()
{
    return this->PK;
}

void Tabela::setFK(string FK)
{
   this->FK = FK;
}

string Tabela::getFK()
{
    return this->FK;
}

void Tabela::setvetCL(colunas vetCL)
{

  this->vetCL[this->tamcl] = vetCL;
  this->tamcl = this->tamcl+1;
}

colunas Tabela::getvetCL(int x)
{
  return this->vetCL[x];
}

int Tabela::getTamcl()
{
  return this->tamcl;
}

//=======================================================
void database(string archive){
  ofstream data;
  data.open("database.txt", ios::app);
  data<<archive<<endl;
  data.close();
}

//Cria Arquivo, Adiciona cabeçalho.
void construtor()
{

    ofstream file;
    string name_archive;
    cin.ignore(100, '\n');
    cout << "Digite o nome do Arquivo:";
    getline(cin, name_archive);
    int k = verify_archive(name_archive);
    while(k == 1){
      cout << "Arquivo já existente, digite outro:";
      getline(cin, name_archive);
      k = verify_archive(name_archive);
    }
    name_archive+=".csv";
    file.open(name_archive, ios::app);

    primary_key(name_archive);

    cout << "Digite o numero de colunas:";
    int x;
    cin >> x; 

    colunas temp[x];

    

    for(int i=0; i<x; i++)
    {
      cout << "Digite o nome da " << i+1 <<"º coluna:";
      cin >> temp[i].name;
      cout << "Digite o tipo da " << i+1 <<"º coluna:";
      cin >> temp[i].type;
    }



Tabela teste;

    for(int i=0; i<x; i++){
    teste.setvetCL(temp[i]);
  }

    for(int i=0;i<teste.getTamcl();i++)
    {
          file<<teste.getvetCL(i).name<<"("<<teste.getvetCL(i).type<<")";
          if(i+1!=teste.getTamcl()){
            file<<",";
          }
    }
    database(name_archive);
    file.close();
 
}

int verify_archive(string archive)
{ 
  archive += ".csv";
  ifstream verify;
  verify.open("database.txt");
  string line;
  while(!verify.eof())
  {
    getline(verify, line);
    if(line == archive)
      return 1;
  }
  verify.close();
   return 0;
}


void primary_key(string archive)
{
    
    string pk;

    cout<<"Digite o nome da Chave Primaria: ";
    cin>>pk;

    ofstream file;
    file.open(archive);

    file<<pk<<"(unsigned),";
    file.close();
}
