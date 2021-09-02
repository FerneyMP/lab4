#include "enrutador.h"


void enrutador::agregar_nodo(char clave, int costo)
{
    if(enrutadores.find(clave)==enrutadores.end()){ // revisa si un elemento existe dentro de un mapa, el .find() retorna un .end()
        //si no encuentra dicho mapa con clave tal, significa que que no existe el mapa y permite continuar con el condicional.
        enrutadores.insert(pair<char, int>(clave,costo)); //Agrega un nuevo elemento dentro del contenedor.
    }
}

void enrutador::eliminar_nodo(char clave)
{
    if(enrutadores.find(clave)!=enrutadores.end()){ // revisa si un elemento existe dentro de un mapa, el .find() retorna un .end()
        //si es diferente al .end() significa que si existe dicho mapa con clave buscada.
        enrutadores.erase(clave);//Elimina el mapa con dicha clave buscada.
    }
}


void enrutador::modificar(char clave, string costo, bool modo, char modificar, char captura, int valor_nuevo)
{
    map<char, int>::iterator it;
    int reinicio = -1;    
    //Modificar tiene una opción dual, que permite modificar solamente el costo de enlace, o modificar el enlace + el costo
    if (modo){//Si se desea modificar solo el costo
        if(enrutadores.find(clave)!=enrutadores.end()){
            enrutadores[clave] = atoi(costo.c_str()); //"Indexa" el mapa con clave buscada y asigna el valor entero después del igual,
            //es decir, lo reemplaza con el valor de costo.            
        }
    }
    else{//Si se desea modificar el enlace + el costo               

        //ENTRO AL ENRUTADOR CON CLAVE, ejemplo(A)

        for(it=enrutadores.begin(); it!=enrutadores.end(); it++){// se asigna un iterador que recorre el mapa clave por clave hasta el final
            //RECORRO LAS CLAVES

            //             modificar
            if(enrutadores[clave] == enrutadores[it->first]){//Se busca el enlace a modificar
                //SI ENCUENTRO LA CLAVE A MODIFICAR, la modifico

                enrutadores.erase(modificar); //elimino la conexión
                //Se hace bidireccional desde la red, dado que se hace lo mismo pero con argumentos diferentes

                //enrutadores.insert(pair<char, int>(captura, valor_nuevo));
                enrutadores[captura] = valor_nuevo;
                enrutadores.insert(pair<char, int>(modificar, reinicio));
                //ETAPA 1: borrado y almacenamiento de enlaces
                // A ---> Clave     B ---> Modificar     C ----> captura

            }
        }
    }

}

void enrutador::modificar(char inverso, int valor_nuevo, char clave)
{

    map<char, int>::iterator it;
    for(it=enrutadores.begin(); it!=enrutadores.end(); it++){// se asigna un iterador que recorre el mapa clave por clave hasta el final
        if(enrutadores[inverso] == enrutadores[it->first]){//Se busca el enlace a modificar
            enrutadores[clave] = valor_nuevo;
        }

    }
}

void enrutador::modificar(char modificar, char clave)
{
    // A ---> Clave     B ---> Modificar     C ----> captura
    int reinicio = -1;
    map<char, int>::iterator it;
    for(it=enrutadores.begin(); it!=enrutadores.end(); it++){// se asigna un iterador que recorre el mapa clave por clave hasta el final
        if(enrutadores[modificar]== enrutadores[it->first]){
            enrutadores.erase(clave); //elimino la conexión con el recíproco
            enrutadores.insert(pair<char, int>(clave, reinicio));
            }
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

void enrutador::mirar_enrutadores_contiguos(char clave, char destino)
{    
    int captura;
    if(enrutadores.find(clave)!=enrutadores.end()){
        cout << "Accediendo al enrutador con clave: " << clave << " ...";
        cout << endl;        
        //AGREGAR VALIDACIÓN (char y existencia del enrutador)
        if(enrutadores.find(destino)!=enrutadores.end()){//Para verificar que exista el enrutador destino
            captura = enrutadores[destino]; //Se le asigna a captura el valor que contiene el enrutador "indexado" con destino
            cout << "El costo de envio del paquete de " << clave << " a " << destino << " es de: " << captura << endl;
        }
        else{

            cout << "El enrutador ingresado no pertecene a la tabla de enrutamiento." << endl;
        }
    }
    else{
        cout << "El enrutador ingresado no pertecene a la tabla de enrutamiento." << endl;
    }
}
void enrutador::asignacion(char clave, char destino)
{
    int costo = -1;
    if(enrutadores.find(clave)!=enrutadores.end()){//Para verificar que exista el enrutador con clave - clave
        if(enrutadores.find(destino)==enrutadores.end()){//Si enrutadores.find(destino) es igual al .end, significa que no existe, al no existir
            enrutadores.insert(pair<char, int>(destino,costo));//se agrega el valor del enrutador con el que no se tiene enlace y se le pone -1
        }
    }
    else{
        cout << "El enrutador ingresado no pertecene a la tabla de enrutamiento." << endl;
    }
}


void enrutador::agregar_nodo_txt(char clave, int costo)
{
   map<char, int>::iterator it;
   if(enrutadores.find(clave)==enrutadores.end()){ // revisa si un elemento existe dentro de un mapa, el .find() retorna un .end()
        //si no encuentra dicho mapa con clave tal, significa que que no existe el mapa y permite continuar con el condicional.
        enrutadores.insert(pair<char, int>(clave,costo)); //Agrega un nuevo elemento dentro del contenedor.
    }
    else  enrutadores[clave] =costo;
}


void enrutador::asistenteDijkstra(char clave_origen, char iterador, char destino, bool &fin)
{
    map<char, int>::iterator asiste;
    //int almacenador=0;
    for(asiste = enrutadores.find(clave_origen); asiste != enrutadores.end(); asiste++){
        if(enrutadores.find(iterador) != enrutadores.end()){
            if(asiste->second == -1 || asiste->second ==0){
                ;
            }
            else{
            int acumulador = enrutadores[asiste->first];
            char acumulador2 = asiste->first;
            if(asiste->second < (asiste->second+1)){//PENSAR EN CORREGIR ESTO
                cout << "Los caminos mas eficientes son: " << endl;
                cout << acumulador << " ---> " << acumulador2 << endl;
                acumulador = acumulador + asiste->second;
                acumulador2 -= asiste -> first;
                if(asiste->first == destino){
                    fin = true;
                    break;
                    }
                }
            }
            /*
             if(asiste->second <= enrutadores[asiste->first] ){
                cout << "Los caminos mas eficientes son: " << endl;
                acumulador += enrutadores[asiste->first];
                cout << acumulador << " ---> " << asiste->first << endl;

            }*/
        }
    }
}
