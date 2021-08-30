#include "enrutador.h"

void enrutador::agregar_nodo(char clave, int costo)
{
    if(enrutadores.find(clave)==enrutadores.end()){ // revisa si un elemento existe dentro de un mapa, el .find() retorna un .end()
        //si no encuentra dicho mapa con clave tal, significa que que no existe el mapa y permite continuar con el condicional.
        enrutadores.insert(pair<char,unsigned int>(clave,costo)); //Agrega un nuevo elemento dentro del contenedor.
    }
}

void enrutador::eliminar_nodo(char clave)
{
    if(enrutadores.find(clave)!=enrutadores.end()){ // revisa si un elemento existe dentro de un mapa, el .find() retorna un .end()
        //si es diferente al .end() significa que si existe dicho mapa con clave buscada.
        enrutadores.erase(clave);//Elimina el mapa con dicha clave buscada.
    }
}

void enrutador::modificar(char clave, string costo)
{

    if(enrutadores.find(clave)!=enrutadores.end()){
        enrutadores[clave] = atoi(costo.c_str()); //"Indexa" el mapa con clave buscada y asigna el valor entero después del igual,
        //es decir, lo reemplaza con el valor de costo.
    }
}

void enrutador::mostrar_tabla(char clave)
{
    map<char, int >::iterator it; //Se hace el llamado del iterador que tiene por defecto el mapa
    cout << "\nTabla de enrutamiento del nodo: " << clave << endl << endl;
    for(it=enrutadores.begin(); it!= enrutadores.end(); it++){        
        cout << "Nodo: " << it->first << " \nCosto de conexion: " << it->second << endl;
        //con it->first lo que se hace es que ubica el iterador en la clave y con second el contenido que acompaña el mapa,
        //en este caso un entero
    }

}
