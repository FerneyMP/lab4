#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class enrutador
{
public:
    void agregar_nodo(char clave, int costo);
    void eliminar_nodo(char clave);
    void modificar(char clave, string costo, bool modo);
    void mostrar_tabla(char clave);

private:
    map<char, int> enrutadores;

};

#endif // ENRUTADOR_H
