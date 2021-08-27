#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "producto.h"

class inventario
{
public:
    inventario();
    void agregar_producto(unsigned long long cod);
    void eliminar(unsigned long long cod);
    void modificar(unsigned long long cod);
    void print();

private:

    map<unsigned long long,producto> inv;
    string cr[7];

};

#endif // INVENTARIO_H
