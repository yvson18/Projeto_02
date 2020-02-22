#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H
#include <vector>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "Imovel.h"

class SistemaImobiliaria
{
    private:
     std::vector <Imovel*> imoveis;
     std::vector <int> BuscarIndice(std::string);

    public:
        SistemaImobiliaria(std::vector <Imovel*> imoveis);

        void cadastraImovel(Imovel* imoveis);
        void removerImovel();
        void editarImovel();
        std::vector <Imovel*> getImovel();
        std::vector <Imovel*> BuscarImovel();

};

#endif // SISTEMAIMOBILIARIA_H
