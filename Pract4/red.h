#ifndef RED_H
#define RED_H
#include "enrutador.h"

class red
{
public:
    /*!
      Agregar enrutador                     ✔
      Quitar enrutador                      ✔
      Mostrar tabla enrutador               ✔
      Modificar costo de enlaces            ✔
      Mostrar red                           ✔
      Generar grafos aleatorios
      Cargar desde un archivo
      */
    void agregar_enrutador(char clave);
    void asignar_enlaceEnrutador(char clave);
    void mostrar_tablaEnrutador(char clave);
    void eliminar_enrutador(char clave);    
    void modificar_costoEnrutador(char clave);
    void mostrar_red();
    void agregar_enrutador_txt(char clave);
    void asignar_enlaceEnrutador_txt(char clave, int peso);



    red();
private:
   map<char, enrutador> redes; //Se crea un mapa de tipo(char, clase)

    //leer archivo de texto, crear nuevo nodo(enrutador) dentro del mapa red, se crea un nueva clave, si ya existe modificar, si no
    // agregar. Dato numérico y la segunda letra, agregar en sentido opuesto


};

#endif // RED_H
