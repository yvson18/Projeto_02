#ifndef ENDERECO_H
#define ENDERECO_H
#include <string>

class Endereco
{
    private:
        std::string logradouro;
        int numero;
        std::string bairro;
        std::string cidade;
        std::string cep;
    public:
//----------Construtor-----------
        Endereco(std::string,int,std::string,std::string,std::string);
        Endereco();


//----------Gets------------------
        std::string getLogradouro();
        int getnumero();
        std::string getBairro();
        std::string getCidade();
        std::string getCep();
//----------Sets------------------

        void setLogradouro(std::string logradouro);
        void setNumero(int numero);
        void setBairro(std::string bairro);
        void setCidade(std::string cidade);
        void setCep(std::string cep);

//---------Destrutor--------------
        ~Endereco(){}
};

#endif // ENDERECO_H
