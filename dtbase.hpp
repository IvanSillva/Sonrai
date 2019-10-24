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
    int tamcl;
    colunas vetCL[3];


    void setPK(string PK);
    string getPK();

    void setFK(string FK);
    string getFK();

    void setvetCL(colunas vetCL);
    colunas getvetCL();

};

void leitura();