#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <map>
using namespace std;

class enrutador
{
public:
    void agregar_nodo(char nombre, unsigned int conexion);
    void eliminar_nodo(char nombre);
    void modificar(char nombre, unsigned int conexion);
    void mostrar_tabla();

private:
    map<char, unsigned int> enrutadores;

};

#endif // ENRUTADOR_H
