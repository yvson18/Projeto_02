#include <iostream>
#include <vector>
#include <string>

//bibliotecas puramente estéticas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>]

//headers
#include "Casa.h"
#include "Apartamento.h"
#include "Terreno.h"
#include "BancoDeDados.h"
#include "SistemaImobiliaria.h"

using namespace std;
int saida = 0;

void ApresentaMenu()
{
    cout << "\t\t\t\t---BEM VINDO A MATRIX---\n" << endl;
    cout << "\t\t\t\t\t---MENU---\n" << "\t\t\t\t---O que deseja fazer?---" << endl;
    cout << "\t\t\t\t1 = Cadastrar Imovel" << endl;
    cout << "\t\t\t\t2 - Listar Imoveis" << endl;
    cout << "\t\t\t\t3 - Buscar" << endl;
    cout << "\t\t\t\t4 - Remover Imovel" << endl;
    cout << "\t\t\t\t5 - Editar Imovel" << endl;
    cout << "\t\t\t\t6 - Salvar" << endl;
    cout << "\t\t\t\t7 - Sair\n" << endl;
}

int main(){

    system("color 0A");

    int i;
    vector <Imovel*> imoveis;
    BancoDeDados b1;

    imoveis = b1.lerArquivo();

    SistemaImobiliaria s1(imoveis);

    ApresentaMenu();
    cin >> i;
    system("cls");
    while(i<=7)
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
            //Agora o Imovel em si--------------------------------------------
            string titulo; double valor; bool AluguelOuVenda; int tipoDeImovel = 0;
            //----------------------------------------------------------------
            system("cls");
            cout << "Agora o Imovel:\n" << endl;
            cout << "Digite o Titulo:\n" << endl;
            getline(cin, titulo);
            //----------------------------------------------------------------
            cout << "Valor:\n" << endl;
            cin >> valor;
            //----------------------------------------------------------------
            cout << "Vai alugar? (Digite 1), vai vender? (Digite 2)\n" << endl;
            int op, avaliador = 0;
            cin >> op;
            while(!avaliador){
                if(op < 1 || op > 2){
                    cout << "Digite um numero valido!\n" << endl;
                    cin >> op;
                }
                if(op == 1){
                    AluguelOuVenda = true; avaliador = 1;
                }
                if(op == 2){
                    AluguelOuVenda = false; avaliador = 1;
                }
            }
            //----------------------------------------------------------------
            cout << "Qual o tipo de Imovel?\n" << endl;
            cout << "Casa---------> 01\nApartamento---------> 02\nTerreno--------->03\n" << endl;
            cin >> tipoDeImovel;
            avaliador = 0;
            while(!avaliador)
            {
                if(tipoDeImovel > 3 || tipoDeImovel < 1){
                    cout << "Digite um numero valido!\n" << endl;
                    cin >> tipoDeImovel;
                }else{avaliador = 1;}
            }
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
                /*-----------------------*/numPavimentos, numQuartos,
                /*----------------------*/ areaTerreno, areaConstruida);
                //----------------------------------------------------------------
                s1.cadastraImovel(I1);
                //----------------------------------------------------------------
                system("cls");
                cout << "Imovel Cadastrado\n" << endl;
                Sleep(2000);
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
                /*------------------------------*/posicao, numQuartos,valorCondominio,
                /*------------------------------*/vagasGaragem, area);
                //----------------------------------------------------------------
                s1.cadastraImovel(I1);
                //----------------------------------------------------------------
                system("cls");
                cout << "Imovel Cadastrado\n" << endl;
                Sleep(2000);
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
                //----------------------------------------------------------------
                system("cls");
                cout << "Imovel Cadastrado\n" << endl;
                Sleep(2000);
            }else{
                cout << "Digite um numero valido! (1 a 3)\n" << endl;
            }

        }
        if(i == 2)
        {
            int tipoLista;
            imoveis = s1.getImovel();

            cout << "       Digite o tipo de listagem\n\n\n";
            cout <<"        Listar todos os imoveis--> 1\n";
            cout <<"        Listar pelo tipo---------> 2\n";
            cout <<"        Listar pela categoria(Aluguel/Venda)--> 3\n";
            cin >> tipoLista;
            while(tipoLista < 1 || tipoLista > 3)
            {
                cout << "Digite um numero valido!\n" << endl;
                cin >> tipoLista;
            }
            system("cls");

                if(tipoLista == 1){
                    for(int i = 0; i<imoveis.size(); i++){
                        imoveis[i]->exibir();
                        cout << "\n\n";
                        Sleep(1000);
                    }
                    if(imoveis.size() == 0)
                        cout << "Lista Vazia!\n" << endl;
                    system("pause");
                    system("cls");
                }
                if(tipoLista == 2){

                    int tipoDeImovel;

                    cout << "Digite o tipo de imovel a ser exibido\n\n"<< endl;
                    cout << "Digite 1 para exibir as Casas"<< endl;
                    cout << "Digite 2 para exibir os Apartamentos"<< endl;
                    cout << "Digite 3 para exibir os Terreno"<< endl;

                    cin >> tipoDeImovel;
                    while(tipoDeImovel < 1 || tipoDeImovel > 3)
                    {
                        cout << "Digite um numero valido!\n" << endl;
                        cin >> tipoDeImovel;
                    }

                    system("cls");

                        if(tipoDeImovel == 1){ // tipo casa

                            for(int i = 0; i<imoveis.size(); i++){
                                if(imoveis[i]->getTipoImovel() == 1){
                                    imoveis[i]->exibir();
                                    cout << "\n\n";
                                    Sleep(1000);
                                }
                            }
                            if(imoveis.size() == 0)
                                cout << "Lista Vazia!\n" << endl;
                            system("pause");
                            system("cls");
                        }

                        if(tipoDeImovel == 2){ // tipo apartamento

                            for(int i = 0; i<imoveis.size(); i++){
                                if(imoveis[i]->getTipoImovel() == 2){
                                    imoveis[i]->exibir();
                                    cout << "\n\n";
                                    Sleep(1000);
                                }
                            }
                            if(imoveis.size() == 0)
                                cout << "Lista Vazia!\n" << endl;
                            system("pause");
                            system("cls");

                        }

                        if(tipoDeImovel == 3){ // tipo terreno
                            for(int i = 0; i<imoveis.size(); i++){
                                if(imoveis[i]->getTipoImovel() == 3){
                                    imoveis[i]->exibir();
                                    cout << "\n\n";
                                    Sleep(1000);
                                }
                            }
                            if(imoveis.size() == 0)
                                cout << "Lista Vazia!\n" << endl;
                            system("pause");
                            system("cls");
                        }

                }
                if(tipoLista == 3){
                   int tipoCategoria;

                   cout << "Digite 1 para exibir imoveis para Alugar" << endl;
                   cout << "Digite 2 para exibir imoveis para Vender" << endl;
                   cin >> tipoCategoria;
                   while(tipoCategoria < 1 || tipoCategoria > 3)
                    {
                        cout << "Digite um numero valido!\n" << endl;
                        cin >> tipoCategoria;
                    }
                   system("cls");

                        if(tipoCategoria == 1){ // Aluguel
                            for(int i = 0; i < imoveis.size(); i++){
                                if(imoveis[i]->getAluguelouVenda() == 1){
                                    imoveis[i]->exibir();
                                    Sleep(1000);
                                }
                                cout << "\n\n";
                            }
                            if(imoveis.size() == 0)
                                cout << "Lista Vazia!\n" << endl;
                            system("pause");
                            system("cls");
                        }else if(tipoCategoria == 2){
                            for(int i = 0; i < imoveis.size(); i++){
                                if(imoveis[i]->getAluguelouVenda() == 0){
                                    imoveis[i]->exibir();
                                    Sleep(1000);
                                }
                                cout << "\n\n";
                            }
                            if(imoveis.size() == 0)
                                cout << "Lista Vazia!\n" << endl;
                            system("pause");
                            system("cls");
                        }
                   }
        }

        if(i == 3)
        {
            system("cls");
            imoveis = s1.BuscarImovel(); unsigned int contador;
             if(imoveis.size() == 0){
                cout << "Lista vazia\n" << endl;
                Sleep(1000);
                system("cls");
            }
            for(contador = 0; contador < imoveis.size(); contador ++)
            {
                cout << "\n";
                imoveis[contador]->exibir();
                cout << "\n" << endl;
                Sleep(1000);
            }
            if(imoveis.size() != 0)
            {
                int int1;
                cout << "Deseja fechar a lista?(Digite 1), se nao: (Digite 0)\n" << endl;
                cin >> int1;
                while(int1 > 1 || int1 < 0)
                {
                    cout << "Digite um numero valido!\n" << endl;
                    cin >> int1;
                }
                while(int1 == 0)
                {
                    cout << "Deseja fechar a lista?(Digite 1), se nao: (Digite 0)\n" << endl;
                    cin >> int1;
                }
                system("cls");
            }
        }

        if(i == 4)
        {
            system("cls");
            //----------------------------------------------------------------
            s1.removerImovel();
            Sleep(2000);
        }
        if(i == 5)
        {
            system("cls");
            s1.editarImovel();
            Sleep(1500);
        }
        if(i == 6)
        {
            saida = 1;
            system("cls");
            b1.salvarArquivo(s1.getImovel());
            cout << "\t\t\t\tArquivo Salvo\n" << endl;
            Sleep(2000);
        }
        if(i == 7)
        {
            system("cls");
            if(!saida){
                cout << "\t\t\t\tDeseja salvar antes de sair?\n\t\t\t\t(Digite 1), Se nao:(Digite 0)" << endl;
                int opc;
                cin >> opc;
                while(opc > 1 || opc < 0)
                {
                    cout << "Digite um numero valido!\n" << endl;
                    cin >> opc;
                }
                if(opc == 1){
                    b1.salvarArquivo(s1.getImovel());
                    cout << "\t\t\t\tArquivo Salvo\n" << endl;
                }
            }
                cout << "\t\t\t\tSaindo...\n\n" << endl;
                Sleep(1500);
                break;
        }
        if(i!=2)
            system("cls");

        ApresentaMenu();
        cin >> i;
        system("cls");
    }
    system("pause");
    return 0;
}

