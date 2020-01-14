#include <iostream>
#include <vector>
//#include "Imovel.h"
#include "Casa.h"
#include "Apartamento.h"
#include "Terreno.h"

using namespace std;

int main(){

 /* Imovel *p = new Casa("Casa foda",Endereco("Rua da augusta",2469,"Loucuras de meu deus","Craquolandia","1233421"),
               200000,true,1,2,7,200,115);
 */
    vector <Imovel*> imoveis;
    imoveis.push_back(new Casa("Casa foda",Endereco("Rua da augusta",2469,"Loucuras de meu deus","Craquolandia","1233421"),
                    200000,false,1,2,7,200,115));

    imoveis.push_back(new Apartamento("Apartamento do Latino",Endereco("Rua da Areia",1213,"I got that turn in momentum","Lose your self","12345432"),
                    600000,true,2,"Nascente oriental", 4 ,10000,2,200));

    imoveis.push_back(new Terreno("Terreiro de macumba",Endereco("Rua do bagulho doido",666,"Exu paranaue caveira","Salvador","32434545"),
                    200,false,3,500));


    return 0;
}
