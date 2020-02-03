#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H
#include <vector>
#include "Imovel.h"

class SistemaImobiliaria
{
    private:
     std::vector <Imovel*> imoveis;

    public:
        SistemaImobiliaria();

        void cadastraImovel(Imovel* imoveis);
        std::vector <Imovel*> getImovel();




};

#endif // SISTEMAIMOBILIARIA_H
