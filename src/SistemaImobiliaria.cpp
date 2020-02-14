#include "SistemaImobiliaria.h"
#include <vector>

void SistemaImobiliaria::cadastraImovel(Imovel* imoveis){
    this->imoveis.push_back(imoveis);
}

SistemaImobiliaria::SistemaImobiliaria(std::vector <Imovel*> imoveis){
    this -> imoveis = imoveis;
}

std::vector <Imovel*> SistemaImobiliaria::getImovel(){
    return this->imoveis;
}

void SistemaImobiliaria::removerImovel(std::string titulo)
{
    unsigned int contador, aux2;
    for(contador = 0; contador < imoveis.size(); contador++)
            {
                if(titulo.compare(imoveis[contador]->getTitulo()) == 0)
                {
                    aux2 = contador;
                    break;
                }
            }
            imoveis.erase(imoveis.begin()+aux2);
}
