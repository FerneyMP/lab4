#ifndef RED_H
#define RED_H
#include "enrutador.h"

class red
{
public:
    /*!
      !IMPORTANTE¡ : AGREGAR VALIDACIONES PARA LOS ENLACES(si se quiere modificar un enlace que no existe, sacarlo del programa)

      Agregar enrutador                     ✔
      Quitar enrutador                      ✔
      Mostrar tabla enrutador               ✔
      Modificar costo de enlaces            ✔
      Modificar enlaces                     ✔  Preguntar(?)
      Mostrar red                           ✔

      Función que permita ver la tabla de enrutamiento de los "vecinos"
      Función que permita elegir el camino óptimo entre cada enlace
      Generar grafos aleatorios
      Cargar desde un archivo
      */
    void agregar_enrutador(char clave);
    void asignar_enlaceEnrutador(char clave);
    void mostrar_tablaEnrutador(char clave);
    void eliminar_enrutador(char clave);    
    void modificar_Enrutador(char clave);
    void mostrar_red();

    red();
private:
   map<char, enrutador> redes; //Se crea un mapa de tipo(char, clase)

    //leer archivo de texto, crear nuevo nodo(enrutador) dentro del mapa red, se crea un nueva clave, si ya existe modificar, si no
    // agregar. Dato numérico y la segunda letra, agregar en sentido opuesto


};

#endif // RED_H
