#include "BancoDeDados.h"
#include "Casa.h"
#include "Terreno.h"
#include "Apartamento.h"

void BancoDeDados::salvarArquivo(std::vector <Imovel*> imoveis){

    std::ofstream ficheiroDeDadosSaida("imoveis.txt",std::ios::out|std::ios::trunc);

        for(int i = 0 ; i < imoveis.size(); i++){
            ficheiroDeDadosSaida << imoveis[i]->toString();
        }

    ficheiroDeDadosSaida.close();
}



std::vector <Imovel*> BancoDeDados::lerArquivo(){


    std::ifstream ficheiroDeDadosEntrada("imoveis.txt",std::ios::in);
    std::vector <std::string> conteudo;
    std::string linhas;


       while(!ficheiroDeDadosEntrada.eof()){
            getline(ficheiroDeDadosEntrada,linhas);
            conteudo.push_back(linhas);
        }

        ficheiroDeDadosEntrada.close();

std::vector <Imovel*> imoveisLidos = toStringtoVector(conteudo);

    return imoveisLidos;
}

std::vector <Imovel*> toStringtoVector(std::vector <std::string> conteudo){

    std::vector <Imovel*> imoveisLidos;
    std::vector <Casa*> casasLidas;
    std::vector <Terreno*> terrenosLidos;
    std::vector <Apartamento*> apartamentosLidos;

    int indice = 0;
    bool verificarproximos = false;

    //std::cout << conteudo.size() << std::endl;

/*
        Basicamente esse while funciona como um for estilizado para duas condições
    que pensei na logica de me localizar  no vector de string lido.
        A logica é a seguinte:
            - olhe a primeira posicao 8 (pois eh onde a flag do tipo se encontra)
            e verifique o tipo do imovel
            - atribua para o primeiro imovel seu lugar no vector de imoveis(essa
            operação eh feita levando em consideração o indice atual do tipo)
            - veja quanto deve-se pular no indice para chegar no titulo do próximo
            imóvel(operação feita levando em consideração o indice corrente em relação
            ao tipo do imovel)

            -Pule 8 posições em relação ao imovel indice > 1 e verifique o tipo do imovel
            -atribua para o corrente imovel um lugar no vector de imoveis
            -veja quanto se deve pular para chegar no titulo do proximo imovel
            -repita isso ate acabar o arquivo



*/

        while(indice < (conteudo.size()-1)){ // tem que ser menos 1 para ignorar um eventual '\n' no final do arquivo

                if(indice == 8){


                        if(atoi(conteudo[indice].c_str()) == 1){ // casa

                            Casa *c1 = new Casa(conteudo[indice-8],Endereco(conteudo[indice-7],atoi(conteudo[indice-6].c_str()),
                                         conteudo[indice-5],conteudo[indice-4],conteudo[indice-3]),atof(conteudo[indice-2].c_str()),
                                         atof(conteudo[indice-1].c_str()),atoi(conteudo[indice - 0].c_str()),atoi(conteudo[indice +1].c_str()),
                                         atoi(conteudo[indice + 2].c_str()),atof(conteudo[indice + 3].c_str()),atof(conteudo[indice + 4].c_str()));


                             casasLidas.push_back(c1);

                             indice += 5;

                        }else if(atoi(conteudo[indice].c_str()) == 2){

                            Apartamento *ap1 = new Apartamento(conteudo[indice-8],Endereco(conteudo[indice-7],atoi(conteudo[indice-6].c_str()),
                                       conteudo[indice-5],conteudo[indice-4],conteudo[indice-3]),atof(conteudo[indice-2].c_str()),
                                       atoi(conteudo[indice-1].c_str()),atoi(conteudo[indice-0].c_str()),conteudo[indice+1],
                                       atoi(conteudo[indice+2].c_str()),atof(conteudo[indice+3].c_str()),atoi(conteudo[indice+4].c_str()),
                                       atof(conteudo[indice+5].c_str()));

                             apartamentosLidos.push_back(ap1);
                             if(conteudo.size() == 15){break;}
                             indice += 6;

                        }else if(atoi(conteudo[indice].c_str()) == 3){

                            Terreno *t1 = new Terreno(conteudo[indice-8],Endereco(conteudo[indice-7],atoi(conteudo[indice-6].c_str()),
                                       conteudo[indice-5],conteudo[indice-4],conteudo[indice-3]),atof(conteudo[indice-2].c_str()),
                                       atoi(conteudo[indice-1].c_str()),atoi(conteudo[indice-0].c_str()),atof(conteudo[indice+1].c_str()));

                            terrenosLidos.push_back(t1);

                            indice += 2;
                        }

                    verificarproximos = true;


                 }


            if(verificarproximos == false){indice++;}

                if(verificarproximos == true){

                    indice += 8;

                         if(atoi(conteudo[indice].c_str()) == 1){

                                Casa *c1 = new Casa(conteudo[indice-8],Endereco(conteudo[indice-7],atoi(conteudo[indice-6].c_str()),
                                         conteudo[indice-5],conteudo[indice-4],conteudo[indice-3]),atof(conteudo[indice-2].c_str()),
                                         atof(conteudo[indice-1].c_str()),atoi(conteudo[indice - 0].c_str()),atoi(conteudo[indice +1].c_str()),
                                         atoi(conteudo[indice + 2].c_str()),atof(conteudo[indice + 3].c_str()),atof(conteudo[indice + 4].c_str()));

                            casasLidas.push_back(c1);
                            indice += 5;


                          }else if(atoi(conteudo[indice].c_str()) == 2){

                           Apartamento *ap1 = new Apartamento(conteudo[indice-8],Endereco(conteudo[indice-7],atoi(conteudo[indice-6].c_str()),
                                       conteudo[indice-5],conteudo[indice-4],conteudo[indice-3]),atof(conteudo[indice-2].c_str()),
                                       atoi(conteudo[indice-1].c_str()),atoi(conteudo[indice-0].c_str()),conteudo[indice+1],
                                       atoi(conteudo[indice+2].c_str()),atof(conteudo[indice+3].c_str()),atoi(conteudo[indice+4].c_str()),
                                       atof(conteudo[indice+5].c_str()));


                            apartamentosLidos.push_back(ap1);
                            indice += 6;
                            //std::cout << indice <<std :: endl;

                         }else if(atoi(conteudo[indice].c_str()) == 3){
                            //std::cout << "Terreno" << std::endl;
                            Terreno *t1 = new Terreno(conteudo[indice-8],Endereco(conteudo[indice-7],atoi(conteudo[indice-6].c_str()),
                                       conteudo[indice-5],conteudo[indice-4],conteudo[indice-3]),atof(conteudo[indice-2].c_str()),
                                       atoi(conteudo[indice-1].c_str()),atoi(conteudo[indice-0].c_str()),atof(conteudo[indice+1].c_str()));

                            terrenosLidos.push_back(t1);
                            indice += 2;
                            //std::cout << indice <<std :: endl;
                         }

                }

        }

        for(int i  = 0; i < casasLidas.size(); i++){
            imoveisLidos.push_back(casasLidas[i]);
        }
        for(int i = 0; i < apartamentosLidos.size();i++){
            imoveisLidos.push_back(apartamentosLidos[i]);
        }
        for(int i = 0; i < terrenosLidos.size();i++){
            imoveisLidos.push_back(terrenosLidos[i]);
        }


        return imoveisLidos;
}
