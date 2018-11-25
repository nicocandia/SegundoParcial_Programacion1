#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
    int idVenta;
    char fechaVenta[128];
    char codigoProducto[128];
    int cantidad;
    float precioUnitario;
    char cuitCliente[128];
}Venta;

Venta* Venta_new();
void Venta_delete();
Venta* Venta_newConParametros(char* idVenta,char* fechaVenta,char* codigoProducto,char* cantidad,char* precioUnitario,char* cuitCliente);

int Venta_setIdVenta(Venta* this,char* idVenta);
int Venta_getIdVenta(Venta* this,int* idVenta);

int Venta_setFechaVenta(Venta* this,char* fechaVenta);
int Venta_getFechaVenta(Venta* this,char* fechaVenta);

int Venta_setCodigoProducto(Venta* this,char* codigoProducto);
int Venta_getCodigoProducto(Venta* this,char* codigoProducto);

int Venta_setCantidad(Venta* this,char* cantidad);
int Venta_getCantidad(Venta* this,int* cantidad);

int Venta_setPrecioUnitario(Venta* this,char* precioUnitario);
int Venta_getPrecioUnitario(Venta* this,float* precioUnitario);

int Venta_setCuitCliente(Venta* this,char* cuitCliente);
int Venta_getCuitCliente(Venta* this,char* cuitCliente);

int cantidadUnidadesVenta(void*element);

int venta_montoMayor_a2000(void*element);
int venta_montoMayor_a10000(void*element);
int cantidadtvlcdVendidas(void*element);

int isvalidIDventa(char* id);
int isvalidCantidad(char* cantidad);
int isvalidPrecio(char* precio);
int isvalidCuil(char* cuil);
int isvalidFecha(char*fecha);
int isvalidProducto(char*producto);

#endif // VENTA_H_INCLUDED
