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

};

void construtor();