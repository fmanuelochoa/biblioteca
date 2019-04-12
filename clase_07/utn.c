#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


int utn_getString (char* msg, char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s",msg);
            fgets(bufferStr, sizeof(bufferStr), stdin);
            bufferStr[strlen(bufferStr)-1] =  '\0';//siempre para no leer el enter y que mande uno antes que el contrabarra 0
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) < maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>0);

    }


    return retorno;
}





int utn_getName (char* msg, char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    //strncpy(resultado,"ANA",maximo);//para probar con verdadero corre igual
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(utn_getString(msg,msgError,minimo,maximo,reintentos,bufferStr) == 0)
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
            }
        }
    }

    return retorno;

}







int isValidName (char* cadena)
{
    int retorno = TRUE;  //para validar siempre empiezo en positivo para encontrar el error y cuando lo encuentro salgo con break
    int i;
    for(i=0;cadena[i] != '\0';i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            retorno = FALSE;
            break;//te saca del for mas cercano y el continue te saca y prueba si vuelve a iterar
        }

    }

    return retorno;

}





