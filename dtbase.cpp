#include <iostream>

#include <stdio.h>

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

void Tabela::write_file(string archive, string line)
{
    ofstream write;
    write.open(archive, ios::app);

    write<<line<<",";

    write.close();

}

//=======================================================

//Cria Arquivo, Adiciona cabeçalho.

void construtor()
{
    cbc();
    ofstream file;
    string name_archive;
    string archive = "Tabelas/";
    cin.ignore(100, '\n');
    cout << "Digite o nome do Arquivo: ";
    getline(cin, name_archive); cout<<endl;
    archive += name_archive;

    
    archive+=".csv";
    file.open(archive, ios::app);

    primary_key(archive);

    cout << "Digite o numero de colunas: ";
    int x;
    cin >> x; 

    colunas temp[x];
    cin.ignore(100, '\n');
    for(int i=0; i<x; i++)
    { 
      cout << "Digite o nome da " << i+1 <<"º coluna: ";
      getline(cin, temp[i].name);
      cout << "Digite o tipo da " << i+1 <<"º coluna: ";
      getline(cin, temp[i].type);
    }


    Tabela teste;

    for(int i=0; i<x; i++)
    {
      teste.setvetCL(temp[i]);
    }

    for(int i=0;i<teste.getTamcl();i++)
    {
      file<<teste.getvetCL(i).name<<"("<<teste.getvetCL(i).type<<"),";
  
      }
      file<<endl;
      file.close();

      tela_primary();
 
}


void primary_key(string archive)
{
    
    string pk;

    cout<<"Digite o nome da Chave Primaria: ";
    getline(cin,pk);

    ofstream file;
    file.open(archive);

    file<<pk<<"(unsigned),";
    file.close();

}

void add_line(string archive)
{   
    cbc();
    ofstream write;
    write.open(archive, ios::app);
  
    ifstream scanner;
    string line;
    scanner.open(archive);
    cin.ignore(100, '\n');
    getline(scanner, line);
    int coutt = 0;
    string temp;

    Tabela w_file;

    for(int i = 0 ; i<line.length(); i++){
        if(line[i] != ','){
        temp += line[i];   
        }else if(line[i] == ','){
          string infile;
          cout << "Digite " << temp << ": ";
          getline(cin, infile);
          w_file.write_file(archive,infile);
          temp.clear();
        }
       
    }

    write << endl;
    scanner.close();
    write.close();

    cout<<endl;


    tela_return_tables(archive);

}

void access_tables()
{
    cbc();
    string name_archive;
    string archive = "Tabelas/";
    cout << "Digite o nome da Tabela: ";
    cin.ignore(100, '\n');
    getline(cin, name_archive);cout<<endl;
    archive += name_archive;
    cout<< archive << endl;
    archive+=".csv";
    fstream Archive;
    Archive.open(archive);

     while(!Archive)
    { 
      cout << "Arquivo não existente, digite outro: ";
      archive.clear();
      archive = "Tabelas/";
      getline(cin, name_archive);
      archive += name_archive;
      archive +=".csv";
      Archive.open(archive,ios_base::in);
    }    
    
    Archive.close();


    tela_tables(archive);

}

void print_archive(string archive)
{   
    cbc();
    ifstream print;
    print.open(archive);
    string line;
    cout<<"███████████████████████████████████████████████████████"<< endl << endl;
    while(!print.eof())
  {
    getline(print, line);
    cout << line << endl;
  }
    cout<<"███████████████████████████████████████████████████████" << endl << endl;
   tela_return_tables(archive);
}


void delete_line(string name_archive)
{  
  string archive = "Tabelas/";

  ifstream Archive;

  archive += name_archive;

  Archive.open(name_archive);

  string info;

  cout << "Digite a Matricula:" << endl;
  cin.ignore(100, '\n');
  getline(cin, info);

  ofstream ArchiveTemp;
  ArchiveTemp.open("Tabelas/NULL.csv", ios::app);

  while(!Archive.eof()){
    string line;
    string valor;
    getline(Archive, line);
    for(int i = 0; i<line.length() ; i++){ 
      if(line[i] == ','){
       
        if(valor == info)
        { 
        }else{
          ArchiveTemp << line << endl;
        }
        break;
      }else{
        valor += line[i];
      }
    }
  }

  ArchiveTemp.close();
  Archive.close();
  cout << archive << "==========";

  const char* Delete = &archive[0];

  remove(Delete);
 

  string file = "mv Tabelas/NULL.csv ";
  file+=name_archive;

  const char* rename = &file[0];

  system(rename);


  
}

void delete_tables()
{
  list_tables();

  string table;
  string archive = "Tabelas/";

  cout<<"Qual Tabela deseja deletar? ";
  cin.ignore(100, '\n');
  getline(cin, table);

  archive+=table;


  const char* Delete = &archive[0];


  remove(Delete);


}
void search_line_1(string name_archive, int value)
{   
    fstream search;
    search.open(name_archive);
    string line;
    string temp;
    string str;
    cout<<"Informe o Valor: ";
    cin.ignore(100, '\n');
    getline(cin, str);

    int flag=0, result=0;

    cout<<endl;

    while(!search.eof())
    {
        int n = 0;
        getline(search, line);
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ',')
            {
                n++;

                if(temp > str && n == value)
                {
                    if(flag ==0)
                    { 

                      cout<<"Resultados da Pesquisa: "<<endl;

                    }
                    cout << line <<  endl;
                    flag++;
                    result++;
                }
                temp.clear();
            }
            else
            {
                temp += line[i];
            }
        }
    }

    search.close();

    if(flag == 0)
    {   
        cout<<endl;
        cout<<"Não foram encontrados resultados para o valor informado!"<<endl;
    }

    tela_return_search(name_archive);

}

void search_line_2(string name_archive, int value)
{   
    fstream search;
    search.open(name_archive);
    string line;
    string temp;
    string str;
    cout<<"Informe o Valor: ";
    cin.ignore(100, '\n');
    getline(cin, str);

    int flag=0, result=0;

    cout<<endl;

    while(!search.eof())
    {
        int n = 0;
        getline(search, line);
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ',')
            {
                n++;

                if(temp >= str && n == value)
                {
                    if(flag ==0)
                    { 

                      cout<<"Resultados da Pesquisa: "<<endl;

                    }
                    cout << line <<  endl;
                    flag++;
                    result++;
                }
                temp.clear();
            }
            else
            {
                temp += line[i];
            }
        }
    }

    search.close();

    if(flag == 0)
    {   
        cout<<endl;
        cout<<"Não foram encontrados resultados para o valor informado!"<<endl;
    }

    tela_return_search(name_archive);
}

void search_line_3(string name_archive, int value)
{   
    fstream search;
    search.open(name_archive);
    string line;
    string temp;
    string str;
    cout<<"Informe o Valor: ";
    cin.ignore(100, '\n');
    getline(cin, str);

    int flag=0, result=0;

    cout<<endl;

    while(!search.eof())
    {
        int n = 0;
        getline(search, line);
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ',')
            {
                n++;

                if(temp == str && n == value)
                {
                    if(flag ==0)
                    { 

                      cout<<"Resultados da Pesquisa: "<<endl;

                    }
                    cout << line <<  endl;
                    flag++;
                    result++;
                }
                temp.clear();
            }
            else
            {
                temp += line[i];
            }
        }
    }

    search.close();

    if(flag == 0)
    {   
        cout<<endl;
        cout<<"Não foram encontrados resultados para o valor informado!"<<endl;
    }

    tela_return_search(name_archive);
}

void search_line_4(string name_archive, int value)
{   
    fstream search;
    search.open(name_archive);
    string line;
    string temp;
    string str;
    cout<<"Informe o Valor: ";
    cin.ignore(100, '\n');
    getline(cin, str);

    int flag=0, result=0;

    cout<<endl;

    while(!search.eof())
    {
        int n = 0;
        getline(search, line);
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ',')
            {
                n++;

                if(temp < str && n == value)
                {
                    if(flag ==0)
                    { 

                      cout<<"Resultados da Pesquisa: "<<endl;

                    }
                    cout << line <<  endl;
                    flag++;
                    result++;
                }
                temp.clear();
            }
            else
            {
                temp += line[i];
            }
        }
    }

    search.close();

    if(flag == 0)
    {   
        cout<<endl;
        cout<<"Não foram encontrados resultados para o valor informado!"<<endl;
    }

    tela_return_search(name_archive);
}

void search_line_5(string name_archive, int value)
{   
    fstream search;
    search.open(name_archive);
    string line;
    string temp;
    string str;
    cout<<"Informe o Valor: ";
    cin.ignore(100, '\n');
    getline(cin, str);

    int flag=0, result=0;

    cout<<endl;

    while(!search.eof())
    {
        int n = 0;
        getline(search, line);
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ',')
            {
                n++;

                if(temp <= str && n == value)
                {
                    if(flag ==0)
                    { 

                      cout<<"Resultados da Pesquisa: "<<endl;

                    }
                    cout << line <<  endl;
                    flag++;
                    result++;
                }
                temp.clear();
            }
            else
            {
                temp += line[i];
            }
        }
    }

    search.close();

    if(flag == 0)
    {   
        cout<<endl;
        cout<<"Não foram encontrados resultados para o valor informado!"<<endl;
    }

    tela_return_search(name_archive);
}