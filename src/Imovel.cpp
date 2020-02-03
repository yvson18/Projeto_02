#include "Imovel.h"
#include <iostream>

Imovel::Imovel(){}

Imovel::Imovel(std::string titulo,Endereco endereco,double valor,
               bool AluguelouVenda,int tipoImovel){

    this->titulo = titulo;
    this->endereco = endereco;
    this->valor = valor;
    this->AluguelouVenda = AluguelouVenda;
    this->tipoImovel = tipoImovel;

}


void Imovel::exibir(){

    std::cout<<"Titulo: "<< titulo << "\n"<<
    "Bairro: " << endereco.getBairro() << "\n" <<
    "Cidade: " << endereco.getCidade() << "\n" <<
    "Valor: " << valor << std::endl;

}

void Imovel::exibirMinimo(){

     std::cout<<"Titulo: "<< titulo << "\n" <<
                "Bairro: " <<endereco.getBairro() << "\n" <<
                "Cidade: " <<endereco.getCidade() << "\n" <<
                "Valor: " << valor << std::endl;

}

void Imovel::editar(){

    int op;
    bool editado = false;

        do{
            std::cout<<"Digite a opcao que deseja mudar\n\n"<<
                   "Titulo-----------------------> 1\n" <<
                   "Endereco---------------------> 2\n" <<
                   "Valor------------------------> 3\n" <<
                   "Aluguel ou Venda-------------> 4\n\n";
            std::cin >> op;



        switch(op){

            case 1:{
                std::string titulo;
                std::cout<<"Digite o novo titulo: ";
                std::cin.ignore();
                getline(std::cin,titulo);
                this->titulo = titulo;
            }
            editado = true;
            break;

            case 2:{
                int op1;
                 std::cout << "Digite qual campo deseja modificar\n\n"<<
                          "Logradouro------------> 1\n"<<
                          "Numero----------------> 2\n"<<
                          "Bairro----------------> 3\n"<<
                          "Cidade----------------> 4\n"<<
                          "Cep-------------------> 5\n\n\n";
                  std::cin >> op1;
                    switch(op1){

                            case 1:{
                                std::string logradouro;
                                std::cout<<"Digite o logradouro: ";
                                std::cin.ignore();
                                getline(std::cin,logradouro);
                                this->endereco.setLogradouro(logradouro);
                            }
                            break;

                            case 2:{
                                int numero;
                                std::cout<<"Digite o numero: ";
                                std::cin>>numero;
                                this->endereco.setNumero(numero);
                            }
                            break;

                            case 3:{
                                std::string bairro;
                                std::cout<<"Digite o bairro: ";
                                std::cin.ignore();
                                getline(std::cin,bairro);
                                this->endereco.setBairro(bairro);
                            }
                            break;

                            case 4:{
                                std::string cidade;
                                std::cout<<"Digite o cidade: ";
                                std::cin.ignore();
                                getline(std::cin,cidade);
                                this->endereco.setCidade(cidade);
                            }
                            break;

                            case 5:{
                                std::string cep;
                                std::cout<<"Digite o cep: ";
                                std::cin.ignore();
                                getline(std::cin,cep);
                                this->endereco.setCep(cep);
                            }
                            break;
                            default:
                                editado = false;
                            break;

                    }



            }

            break;

            case 3:{
                double valor;
                std::cout << "Digite o novo valor: ";
                std::cin >> valor;
                this->valor = valor;
                editado = true;
            }
            break;

            case 4:{
                bool AluguelouVenda;
                std::cout << "Digite 1 para alugado ou 0 para a venda: ";
                std::cin >> AluguelouVenda;
                this->AluguelouVenda = AluguelouVenda;
                editado = true;
            }
            break;

            default:
                std::cout << "Opcao invalida usuario\n";
                editado = false;
            break;
        }

        }while(editado == false);
}

std::string Imovel::getTitulo(){
    return this->titulo;
}
Endereco Imovel::getEndereco(){
    return this->endereco;
}
double Imovel::getValor(){
    return this->valor;
}
bool Imovel::getAluguelouVenda(){
    return this->AluguelouVenda;
}
int Imovel::getTipoImovel(){
    return this->tipoImovel;
}

std::string Imovel::toString(){/*vai ser overridado*/}
