#include "red.h"

void red::agregar_enrutador(char clave)
{
    enrutador enrut; //Se instancia la clase enrutador
    //char name;
    int defecto = 0;
    /*! El cout va en el menú */
    /*cout << "Ingrese el nombre del nuevo enrutador: ";
    cin >> name;
    //AGREGAR VALIDACIÓN*/

    //Busca la clave designada dentro del mapa, si es igual a map::end, es porque no está y se puede agregar un nuevo valor
    if(redes.find(clave)==redes.end()){
        //De la clase enrutador se llama el método agregar_nodo para crear un nodo nuevo.
        enrut.agregar_nodo(clave,defecto);
        //Se agrega un nodo nuevo en la clase red mediante la función insert(dada por c++)
        redes.insert(pair<char, enrutador>(clave,enrut));
    }
}

void red::eliminar_enrutador(char clave)
{
    //Busca la clave designada dentro del mapa y si diferente a map::end, es porque si está y entra dentro del condicional
    if(redes.find(clave)!=redes.end()){
        //Se elimina el nodo de la clase red mediante la función erase(dada por c++)
        redes.erase(clave);
    }
}

void red::modificar_enrutador(char clave)
{
    enrutador enrut; //Se instancia la clase enrutador
    string _costo;
    if(redes.find(clave)!=redes.end()){
        //Mientras que map.find(clave) sea diferente a map.end significa que el mapa
        //con clave dada existe y se puede modificar
        cout << "Ingrese el nuevo costo de enlace: ";
        getline(cin,_costo);
        enrut.modificar(clave, _costo);
    }
}

void red::mostrar_tablaEnrutador(char clave)
{
    map<char, enrutador>::iterator iterator; //Se hace uso del iterador que va servir para recorrer el mapa

    enrutador enrut; //Se instancia la clase enrutador

    if(redes.find(clave)!=redes.end()){ //Misma condición que en las anteriores funciones para revisar si la clave dada esta
        for(iterator=redes.begin(); iterator!=redes.end();iterator++){
            //Con este for se inicializa el iterator en la posición de inicio del mapa y se recorre todo
            //mientras llega al final de este
            iterator->second.mostrar_tabla(); //Con iterator.second se "abre" la segunda posición del mapa
            //cuya información contiene una clase, luego, se llama el método mostrar_tabla de dicha clase
        }
    }
}

red::red()
{

}
