#include <iostream>
#include <vector>
#include <string>

//bibliotecas puramente estéticas
#include <stdio.h>
#include <stdlib.h>

//headers
#include "Casa.h"
#include "Apartamento.h"
#include "Terreno.h"
#include "BancoDeDados.h"
#include "SistemaImobiliaria.h"

using namespace std;

void ApresentaMenu()
{
    cout << "\t\t\t\t---MENU----\n" << "\t\t\t---O que deseja fazer?---" << endl;
    cout << "\t\t\t1 = Cadastrar Imovel" << endl;
    cout << "\t\t\t2 - Listar Imoveis" << endl;
    cout << "\t\t\t3 - Buscar" << endl;
    cout << "\t\t\t4 - Remover Imovel" << endl;
    cout << "\t\t\t5 - Editar Imovel" << endl;
    cout << "\t\t\t6 - Salvar" << endl;
    cout << "\t\t\t7 - Sair\n" << endl;
}

int main(){



    int i;
    vector <Imovel*> imoveis;
    BancoDeDados b1;


    imoveis = b1.lerArquivo();

    //imoveis[0]->exibir();

    SistemaImobiliaria s1(imoveis);

    ApresentaMenu();
    cin >> i;

    while(i<7)
    {
        if(i == 1)
        {
            Imovel *I1;
            string logradouro, bairro, cidade, cep; int num1;
            //----------------------------------------------------------------
            cout << "Digite o endereco:\n" << endl;
            //----------------------------------------------------------------
            cout << "Logradouro:\n" << endl;
            cin.ignore();
            getline(cin, logradouro);
            //----------------------------------------------------------------
            cout << "Numero:\n" << endl;
            cin >> num1;
            //----------------------------------------------------------------
            cout << "Bairro:\n" << endl;
            cin.ignore();
            getline(cin, bairro);
            //----------------------------------------------------------------
            cout << "Cidade:\n" << endl;
            getline(cin, cidade);
            //----------------------------------------------------------------
            cout << "Cep:\n" << endl;
            getline(cin, cep);
            //----------------------------------------------------------------
            Endereco E1(logradouro, num1, bairro, cidade, cep);
            //Agora o Imovel em si

            string titulo; double valor; bool AluguelOuVenda; int tipoDeImovel;
            //----------------------------------------------------------------
            cout << "Agora o Imovel:\n" << endl;
            cout << "Digite o Titulo:\n" << endl;
            getline(cin, titulo);
            //----------------------------------------------------------------
            cout << "Valor:\n" << endl;
            cin >> valor;
            //----------------------------------------------------------------
            cout << "Vai alugar? (Digite 1), vai vender? (Digite 2)\n" << endl;
            int op;
            cin >> op;
            if(op == 1)
                AluguelOuVenda = true;
            if(op == 2)
                AluguelOuVenda = false;
            //----------------------------------------------------------------
            cout << "Qual o tipo de Imovel?\n" << endl;
            cout << "Casa---------> 01\nApartamento---------> 02\nTerreno--------->03\n" << endl;
            cin >> tipoDeImovel;
            //----------------------------------------------------------------
            if(tipoDeImovel == 1)
            {
                int numPavimentos, numQuartos; double areaTerreno, areaConstruida;
                //----------------------------------------------------------------
                cout << "Quantos pavimentos na casa?\n" << endl;
                cin >> numPavimentos;
                //----------------------------------------------------------------
                cout << "Quantos quartos?\n" << endl;
                cin >>numQuartos;
                //----------------------------------------------------------------
                cout << "Qual a area do terreno?\n" << endl;
                cin >> areaTerreno;
                //----------------------------------------------------------------
                cout << "Qual a area construida desse terreno?\n" << endl;
                cin >> areaConstruida;
                //----------------------------------------------------------------
                I1 = new Casa(titulo, E1, valor, AluguelOuVenda, tipoDeImovel,
                                           numPavimentos, numQuartos,
                                           areaTerreno, areaConstruida);
                //----------------------------------------------------------------
                s1.cadastraImovel(I1);
            }
            else if(tipoDeImovel == 2)
            {
                string posicao; int numQuartos, vagasGaragem; double valorCondominio, area;
                //----------------------------------------------------------------
                cout << "Qual a posicao do apartamento?\n" << endl;
                cin.ignore();
                getline(cin, posicao);
                //----------------------------------------------------------------
                cout << "Quantos quartos tem?\n" << endl;
                cin >> numQuartos;
                //----------------------------------------------------------------
                cout << "Qual o valor do condominio?\n" << endl;
                cin >> valorCondominio;
                //----------------------------------------------------------------
                cout << "Quantas vagas na garagem?\n" << endl;
                cin >> vagasGaragem;
                //----------------------------------------------------------------
                cout << "Qual a area do imovel?\n" << endl;
                cin >> area;
                //----------------------------------------------------------------
                I1 = new Apartamento(titulo, E1, valor, AluguelOuVenda, tipoDeImovel,
                                                  posicao, numQuartos,valorCondominio,
                                                  vagasGaragem, area);
                //----------------------------------------------------------------
                s1.cadastraImovel(I1);
            }
            else if(tipoDeImovel == 3)
            {
                double area;
                //----------------------------------------------------------------
                cout << "Digite a area do terreno:\n" << endl;
                cin >> area;
                //----------------------------------------------------------------
                I1 = new Terreno(titulo, E1, valor, AluguelOuVenda, tipoDeImovel, area);
                //----------------------------------------------------------------
                s1.cadastraImovel(I1);
            }else{
                cout << "Digite um numero valido! (1 a 3)\n" << endl;
            }

        }
        if(i == 2)
        {
            unsigned int contador;
            imoveis = s1.getImovel();
            //cout << imoveis.size();
            //imoveis[0]->exibir();

            //----------------------------------------------------------------
            for(contador = 0; contador < imoveis.size(); contador ++)
            {
                imoveis[contador]->exibir();
            }
        }

        if(i == 3)
        {
            cout << "So quando marcos terminar, aquele homo, sexo, uau\n" << endl;
            break;
        }
        if(i == 4)
        {
            string titulo1;
            //----------------------------------------------------------------
            cout << "Digite o titulo do imovel que quer deletar:\n" << endl;
            cin.ignore();
            getline(cin, titulo1);
            //----------------------------------------------------------------
            s1.removerImovel(titulo1);
        }
        if(i == 5)
        {
            cout << "So quando marcos terminar, aquele homo, sexo, uau\n" << endl;
            break;
        }
        if(i == 6)
        {
            b1.salvarArquivo(imoveis);
            cout << "Arquivo Salvo\n" << endl;
        }
        ApresentaMenu();
        cin >> i;
    }
    system("pause");
    return 0;
}

