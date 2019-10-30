#include <iostream>

#include <string>

#include <fstream>

#include <stdlib.h>

#include "dtbase.hpp"


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
  cout<<this->vetCL[this->tamcl].name<<endl;
  cout<<this->vetCL[this->tamcl].type<<endl;
  this->tamcl = this->tamcl+1;
  cout<<this->tamcl<<endl;
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

void construtor()
{

    ofstream file;
    string name_archive;
    cout << "Digite o nome do Arquivo:";
    getline(cin, name_archive);
    file.open(name_archive);

    cout << "Digite o numero de colunas:";
    int x;
    cin >> x; 

    colunas temp[x];

    for(int i=0; i<x; i++){
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
          file<<teste.getvetCL(i).name<<"("<<teste.getvetCL(i).type<<")"<<",";
    }
    
    file.close();
 
}

