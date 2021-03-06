#ifndef RED_H
#define RED_H
#include "enrutador.h"
#include "funciones.h"

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

      Ofrecer la posibilidad de saber cuánto cuesta enviar un paquete (Origen/Destino)        ✔
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

    void origen_destino();
    void eficiencia_origen_destino();

    void asignar_enlaceEnrutador_txt(char clave, char _nodo2, int costo );

    void iterar_txt(char clave );

    void random_red(int nodo, float probabilidad);

    void dijsktra(char clave_origen, char destino);

    red();
private:
   map<char, enrutador> redes; //Se crea un mapa de tipo(char, clase)

    //leer archivo de texto, crear nuevo nodo(enrutador) dentro del mapa red, se crea un nueva clave, si ya existe modificar, si no
    // agregar. Dato numérico y la segunda letra, agregar en sentido opuesto


};

#endif // RED_H
