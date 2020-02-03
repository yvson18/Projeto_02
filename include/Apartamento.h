#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Imovel.h"
#include "BancoDeDados.h"

class Apartamento : public Imovel{

   private:
       std::string posicao;
       int numQuartos,vagasGaragem;
       double valorCondominio,area;
   public:
        Apartamento(std::string titulo,Endereco endereco,double valor,bool AluguelouVenda,
                    int tipoImovel,std::string posicao,int numQuartos,double valorCondominio,
                    int vagasGaragem,double area);
        void exibir()override;
        void editar()override;
        std::string toString()override;

        friend class BancoDeDados;

};

#endif // APARTAMENTO_H
