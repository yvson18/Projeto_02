#ifndef TERRENO_H
#define TERRENO_H
#include "Imovel.h"
#include "BancoDeDados.h"


class Terreno : public Imovel{

   private:
       double area;

   public:
        Terreno(std::string titulo,Endereco endereco,double valor,
                bool AluguelouVenda,int tipoImovel,double area);

        void exibir()override;
        void editar()override;
        std::string toString()override;

        friend class BancoDeDados;

};

#endif // TERRENO_H
