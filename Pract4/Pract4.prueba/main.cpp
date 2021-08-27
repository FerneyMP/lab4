#include "enrutador.h"
#include "funciones.h"

int main()

{    
    string texto, nombre;
    texto=leer( nombre);
    escribir (texto, texto);

    enrutador a;
    a.agregar_nodo('a',3);
    a.mostrar_tabla();

    return 0;
}
