
#include "Funciones.h"
#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Venta* Venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}

void Venta_delete(Venta* this)
{
    free(this);
}

Venta* Venta_newConParametros(char* idVenta,char* fechaVenta,char* codigoProducto,char* cantidad,char* precioUnitario,char* cuitCliente)
{
    Venta* this;
    this=Venta_new();

    if(
    !Venta_setIdVenta(this,idVenta)&&
    !Venta_setFechaVenta(this,fechaVenta)&&
    !Venta_setCodigoProducto(this,codigoProducto)&&
    !Venta_setCantidad(this,cantidad)&&
    !Venta_setPrecioUnitario(this,precioUnitario)&&
    !Venta_setCuitCliente(this,cuitCliente))
        return this;

    Venta_delete(this);
    return NULL;
}

int Venta_setIdVenta(Venta* this,char* idVenta)
{
    int retorno=-1;
    int idventaAux;
    if(this!=NULL && !isvalidIDventa(idVenta))
    {
        idventaAux=atoi(idVenta);
        this->idVenta=idventaAux;
        retorno=0;
    }
    return retorno;
}

int Venta_getIdVenta(Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}

int Venta_setFechaVenta(Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && !isvalidFecha(fechaVenta))
    {
        strcpy(this->fechaVenta,fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_getFechaVenta(Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(fechaVenta,this->fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_setCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=0;
    }
    return retorno;
}

int Venta_getCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(codigoProducto,this->codigoProducto);
        retorno=0;
    }
    return retorno;
}

int Venta_setCantidad(Venta* this,char* cantidad)
{
    int retorno=-1;
    int cantidadAux;
    if(this!=NULL && !isvalidCantidad(cantidad))
    {
        cantidadAux=atoi(cantidad);
        this->cantidad=cantidadAux;
        retorno=0;
    }
    return retorno;
}

int Venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_setPrecioUnitario(Venta* this,char* precioUnitario)
{
    int retorno=-1;
    float precioUnitarioAux;
    if(this!=NULL && !isvalidPrecio(precioUnitario))
    {
        precioUnitarioAux=atof(precioUnitario);
        this->precioUnitario=precioUnitarioAux;
        retorno=0;
    }
    return retorno;
}

int Venta_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Venta_setCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && !isvalidCuil(cuitCliente))
    {
        strcpy(this->cuitCliente,cuitCliente);
        retorno=0;
    }
    return retorno;
}

int Venta_getCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(cuitCliente,this->cuitCliente);
        retorno=0;
    }
    return retorno;
}

int cantidadUnidadesVenta(void*element)
{
    int cantidadVendidas;
    Venta_getCantidad(element,&cantidadVendidas);
    return cantidadVendidas;

}

int venta_montoMayor_a10000(void*element)
{
    int retorno=0;
    int cantidadAux;
    float precioUnitarioAux;

    Venta_getCantidad(element,&cantidadAux);
    Venta_getPrecioUnitario(element,&precioUnitarioAux);

    if((cantidadAux*precioUnitarioAux)>10000)
    {
        retorno=1;
    }

    return retorno;
}

int venta_montoMayor_a2000(void*element)
{
    int retorno=0;
    int cantidadAux;
    float precioUnitarioAux;

    Venta_getCantidad(element,&cantidadAux);
    Venta_getPrecioUnitario(element,&precioUnitarioAux);

    if((cantidadAux*precioUnitarioAux)>20000)
    {
        retorno=1;
    }

    return retorno;
}

int cantidadtvlcdVendidas(void*element)
{
    int retorno=0;
    int cantidad;
    char codigoProducto[128];

    Venta_getCantidad(element,&cantidad);
    Venta_getCodigoProducto(element,codigoProducto);

    if(strcmp(codigoProducto,"LCD_TV")==0)
    {
        retorno=cantidad;
    }
    return retorno;
}

int isvalidIDventa(char* id)
{
   int retorno=-1;
   int idaux;
   if(!verificarArregloSoloNumeros(id))
   {
        idaux=atoi(id);
        if(idaux>=0)
        {
            retorno=0;
        }
   }
   return retorno;
}

int isvalidCantidad(char* cantidad)
{
   int retorno=-1;
   int cantidadAux;
   if(!verificarArregloSoloNumeros(cantidad))
   {
        cantidadAux=atoi(cantidad);
        if(cantidadAux>=0)
        {
            retorno=0;
        }
   }
   return retorno;
}

int isvalidPrecio(char* precio)
{
   int retorno=-1;
   float precioAux;
   if(!verificarArreglosoloFlotantes(precio))
   {
        precioAux=atof(precio);
        if(precioAux>=0)
        {
            retorno=0;
        }
   }
   return retorno;
}

int isvalidCuil(char* cuil)
{
   int retorno=-1;
   if(!verificarCuitoCuil(cuil))
   {
        retorno=0;
   }
   return retorno;
}

int isvalidFecha(char*fecha)
{
    int retorno=-1;
    if(!verificarfecha(fecha))
    {
        retorno=0;
    }
    return retorno;
}



