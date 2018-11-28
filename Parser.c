#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Venta.h"

/** \brief parsea un archivo de texto
 *
 * \param listaventas LinkedList* Puntero a la lista
 * \param fileName char* puntero al nombre del archivo
 * \return int Retorna  (0) Error si no pudo tomar los datos
                        ( 1) Si tomo los datos del archivo correctamente
 *
 */

int parser_parseVentas(char* fileName, LinkedList* listaVentas)
{
    FILE*pFile;
    int retorno=0;
    char buffer[2000];
    pFile=fopen(fileName,"r");
    char*tokenIdventa;
    char*tokenFecha;
    char*tokenCodigoProducto;
    char*tokenCantidad;
    char*tokenPrecioUnitario;
    char*tokenCuit;
    Venta*venta;

    if(pFile!=NULL && listaVentas!=NULL)
    {
        fgets(buffer,2000,pFile);
        do
        {
            fscanf(pFile,"%[^\n]\n",buffer);
            tokenIdventa=strtok(buffer,",");
            tokenFecha=strtok(NULL,",");
            tokenCodigoProducto=strtok(NULL,",");
            tokenCantidad=strtok(NULL,",");
            tokenPrecioUnitario=strtok(NULL,",");
            tokenCuit=strtok(NULL,"\n");

            venta=Venta_newConParametros(tokenIdventa,tokenFecha,tokenCodigoProducto,tokenCantidad,tokenPrecioUnitario,tokenCuit);

            if(venta!=NULL)
            {
                ll_add(listaVentas,venta);
                retorno=1;
            }
        }while(!feof(pFile));
    }
    fclose(pFile);

    return retorno; // OK
}
