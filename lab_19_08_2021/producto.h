#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <map>
using namespace std;


class producto
{
public:
    void modificar_interno(string name, string value); //Para el mapa
    //agregar nuevas características en tiempo de ejecución
    void agregar(string name, string value="");
    void eliminar(string name);
    void mostrar();

private:
    map<string,string> ca;
    /*
    unsigned int cod, cant, cant_bodega, precio;
    float peso;
    string nombre, seccion;*/


};

#endif // PRODUCTO_H
