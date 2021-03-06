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
    void modificar(char clave, string costo, bool modo, char modificar, char captura, int valor_nuevo);
    void modificar(char inverso, int valor_nuevo, char clave);
    void modificar(char modificar, char clave);
    void mostrar_tabla(char clave);

    void mirar_enrutadores_contiguos(char clave, char destino);
    void asignacion(char clave, char destino);

    void agregar_nodo_txt(char clave, int costo);

    void asistenteDijkstra(char clave_origen, char iterador, char destino, bool &fin);

private:
    map<char, int> enrutadores;

};

#endif // ENRUTADOR_H
