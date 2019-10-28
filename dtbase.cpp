#include <iostream>

#include <string>

#include <fstream>

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
    colunas test[2];
    test[0].name = "Jorge";
    test[0].type = "int";
    test[1].name = "Ivan";
    test[1].type = "float";

    Tabela teste;
    teste.setvetCL(test[0]);
    teste.setvetCL(test[1]);


    ofstream file;
    file.open("data.csv");



    for(int i=0;i<teste.getTamcl();i++)
    {
          string temp = teste.getvetCL(i).name;
          file<<temp<<",";
    }

    file.close();

    /*Roteador* r1 = new Roteador();r1->setIP("192.168.0.1");
    Roteador* r2 = new Roteador();r2->setIP("192.168.0.2");
    Roteador* r3 = new Roteador();r3->setIP("192.168.0.3");
    Roteador* r4 = new Roteador();r4->setIP("192.168.0.4");
    Roteador* r5 = new Roteador();r5->setIP("192.168.0.5");
    Roteador* r6 = new Roteador();r6->setIP("192.168.0.6");
    Roteador* r7 = new Roteador();r7->setIP("192.168.0.7");
    Roteador* r8 = new Roteador();r8->setIP("192.168.0.8");
    Roteador* r9 = new Roteador();r9->setIP("192.168.0.9");

    Roteador* Mat[3][3];
    Mat[0][0] = r1; Mat[0][1] = r2; Mat[0][2] = r3;
    Mat[1][0] = r4; Mat[1][1] = r5; Mat[1][2] = r6;
    Mat[2][0] = r7; Mat[2][1] = r8; Mat[2][2] = r9;

    ifstream leitura;
    leitura.open("comunicação.txt");

    string origem;
    string destino;
    string qtd;
    string info;

    while(!leitura.eof()){
      leitura >> origem;
      leitura >> destino;
      leitura >> qtd;
      int qtdI = stoi(qtd);
      leitura >> info;
      cout << destino[10] << endl;
      Pacote pct[qtdI];
      for(int i = 0; i < qtdI; i++)
      {     
        //Setando cabeçalho
            if(i == 0){
                pct[0].cabecalho = 1;
            }else{
                 pct[i].cabecalho = 0;
            }
        //Setando terminador
            if(i == qtdI-1)
            {
                pct[i].terminador = 1;
            }else{
                pct[i].terminador = 0;
            }
        //Setando Dados
            pct[i].dados = info;
        //Setando Destino
            pct[i].destino = destino;
      }

      for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
          if(origem == Mat[i][j]->getIP()){
            for(int k = 0; k<qtdI; k++){
            Mat[i][j]->buffers.push(pct[k]);
            }
          }
        }
      }
    }
	leitura.close();*/





    
}

