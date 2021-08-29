#ifndef RED_H
#define RED_H
#include "enrutador.h"

class red
{
public:
    /*!
      Agregar enrutador         ✔
      Quitar enrutador          ✔
      Mostrar tabla
      Modificar                 ✔
      */
    void agregar_enrutador(char clave);
    void eliminar_enrutador(char clave);
    void modificar_enrutador(char clave);
    void mostrar_tablaEnrutador(char clave);
    red();
private:
   map<char, enrutador> redes; //Se crea un mapa de tipo(char, clase)

    //leer archivo de texto, crear nuevo nodo(enrutador) dentro del mapa red, se crea un nueva clave, si ya existe modificar, si no
    // agregar. Dato numérico y la segunda letra, agregar en sentido opuesto


};

#endif // RED_H
