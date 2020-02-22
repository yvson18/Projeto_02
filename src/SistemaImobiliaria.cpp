#include "SistemaImobiliaria.h"
#include "stringNosvy.h"

void SistemaImobiliaria::cadastraImovel(Imovel* imoveis){
    this->imoveis.push_back(imoveis);
}

SistemaImobiliaria::SistemaImobiliaria(std::vector <Imovel*> imoveis){
    this -> imoveis = imoveis;
}

std::vector <Imovel*> SistemaImobiliaria::getImovel(){
    return this->imoveis;
}
std::vector <int> SistemaImobiliaria::BuscarIndice(std::string titulo1)
{
    unsigned i = 0; std::vector <int> aux;
    for(i = 0; i < imoveis.size(); i++)
        {
            if(buscaContida(titulo1,imoveis[i]->getTitulo()) == true)
            {
                aux.push_back(i);
            }
        }
        return aux;
}

std::vector <Imovel*> SistemaImobiliaria::BuscarImovel()
{
    int op, avaliador = 0; std::vector <Imovel*> indices;
    std::cout << "\t\t\t\tComo deseja buscar o Imovel?\n" << std::endl;
    std::cout << "\t\t\t\t1 - Por Bairro\n" << "\t\t\t\t2 - Por Cidade\n" << "\t\t\t\t3 - Por Titulo\n" << "\t\t\t\t4 - Por Valor\n" << std::endl;
    std::cin >> op;
    while(!avaliador)
    {
        if(op > 4){
            std::cout << "Digite um numero valido!\n" << std::endl;
            std::cin >> op;
        }else if(op < 0){
            std::cout << "Digite um numero valido:\n" << std::endl;
            std::cin >> op;
        }else if(op <=4 || op >= 1){
            avaliador = 1;
        }
    }
    if(op == 1)
    {
        unsigned int i; std::string bairro1;
        std::cout << "Digite o Bairro:\n" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, bairro1);
        while(!bairro1.compare("\0"))
        {
            std::cout << "Digite um bairro valido!\n" << std::endl;
            std::getline(std::cin, bairro1);
        }
        for(i = 0; i < imoveis.size(); i++)
        {
            if(buscaContida(bairro1,imoveis[i]->getEndereco().getBairro()) == true)
            {

                indices.push_back(imoveis[i]);
            }
        }
    }
    if(op == 2)
    {
        unsigned int i; std::string cidade1;
        std::cout << "Digite a cidade:\n" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, cidade1);
        while(!cidade1.compare("\0"))
        {
            std::cout << "Digite um bairro valido!\n" << std::endl;
            std::getline(std::cin, cidade1);
        }
        for(i = 0; i < imoveis.size(); i++)
        {
            if(buscaContida(cidade1,imoveis[i]->getEndereco().getCidade()) == true)
            {
                indices.push_back(imoveis[i]);
            }
        }
    }
    if(op == 3)
    {
        unsigned int i; std::string titulo1;
        std::cout << "Digite o titulo:\n" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, titulo1);
        while(!titulo1.compare("\0"))
        {
            std::cout << "Digite um bairro valido!\n" << std::endl;
            std::getline(std::cin, titulo1);
        }
        for(i = 0; i < imoveis.size(); i++)
        {
            if(buscaContida(titulo1,imoveis[i]->getTitulo()) == true)
            {
                indices.push_back(imoveis[i]);
            }
        }
    }
    if(op == 4)
    {
        unsigned int i; double valor; int opc;
        std::cout << "Deseja procurar a partir de um certo valor, ou abaixo dele?(Digite 1), (Digite 0)\n" << std::endl;
        std::cin >> opc;
        avaliador = 0;
        while(!avaliador)
        {
            if(opc < 0 || opc >1)
            {
                std::cout << "Digite um numero valido!\n" << std::endl;
                std::cin >> opc;
            }
            if(opc == 0)
            {
                avaliador = 1;
            }
            if(opc == 1)
            {
                avaliador = 1;
            }
        }
        if(opc == 1)
        {
            std::cout << "Digite o valor:\n" << std::endl;
            std::cin >> valor;
            for(i = 0; i < imoveis.size(); i++)
            {
                if((imoveis[i]->getValor()) >= valor)
                {
                    indices.push_back(imoveis[i]);
                }
            }
        }
        if(opc == 0)
        {
            std::cout << "Digite o valor:\n" << std::endl;
            std::cin >> valor;
            for(i = 0; i < imoveis.size(); i++)
            {
                if((imoveis[i]->getValor()) <= valor)
                {
                    indices.push_back(imoveis[i]);
                }
            }
        }
    }
    return indices;
}

void SistemaImobiliaria::removerImovel()
{
    std::vector <Imovel*> imoveis01; int indice, in; unsigned int i; std::vector <int> aux;
    imoveis01 = BuscarImovel();
    for(i = 0; i < imoveis01.size(); i++)
    {
        std::cout << "\n\nImovel encontrado numero: " << i + 1 << "\n" << std::endl;
        imoveis01[i]->exibir();
        Sleep(1000);
    }
    if(imoveis01.size() != 0){
        std::cout << "Qual deseja deletar? Digite de 1 a " << i << "\n" << std::endl;
        std::cin >> indice;

        while(indice < 1 || indice > i+1){
            std::cout << "Digite um numero valido!\n" << std::endl;
            std::cin >> indice;
        }
        in = indice - 1;
        aux = BuscarIndice(imoveis01[indice - 1]->getTitulo());

        if(aux.size() != 0)
        {
            imoveis.erase(imoveis.begin() + aux[in]);
            std::cout << "Imovel Deletado\n" << std::endl;
        }else{
            std::cout << "Operacao falhou, repita a operacao!\n" << std::endl;
        }
    }else{
        std::cout << "Lista Vazia\n" << std::endl;
    }
}
void SistemaImobiliaria::editarImovel()
{
    std::vector <Imovel*> imoveis01; int indice, op; unsigned int i; std::vector <int> aux;
    imoveis01 = BuscarImovel();
    for(i = 0; i < imoveis01.size(); i++)
    {
        std::cout << "\n\nImovel encontrado numero: " << i + 1 << "\n" << std::endl;
        imoveis01[i]->exibir();
        Sleep(1000);
    }
    if(imoveis01.size() != 0){
        if(i>1){
            std::cout << "Qual deseja editar? Digite de 1 a " << i << "\n" << std::endl;
            std::cin >> indice;
        }else if(i == 1){
            indice = 1;
        }

        while(indice < 1 || indice > i+1){
            std::cout << "Digite um numero valido!\n" << std::endl;
            std::cin >> indice;
        }
        aux = BuscarIndice(imoveis01[indice - 1]->getTitulo());

        if(aux.size() != 0)
        {
            imoveis[aux[indice - 1]]->editar();
            std::cout << "Operacao concluida\n" << std::endl;
        }else{
            std::cout << "Operacao falhou, repita a operacao!\n" << std::endl;
        }
    }else{
        std::cout << "Lista Vazia\n" << std::endl;
    }
}
