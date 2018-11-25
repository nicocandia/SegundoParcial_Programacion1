#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Generador.h"

int main()
{
    LinkedList*listaVentas=ll_newLinkedList();

    if(parser_parseVentas("data.csv",listaVentas)==1)
    {
        printf("se ha cargado el archivo correctamente\n");


        if(generarArchivos("informes.txt",listaVentas)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
        {
            printf("Error generando archivo\n");
        }

    }else
    {
        printf("no se ha cargado el archivo correctamente\n");
    }
    return 0;
}
