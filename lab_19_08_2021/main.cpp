#include "inventario.h"

int main()
{       
    /*!   Manejo de inventario en un supermecado.

     *    Hacer el manejo completo del inventario de un supermecado en particular.

     *    Inventario completo, productos, base de datos.

     *    Características:
     *    código del producto, nombre, cantidad, cantidad_bodega, precio, sección, peso.

     *    Producto:
     *          Nombre
     *          Código
     *          precio
     *          seccion
     *
     *          Modificar cada característica
     *          Agregar nuevo producto
     *          Eliminar cualidad
     *          Mostrar cualidades
     *
     *   Inventario:
     *          Agregar un nuevo producto
     *          Eliminar un producto
     *          Modificar los datos de un producto
     *          Visualizar en la aplicación
     *
     *          Sede
     *          Nombre supermecado
     *          Nombre encargado
     *
     *   Base de datos:
     *          Nombre
     *          Escribir un nuevo dato
     *          Leer un nuevo dato
     *          Modificar un dato
     *          Eliminar un dato
      */

    //producto *l = new producto; se accede con ->
   /* producto k,k2,k3; //objeto

    k.agregar("Precio", "2100");
    k.agregar("Nombre","leche");
    k2.agregar("Nombre","Chocolate");
    k3.agregar("Nombre","mani");*/

    inventario inv;
    inv.agregar_producto(123456);
    inv.agregar_producto(111111);
    inv.agregar_producto(444444);
    inv.agregar_producto(555555);
    inv.print();

    inv.eliminar(111111);
    inv.modificar(55555);
    inv.print();

    return 0;
}
