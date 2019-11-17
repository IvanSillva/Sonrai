#include <string>
using namespace std;

struct colunas
{
    string name;
    string type;
};

class Tabela 
{
    public:
    string PK;
    string FK;
    int tamcl = 0;
    colunas vetCL[30];


    void setPK(string PK);
    string getPK();

    void setFK(string FK);
    string getFK();

    void setvetCL(colunas vetCL);
    colunas getvetCL(int x);

    int getTamcl();

    void write_file(string archive, string line);

};

void construtor();
void primary_key(string archive);
int verify_archive(string archive);
void access_tables();
void add_line(string archive);
void print_archive(string archive);
void delete_line(string name_archive);
void delete_tables();
void search_line_1(string name_archive, int value);
void search_line_2(string name_archive, int value);
void search_line_3(string name_archive, int value);
void search_line_4(string name_archive, int value);
void search_line_5(string name_archive, int value);
void test_type(string info);