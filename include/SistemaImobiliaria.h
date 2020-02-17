#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H
#include <vector>
#include <iostream>
#include <string>
#include "Imovel.h"

class SistemaImobiliaria
{
    private:
     std::vector <Imovel*> imoveis;

    public:
        SistemaImobiliaria(std::vector <Imovel*> imoveis);

        void cadastraImovel(Imovel* imoveis);
        void removerImovel();
        void editarImovel();
        std::vector <Imovel*> getImovel();
        std::vector <Imovel*> BuscarImovel();
        int BuscarPorTitulo();




};

#endif // SISTEMAIMOBILIARIA_H
