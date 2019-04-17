#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_EMPLEADOS 10

int main()
{
    //char auxName[500] = "test";
    char arrayNombres[QTY_EMPLEADOS][50];
    char auxiliarNombres[50];
    //strncpy(arrayNombres[0],"JUAN",50);
    //strncpy(arrayNombres[1],"JUAN1",50);
    //strncpy(arrayNombres[2],"JUAN2",50);


    if(utn_getName("Nombre?:","Error",2,50,4,auxiliarNombres) == 0)
    {
        //strncpy(arrayNombres[QTY_EMPLEADOS],auxiliarNombres,sizeof(arrayNombres[QTY_EMPLEADOS]));
        //printf("OK: %s",auxiliarNombres);
        printArray(auxiliarNombres, 10);
    }
    else
    {
        printf("ERROR: %s",auxiliarNombres);
    }



    return 0;
}


//
