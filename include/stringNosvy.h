#ifndef STRING_NOSVY_H
#define STRING_NOSVY_H

#include <ctype.h>
#include <iostream>
#include <string>

/*
 Autor: Yvson Nunes 16/02/2020
*/

void converteMinuscula(char *p){
    while( *p ){
        *p=tolower( *p );
        p++;
    }
}

bool buscaContida(std::string inputStr, std::string outputStr){

    const char *inputStrC = inputStr.c_str();
    const char *outputStrC = outputStr.c_str();

    converteMinuscula((char*)inputStrC);
    converteMinuscula((char*)outputStrC);


    std::string inputStr_C_back_Cpp = inputStrC;
    std::string outputStr_C_back_Cpp = outputStrC;

    int contem = outputStr_C_back_Cpp.find(inputStr_C_back_Cpp); // se for negativo nao contem

    if(contem >= 0){
        return true;
    }else{
        return false;
    }

}

#endif
