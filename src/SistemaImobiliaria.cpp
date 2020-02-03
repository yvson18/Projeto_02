#include "SistemaImobiliaria.h"

void SistemaImobiliaria::cadastraImovel(Imovel* imoveis){
    this->imoveis.push_back(imoveis);
}

SistemaImobiliaria::SistemaImobiliaria(){

}

std::vector <Imovel*> SistemaImobiliaria::getImovel(){
    return this->imoveis;
}
