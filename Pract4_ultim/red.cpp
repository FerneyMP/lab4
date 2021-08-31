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

        //AGREGAR VALIDACION DE ENTEROS
        if(conexiones ==0){
            map<char, enrutador>::iterator it;
            for(it=redes.begin(); it != redes.end(); it++){
                //redes[clave].asignacion(it->first);
                redes[clave].asignacion(clave,it->first);  // ----------------------------------------->        ✔
                }
        }
        else{
        for(int i=0; i<conexiones; i++){
            cout << "Conexion #" << i+1 << ": ";
            cin>>captura;
            //AGREGAR VALIDACION de CHAR

            if(redes.find(captura)!=redes.end()){//Busca si el enrutador existe para poder asignar un enlace

                cout << "Costo de la conexion: "; cin >> costo; cout << endl;
                redes[clave].agregar_nodo(captura, costo);    // ----------------------------------------->        ✔

                //ENLACE BIDIRECCIONAL, es decir, se tiene que asignar el segundo enlace también
                redes[captura].agregar_nodo(clave, costo);    // ----------------------------------------->        ✔

                //NECESITO AGREGAR LOS DEMÁS ENRUTADORES
                //IDEA: Agregar un for que recorra los enrutadores y si alguno es diferente de captura, asignarle el -1
                map<char, enrutador>::iterator it;
                for(it=redes.begin(); it != redes.end(); it++){
                    //redes[clave].asignacion(it->first);
                    redes[clave].asignacion(clave,it->first);  // ----------------------------------------->        ✔
                    }
                }

            else{
                cout << "El enlace no puede ser creado. El enrutador ingresado no existe." << endl;
                }
            }
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

void red::modificar_Enrutador(char clave)
{

    string costo_;
    char modificar;
    int validar;
    bool modo;
    char captura = '\0';

    enrutador enruta;
    if(redes.find(clave)!=redes.end()){//Si
        cout << "Ingrese el enlace a modificar: ";
        cin>>modificar;
        //AGREGAR VALIDACION

        //CORREGIR ------------------------------------
        if(redes.find(modificar)==redes.end()){ //Se comprueba de que el enrutador exista
            cout << "El enlace a modificar no existe." << endl;
        }

        else{
                //map<char, enrutador>::iterator it;
                //map<char, int>::iterator iter;
                //for(it=redes.find(clave); it!=redes.end(); it++){
                //    if()
               // }

                cout <<"0. Para modificar el costo de enlace.\n1. Para modificar el enlace." << endl;
                cin>>validar;
                while (validar!=0 && validar!=1) {
                    cout <<"0. Para modificar el costo de enlace.\n1. Para modificar el enlace." << endl;
                    cin>>validar;
                }

                if(validar==0) modo= true;
                if(validar==1) modo= false;

                if(modo){ //True: Modificar Costo
                    cout << "Ingrese el nuevo costo de enlace: ";
                    getline(cin,costo_);
                    getline(cin,costo_);
                    //Se ingresa en el mapa mediante la clave X, y se invoca la función modificar que pertenece a la clase enrutador
                    redes[clave].modificar(modificar, costo_, modo, captura);
                    cout << "Los enlaces han sido modificados correctamente..." << endl << endl;
                }

                else{//False: Modificar Enlaces

                    //Cómo modificar algo que no ha sido creado?
                    cout << "Ingrese el nuevo enlace: ";
                    cin >> captura;
                    //AGREGAR VALIDACIÓN
                    if(redes.find(captura)!=redes.end()){//significa que existe
                        redes[clave].modificar(modificar, costo_, modo, captura);
                        }
            else{
                cout << "El enrutador " << captura << " no ha sido creado." << endl;
                }
            }
        }
    }
}

void red::mostrar_red()
{
    //system("clear");
    cout << "Red completa: " << endl;
    map<char, enrutador>::iterator it; //
    for(it=redes.begin(); it!=redes.end(); it++){
        //se accede a las diferentes claves mediante las iteraciones del it y allí, luego, en cada iteración se llama a la
        // funcion mostrar_tabla perteneciente a la clase enrutador e imprime el contenido de cada enrutador.
        redes[it->first].mostrar_tabla(it->first);
    }
}

void red::origen_destino()
{
    char origen, destino;
    cout << "Ingrese el origen: ";
    cin >> origen;
    //AGREGAR validación

    if(redes.find(origen)!=redes.end()){// Se verifica que el enrutador ORIGEN exista
        cout << "Ingrese el destino: "; cin >> destino; //AGREGAR VALIDACION

        if(redes.find(destino)!=redes.end()){// Se verifica que el enrutador DESTINO exista
            redes[origen].mirar_enrutadores_contiguos(origen,destino);}//al existir, se indexa redes con origen y se accede a la función
        if(redes.find(destino)==redes.end()){// Al llegar al final del mapa indica que no existe, por eso la igualdad
            cout << "El destino no es valido." << endl;
        }
    }
    else{
        cout << "El enrutador ingresado no existe." << endl;
    }
}

/*void red::eficiencia_origen_destino()
{
    /*! Qué necesito?

        1.) Conocer la tabla de enrutamiento de toda la red
        2.) Determinar por cuales enlaces es más "barato(eficiente)" para enviar el paquete
        3.) Imprimir dicho camino


}*/

red::red()
{

}
