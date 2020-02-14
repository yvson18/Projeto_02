#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H
#include <vector>
#include "Imovel.h"

class SistemaImobiliaria
{
    private:
     std::vector <Imovel*> imoveis;

    public:
        SistemaImobiliaria(std::vector <Imovel*> imoveis);

        void cadastraImovel(Imovel* imoveis);
        void removerImovel(std::string);
        std::vector <Imovel*> getImovel();




};

#endif // SISTEMAIMOBILIARIA_H
