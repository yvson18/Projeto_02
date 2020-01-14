#include "Endereco.h"
#include <string>

//-----------Construtor----------------

Endereco::Endereco(std::string logradouro,int numero,std::string bairro,
                   std::string cidade,std::string cep){

    this->logradouro = logradouro;
    this->numero = numero;
    this->bairro = bairro;
    this->cidade = cidade;
    this->cep = cep;

}

Endereco::Endereco(){}

//-------------Gets----------------------

std::string Endereco::getLogradouro(){return this->logradouro;}
int Endereco::getnumero(){return this->numero;}
std::string Endereco::getBairro(){return this->bairro;}
std::string Endereco::getCidade(){return this->cidade;}
std::string Endereco::getCep(){return this->cep;}


//-------------Sets-----------------------

void Endereco::setLogradouro(std::string logradouro){
    this->logradouro = logradouro;
}
void Endereco::setNumero(int numero){
    this->numero = numero;
}
void Endereco::setBairro(std::string bairro){
    this->bairro = bairro;
}
void Endereco::setCidade(std::string cidade){
    this->cidade = cidade;
}
void Endereco::setCep(std::string cep){
    this->cep = cep;
}
