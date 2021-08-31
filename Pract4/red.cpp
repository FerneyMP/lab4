#include "red.h"

void red::agregar_enrutador(char clave)
{
    enrutador enrut; //Se instancia la clase enrutador
    //char name;
    int defecto = 0;
    //Busca la clave designada dentro del mapa, si es igual a map::end, es porque no está y se puede agregar un nuevo valor
    if(redes.find(clave)==redes.end()){
        //De la clase enrutador se llama el método agregar_nodo para crear un nodo nuevo.
        enrut.agregar_nodo(clave,defecto);
        //Se agrega un nodo nuevo en la clase red mediante la función insert(dada por c++)
        redes.insert(pair<char, enrutador>(clave,enrut));
        cout << "El enrutador " << clave << " ha sido creado correctamente..." << endl;
    }
}

void red::asignar_enlaceEnrutador(char clave)
{
    enrutador enruta;
    int conexiones=0;
    char captura;
    int costo;
    if(redes.find(clave)!=redes.end()){
        cout << "Ingrese el numero de conexiones del nodo: ";
        cin>>conexiones;
        //AGREGAR VALIDACION
        for(int i=0; i<conexiones; i++){
            cout << "Conexion #" << i+1 << ": ";
            cin>>captura;
            //AGREGAR VALIDACION
            cout << "Costo de la conexion: "; cin >> costo; cout << endl;
            redes[clave].agregar_nodo(captura, costo);
        }
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
            iterator->second.mostrar_tabla(clave); //Con iterator.second se "abre" la segunda posición del mapa
            //cuya información contiene una clase, luego, se llama el método mostrar_tabla de dicha clase
        }
    }
}

void red::eliminar_enrutador(char clave)
{
    //Busca la clave designada dentro del mapa y si diferente a map::end, es porque si está y entra dentro del condicional
    if(redes.find(clave)!=redes.end()){
        //Se elimina el nodo de la clase red mediante la función erase(dada por c++)
        redes.erase(clave);
        cout << "El enrutador " << clave << " ha sido eliminado correctamente..." << endl;
    }
}

void red::modificar_costoEnrutador(char clave)
{
    string costo_;
    char modificar;
    if(redes.find(clave)!=redes.end()){
        cout << "Ingrese el enlace a modificar: ";
        cin>>modificar;
        //AGREGAR VALIDACION
        cout << "Ingrese el nuevo costo de enlace: ";
        getline(cin,costo_);
        getline(cin,costo_);
        //Se ingresa en el mapa mediante la clave X, y se invoca la función modificar que pertenece a la clase enrutador
        redes[clave].modificar(modificar, costo_);
        cout << "Los enlaces han sido modificados correctamente..." << endl << endl;
    }
}

void red::mostrar_red()
{
    system("clear");
    cout << "Red completa: " << endl;
    map<char, enrutador>::iterator it; //
    for(it=redes.begin(); it!=redes.end(); it++){
        //se accede a las diferentes claves mediante las iteraciones del it y allí, luego, en cada iteración se llama a la
        // funcion mostrar_tabla perteneciente a la clase enrutador e imprime el contenido de cada enrutador.
        redes[it->first].mostrar_tabla(it->first);
    }
}

void red::agregar_enrutador_txt(char clave)
{
    enrutador enrut; //Se instancia la clase enrutador
    //char name;
    int defecto = 0;
    //Busca la clave designada dentro del mapa, si es igual a map::end, es porque no está y se puede agregar un nuevo valor
    if(redes.find(clave)==redes.end()){
        //De la clase enrutador se llama el método agregar_nodo para crear un nodo nuevo.
        enrut.agregar_nodo(clave,defecto);
        //Se agrega un nodo nuevo en la clase red mediante la función insert(dada por c++)
        redes.insert(pair<char, enrutador>(clave,enrut));
        //cout << "El enrutador " << clave << " ha sido creado correctamente..." << endl;
    }
}

void red::asignar_enlaceEnrutador_txt(char clave, int peso)
{
    enrutador enruta;
    int conexiones=0;
    char captura;
    if(redes.find(clave)!=redes.end()){
        cout << "Ingrese el numero de conexiones del nodo: ";
        cin>>conexiones;
        //AGREGAR VALIDACION DE ENTEROS

        for(int i=0; i<conexiones; i++){
            cout << "Conexion #" << i+1 << ": ";
            cin>>captura;
            //AGREGAR VALIDACION de CHAR

            if(redes.find(captura)!=redes.end()){
            redes[clave].agregar_nodo(captura, peso);}
            else{
                cout << "El enlace no puede ser creado. El enrutador ingresado no existe." << endl;
            }
        }
    }
}

red::red()
{

}
