#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"
#include "LinkedList.h"

int generarArchivos(char* fileName,LinkedList* listaVentas)
{
    int retorno=0;
    FILE*pFile;
    int len=ll_len(listaVentas);
    pFile=fopen(fileName,"w");

    if(pFile!=NULL && listaVentas!=NULL && len>0)
    {
        fprintf(pFile,"***************\nInformes de ventas\n***************\n\n");
        fprintf(pFile,"Cantidad de ventas por un monto mayor a 10000:%d\n",ll_count(listaVentas,venta_montoMayor_a10000));
        fprintf(pFile,"Cantidad de ventas por un monto mayor a 20000:%d\n",ll_count(listaVentas,venta_montoMayor_a2000));
        fprintf(pFile,"Cantidad de tvs LCD vendidas:%d\n\n",ll_count(listaVentas,cantidadtvlcdVendidas));
        fprintf(pFile,"*******************");
        retorno=1;
    }
    fclose(pFile);
    return retorno;
}
