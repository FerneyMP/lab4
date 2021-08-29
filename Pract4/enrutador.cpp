#include "enrutador.h"

void enrutador::agregar_nodo(char nombre, int conexion)
{
    if(enrutadores.find(nombre)==enrutadores.end()){ // revisa si un elemento existe dentro de un mapa
        enrutadores.insert(pair<char,unsigned int>(nombre,conexion)); //Agregar un nuevo elemento dentro del contenedor
    }
}

void enrutador::eliminar_nodo(char nombre)
{
    if(enrutadores.find(nombre)!=enrutadores.end()){
        enrutadores.erase(nombre);
    }
}

void enrutador::modificar(char nombre, string costo)
{

    if(enrutadores.find(nombre)!=enrutadores.end()){
        enrutadores[nombre] = atoi(costo.c_str()); //Se convierte a entero
    }
}

void enrutador::mostrar_tabla()
{
    map<char, int >::iterator it;
    for(it=enrutadores.begin(); it!= enrutadores.end(); it++){
       cout << "Nombre del nodo: " << it->first << " \nNumero de conexiones: " << it->second << endl;
    }

}
