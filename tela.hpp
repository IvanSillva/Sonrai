#include <iostream>

#include <string>

#include <fstream>

#include <stdlib.h>

using namespace std;

void cbc();
void tela_primary();
void list_tables();
void tela_tables(string name_archive); 
void open_archive(string name_archive);
void tela_return();
void tela_return_tables(string name_archive);
void tela_search(string name_archive);
void tela_search_value(string name_archive, int value);
void tela_return_search(string name_archive);