#ifndef CASA_H
#define CASA_H
#include "Imovel.h"


class Casa : public Imovel{

    private:
        int numPavimentos, numQuartos;
        double areaTerreno, areaConstruida;

    public:
        Casa();
        Casa(std::string titulo,Endereco endereco,double valor,bool AluguelouVenda,int tipoImovel,
             int numPavimentos,int numQuartos,double areaTerreno,double areaConstruida);

        void exibir()override;
        void editar()override;
        std::string toString()override;

        friend class BancoDeDados;



};

#endif // CASA_H
