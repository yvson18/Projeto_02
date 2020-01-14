#ifndef TERRENO_H
#define TERRENO_H
#include "Imovel.h"

class Terreno : public Imovel{

   private:
       double area;

   public:
        Terreno(std::string titulo,Endereco endereco,double valor,
                bool AluguelouVenda,int tipoImovel,double area);

        void exibir()override;
        void editar()override;

};

#endif // TERRENO_H
