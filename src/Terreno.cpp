#include "Terreno.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Terreno::Terreno(std::string titulo,Endereco endereco,double valor,
                bool AluguelouVenda,int tipoImovel,double area)

        :Imovel(titulo,endereco,valor,AluguelouVenda,tipoImovel){

        this->area = area;
}

void Terreno::exibir(){

    std::string categoria;

    if(AluguelouVenda == true){
        categoria = "Alugar";
    }else{
        categoria = "Vender";
    }

    std::cout <<"Titulo: " << titulo << "\n"
              <<"Categoria: "<< categoria <<"\n"
              <<"Logradouro: "<< endereco.getLogradouro() << "\n"
              <<"Bairro: " << endereco.getBairro() << "\n"
              <<"Numero: " << endereco.getnumero() << "\n"
              <<"Cidade: " <<endereco.getCidade() << "\n"
              <<"Valor: " << valor << "\n"
              <<"Area: " << area << std::endl;
}

void Terreno::editar(){

    int op;
    bool editado = false;

        do{
            std::cout<<"Digite a opcao que deseja mudar\n\n"<<
                   "Titulo-----------------------> 1\n" <<
                   "Endereco---------------------> 2\n" <<
                   "Valor------------------------> 3\n" <<
                   "Aluguel ou Venda-------------> 4\n" <<
                   "Area-------------------------> 5\n\n";
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

            case 5:{
                double area;
                std::cout << "Digite o valor da nova area: ";
                std:: cin >> area;
                this->area = area;
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

std::string Terreno::toString(){

        std::stringstream buffer;

        buffer << this->titulo << "\n" << this->endereco.getLogradouro() << "\n" <<
        this->endereco.getnumero() << "\n" << this->endereco.getBairro() << "\n" <<
        this->endereco.getCidade() << "\n" << this->endereco.getCep() << "\n"<< std::fixed <<
        std::setprecision(2)<<this->valor << "\n" << this->AluguelouVenda << "\n" << this->tipoImovel <<"\n"<<
        this->area << "\n";

    return buffer.str();

}


