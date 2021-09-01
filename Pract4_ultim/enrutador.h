#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

class enrutador
{
public:
    void agregar_nodo(char clave, int costo);
    void eliminar_nodo(char clave);
    void modificar(char clave, string costo, bool modo, char captura);
    void mostrar_tabla(char clave);

    void mirar_enrutadores_contiguos(char clave, char destino);
    void asignacion(char clave, char destino);

    void agregar_nodo_txt(char clave, int costo);

private:
    map<char, int> enrutadores;

};

#endif // ENRUTADOR_H
