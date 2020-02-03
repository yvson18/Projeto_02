#ifndef IMOVEL_H
#define IMOVEL_H
#include "Endereco.h"
#include <string>

class Imovel
{
    protected:
        std::string titulo;
        Endereco endereco;
        double valor;
        bool AluguelouVenda; // true: aluguel | false: venda
        int tipoImovel; // pode assumir 1 para Casa, 2 para Apartamento e 3 Para terreno

    public:
        Imovel();
        Imovel(std::string titulo,Endereco endereco,double valor,bool AluguelouVenda,int tipoImovel);
        virtual void exibir();
        void exibirMinimo();
        virtual void editar();
        virtual std::string toString();

        std::string getTitulo();
        bool getAluguelouVenda();
        Endereco getEndereco();
        double getValor();
        int getTipoImovel();



};

#endif // IMOVEL_H
