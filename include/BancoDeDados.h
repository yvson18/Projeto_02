#ifndef BANCODEDADOS_H
#define BANCODEDADOS_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Imovel.h"

extern std::vector <Imovel*> toStringtoVector(std::vector <std::string> conteudo);

class BancoDeDados{

    public:
        BancoDeDados(){ }

        int numero();

        void salvarArquivo(std::vector <Imovel*> imoveis);
        void lerArquivo();
};



#endif // BANCODEDADOS_H
