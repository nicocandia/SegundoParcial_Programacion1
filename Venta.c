
#include "Funciones.h"
#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief crea una nueva venta
 *
 * \return Venta* Retorna
 *
 */
Venta* Venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}

/** \brief elimina venta
 *
 * \param this Venta* Puntero a venta
 * \return void
 */

void Venta_delete(Venta* this)
{
    free(this);
}
/** \brief crea una venta nueva con parametros
 *
 * \param idventa char* Puntero a idventa
 * \param fechaventa char* puntero a fechaVenta
 * \param codigoProducto char* Puntero a codigoProducto
 * \param cantidad char* puntero a cantidad
 * \param precioUnitario char* Puntero a precioUnitario
 * \param cuitCliente char* puntero a cuitCliente
 * \return Venta* Retorna  (venta) si tomo los datos correctamente
                        ( NULL) Si salio todo mal
 *
 */
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
/** \brief setea idVenta
 *
 * \param this Venta* Puntero a la venta
 * \param idVenta char* puntero al idventa
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
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

/** \brief obtengo idventa
 *
 * \param this Venta* Puntero a la venta
 * \param idventa char* puntero a idventa
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
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

/** \brief setea fechaventa
 *
 * \param this Venta* Puntero a la venta
 * \param fechaventa char* puntero a fechaventa
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
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

/** \brief obtengo fechaventa
 *
 * \param this Venta* Puntero a la venta
 * \param fechaventa char* puntero a fechaventa
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
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
/** \brief setea codigo producto
 *
 * \param this Venta* Puntero a la venta
 * \param codigoproducti char* puntero a codigoproducto
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
int Venta_setCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && !isvalidProducto(codigoProducto))
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=0;
    }
    return retorno;
}

/** \brief obtengo codigoProducto
 *
 * \param this Venta* Puntero a la venta
 * \param codigoProducto char* puntero a codigoProducto
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
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

/** \brief setea cantidad
 *
 * \param this Venta* Puntero a la venta
 * \param cantidad char* puntero a cantidad
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
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

/** \brief obtengo cantidad
 *
 * \param this Venta* Puntero a la venta
 * \param cantidad char* puntero a cantidad
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
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
/** \brief setea precio unitario
 *
 * \param this Venta* Puntero a la venta
 * \param precioUnitario char* puntero a precioUnitario
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
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

/** \brief obtengo precioUnitario
 *
 * \param this Venta* Puntero a la venta
 * \param preciounitario char* puntero a preciounitario
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
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
/** \brief setea cuitcliente
 *
 * \param this Venta* Puntero a la venta
 * \param cuitcliente char* puntero a cuitcliente
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
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

/** \brief obtengo cuit cliente
 *
 * \param this Venta* Puntero a la venta
 * \param cuitcliente char* puntero a cuitcliente
 * \return int* Retorna  (0) si tomo los datos correctamente
                        ( -1) Si salio todo mal
 *
 */
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

/** \brief obtengo la cantidad vendidas de la venta
 *
 * \param element Void* Puntero a void
 * \return int* Retorna  cantidadVendidas

 *
 */
int cantidadUnidadesVenta(void*element)
{
    int cantidadVendidas=0;
    if(element!=NULL)
    {
        Venta_getCantidad(element,&cantidadVendidas);
    }
    return cantidadVendidas;
}

/** \brief calcula una venta por un monto mayor a 10000
 *
 * \param element Void* puntero a void
 * \return int* Retorna  (1) si el monto supera 10000
                        ( 0) Si el monto no supera a 10000
 *
 */
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

/** \brief calcula una venta por un monto mayor a 20000
 *
 * \param element Void* puntero a void
 * \return int* Retorna  (1) si el monto supera 20000
                        ( 0) Si el monto no supera a 20000
 *
 */
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

/** \brief calcula la cantidad de LCD_TV vendidas
 *
 * \param element Void* puntero a void
 * \return int* Retorna  (cantidad) si codigo producto corresponde a LCD_TV
                        ( 0) Si el codigo producto no corresponde a LCD_TV
 *
 */
int cantidadtvlcdVendidas(void*element)
{
    int retorno=0;
    int cantidad=0;
    char codigoProducto[128];

    Venta_getCantidad(element,&cantidad);
    Venta_getCodigoProducto(element,codigoProducto);

    if(strcmp(codigoProducto,"LCD_TV")==0)
    {
        retorno=cantidad;
    }
    return retorno;
}

/** \brief valida idventa
 *
 * \param id char* puntero a id
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
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

/** \brief valida cantidad
 *
 * \param cantidad char* puntero a cantidad
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
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

/** \brief valida precio
 *
 * \param precio char* puntero a precio
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
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

/** \brief valida cuil
 *
 * \param cuil char* puntero a cuil
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
int isvalidCuil(char* cuil)
{
   int retorno=-1;
   if(!verificarCuitoCuil(cuil))
   {
        retorno=0;
   }
   return retorno;
}

/** \brief valida fecha
 *
 * \param fecha char* puntero a fecha
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
int isvalidFecha(char*fecha)
{
    int retorno=-1;
    if(!verificarfecha(fecha))
    {
        retorno=0;
    }
    return retorno;
}

/** \brief valida producto
 *
 * \param producto char* puntero a producto
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
int isvalidProducto(char*producto)
{
   int retorno;
    int i=0;
    int contadorguionBajo=0;
    char auxiliar=producto[i];
    while(auxiliar!='\0')
        {
            if(!((auxiliar>='A' && auxiliar<='Z')||(auxiliar>='0' && auxiliar<='9') || auxiliar=='_'))
            {
                retorno=-1;
                break;
            }
            if(auxiliar=='_')
            {
                contadorguionBajo++;
            }
                i++;
                auxiliar=producto[i];
            }
    if(contadorguionBajo==1)
    {
        retorno=0;
    }
    return retorno;
}



