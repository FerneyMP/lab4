#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class enrutador
{
public:
    void agregar_nodo(char nombre, int conexion);
    void eliminar_nodo(char nombre);
    void modificar(char nombre, string costo);
    void mostrar_tabla();

private:
    map<char, int> enrutadores;

};

#endif // ENRUTADOR_H
