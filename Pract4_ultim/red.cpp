#include "red.h"

void red::agregar_enrutador(char clave)
{
    enrutador enrut; //Se instancia la clase enrutador    
    int defecto = 0;
    //Busca la clave designada dentro del mapa, si es igual a map::end, es porque no está y se puede agregar un nuevo valor
    if(redes.find(clave)==redes.end()){
        //De la clase enrutador se llama el método agregar_nodo para crear un nodo nuevo.
        enrut.agregar_nodo(clave,defecto);
        //Se agrega un nodo nuevo en la clase red mediante la función insert(dada por c++)
        redes.insert(pair<char, enrutador>(clave,enrut));
        cout << "El enrutador " << clave << " ha sido creado correctamente..." << endl;
    }
    else if(redes.find(clave) == redes.find(clave)){
        cout << "El enrutador ya ha sido creado." << endl;
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
                redes[clave].asignacion(clave,it->first);
                }
        }
        else{
        for(int i=0; i<conexiones; i++){
            cout << "Conexion #" << i+1 << ": ";
            cin>>captura;
            validar(captura);
            if(redes.find(captura)!=redes.end()){//Busca si el enrutador existe para poder asignar un enlace

                cout << "Costo de la conexion: "; cin >> costo; cout << endl;
                redes[clave].agregar_nodo(captura, costo);

                //ENLACE BIDIRECCIONAL, es decir, se tiene que asignar el segundo enlace también
                redes[captura].agregar_nodo(clave, costo);

                //SE AGREGAN LOS DEMÁS ENRUTADORES
                map<char, enrutador>::iterator it;
                for(it=redes.begin(); it != redes.end(); it++){
                    //mientras sea diferente se pueden agregar los demás enrutadores mediante la función asignación
                    redes[clave].asignacion(clave,it->first);
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
    map<char, enrutador>::iterator iterator=redes.begin(); //Se hace uso del iterador que va servir para recorrer el mapa
    if(redes.find(clave)!=redes.end()){ //Misma condición que en las anteriores funciones para revisar si la clave dada esta
        for(iterator=redes.begin(); iterator!=redes.end();iterator++){
            //Con este for se inicializa el iterator en la posición de inicio del mapa y se recorre todo
            //mientras llega al final de este
            if (iterator->first == clave){
                iterator->second.mostrar_tabla(clave); //Con iterator.second se "abre" la segunda posición del mapa
                //cuya información contiene una clase, luego, se llama el método mostrar_tabla de dicha clase
            }
        }
    }
    else cout << "El enrutador " << clave << " no ha sido creado." << endl;
}

void red::eliminar_enrutador(char clave)
{
    //Busca la clave designada dentro del mapa y si diferente a map::end, es porque si está y entra dentro del condicional
    if(redes.find(clave)!=redes.end()){
        //Se elimina el nodo de la clase red mediante la función erase(dada por c++)
        redes.erase(clave);
        cout << "El enrutador " << clave << " ha sido eliminado correctamente..." << endl;
    }
    else cout<< "El enrutador que desea eliminar no existe "<<endl;
}

void red::modificar_Enrutador(char clave)
{
    string costo_;
    char modificar;
    int cero_uno;
    bool modo;
    char captura = '\0';
    int valor_nuevo=0;
    //int reinicio = -1;
    map<char, enrutador>::iterator ite;
    if(redes.find(clave) != redes.end()){
        cout << "Ingrese el enlace que desea modificar: "; cin >> modificar; validar(modificar);
        if(redes.find(modificar) != redes.end()){ //El enlace existe y se puede modificar si cumple con el condicional
            cout << "Ingrese:\n0. Para modificar el costo del enlace.\n1. Para modificar el enlace." << endl; cin >>cero_uno;
            while (cero_uno!=0 && cero_uno!=1) {
                cout <<"0. Para modificar el costo de enlace.\n1. Para modificar el enlace." << endl;
                cin>>cero_uno;
            }
            if(cero_uno==0) modo = true;
            if(cero_uno==1) modo = false;

            if(modo){
                cout << "Ingrese el nuevo costo de enlace: "; cin >> costo_;
                redes[clave].modificar(modificar, costo_, modo, clave, captura, valor_nuevo); //Clave - modificar
                //redes[modificar].modificar(clave, costo_, modo, clave, captura, valor_nuevo); //Modificar puesto que es el enlace pareja de clave
                cout <<"Los enlaces han sido modificados correctamente..." << endl;
            }
            else if(modo == false){
                cout << "Ingrese el nuevo enlace: "; cin >> captura; validar(captura);
                if(redes.find(captura)!=redes.end()){
                    cout << "Ingrese el nuevo costo del enlace: ";
                    cin >> valor_nuevo;
                    redes[clave].modificar(clave, costo_, modo, modificar, captura, valor_nuevo);//Se busca eliminar a modificar (modificar-Captura)
                    //void enrutador::modificar(char inverso, char modificar, int valor_nuevo)
                    redes[captura].modificar(captura, valor_nuevo, clave);
                    redes[modificar].modificar(modificar, clave);
                    //redes[captura].modificar(captura, costo_, modo, modificar, clave, valor_nuevo);//Se busca añadir a captura (modificar-Captura)

                    cout << "Los enlaces han sido modificados correctamente..." << endl;

                }
                // A ---> Clave     B ---> Modificar     C ----> captura
            }

        }
        else cout << "El enlace " << modificar << " no existe." << endl;
    }
    else{
        cout << "El enrutador " << clave << " no ha sido creado." << endl;
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
    validar(origen);

    if(redes.find(origen)!=redes.end()){// Se verifica que el enrutador ORIGEN exista
        cout << "Ingrese el destino: "; cin >> destino; validar(destino);

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

void red::asignar_enlaceEnrutador_txt(char clave, char captura, int costo )//captura=_nodo2
{
    enrutador enruta;
    //int conexiones=0;

    if(redes.find(clave)!=redes.end()){
            if(redes.find(captura)!=redes.end()){//Busca si el enrutador existe para poder asignar un enlace

                redes[clave].agregar_nodo_txt(captura, costo);

                //ENLACE BIDIRECCIONAL, es decir, se asigna el segundo enlace también
                redes[captura].agregar_nodo_txt(clave, costo);
                }

            else{
                cout << "El enlace no puede ser creado. El enrutador ingresado no existe." << endl;
                }
            }
        }

void red::iterar_txt(char clave )//captura=_nodo2
{
    enrutador enruta;
    if(redes.find(clave)!=redes.end()){//Busca si el enrutador existe para poder asignar un enlace
            map<char, enrutador>::iterator it;
            for(it=redes.begin(); it != redes.end(); it++){
                    redes[clave].asignacion(clave,it->first);                   
                    }
                }
            else{
                cout << "El enlace no puede ser creado. El enrutador ingresado no existe." << endl;
    }
}



void red::random_red( int nodo, float probabilidad)
{
    map<char, map<char,int>>redes;
    map <char,int>fila;//representa lo que tiene una fila por dentro
    map<char, int >::iterator itCol; //iterador que recorra las columnas
    map<char, map<char, int >>:: iterator itRed; //iterador que recorra las filas de la red

    enrutador enrut;

    char name='A';
    int contador,contador_, enlaces;
    //generar matriz de ceros y -1

    //recorremos por filas y luego dentro de cada una de ellas
    for (int i=0;i<nodo;i++){//para inicializar nombres para filas y columnas
        for ( int j=0;j<nodo;j++){
            if (i==j) fila.insert(pair<char,int>(name+j,0)); //i==j diagonal principal=0
            else fila.insert(pair<char,int>(name+j,-1)); //clave y dato
        }
    redes.insert(pair<char, map<char,int>>(name+i,fila));


    //redes.insert(pair<char,enrutadores>(name+i,fila));
    fila.clear();//eliminar la fila para poder ejecutar el ciclo
    }

    //recorrer triangulo superior de la matriz y refrejar en el opuesto
    //garantizar que todos los nodos tengan por lo menos una conexion
    for(itRed=redes.begin(),contador=1; itRed!= redes.end(); itRed++,contador++){ //ciclo doble que permita recorrer la red //A+1=B ...
        if (itRed!=redes.begin() && contador_==0){//el it ya ejecuto el codigo por una vez, no se realizo ninguna conexion
            contador--;
            itRed--;//devolverse a la fila  anterior
        }
        contador_=0; //cada que se inicie un nuevo nodo se reinicia el contador
        for(itCol = itRed->second.find(name+contador); itCol!=itRed->second.end(); itCol++){//empieza a moverse desde la segunda clave ...
              if (random(probabilidad)){ //probabilidad de los enlaces
                  enlaces=rand()%100+1;
                  itCol->second=enlaces; //al valor del mapa se le pasa un n aleatorio entre 1 y 100 del triangulo sup
                  redes[itCol->first][itRed->first]=enlaces;// mapa intero,clave del externo en el momento para el triangulo inf
                  contador_++;
              }
          }
    }
    imprimir(redes);
}

void red::dijsktra(char clave_origen, char destino)
{
   /* map<char, enrutador>::iterator it;
    for(it=redes.begin(); it != redes.end(); it++){
        //redes[clave].asignacion(it->first);
        redes[clave].asignacion(clave,it->first);  // ----------------------------------------->        ✔
        }
    }*/
    //AGREGAR DESTINO POR CONSOLA
    bool fin = false;
    map<char, enrutador>::iterator iterator;
    for(iterator = redes.find(clave_origen+1); iterator != redes.end(); iterator++){
        redes[clave_origen+1].asistenteDijkstra(clave_origen, iterator->first, destino, fin);
        if (fin == true){
            break;
        }
    }
}



red::red()
{

}
