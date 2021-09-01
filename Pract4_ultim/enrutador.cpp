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


void enrutador::modificar(char clave, string costo, bool modo, char captura)
{
    map<char, int>::iterator it;
    //Modificar tiene una opción dual, que permite modificar solamente el costo de enlace, o modificar el enlace + el costo
    if (modo){//Si se desea modificar solo el costo
        if(enrutadores.find(clave)!=enrutadores.end()){
            enrutadores[clave] = atoi(costo.c_str()); //"Indexa" el mapa con clave buscada y asigna el valor entero después del igual,
            //es decir, lo reemplaza con el valor de costo.
        }
    }
    else{//Si se desea modificar el enlace + el costo
        enrutador enruta;
        //char captura;
        //int valor_antiguo=0;
        int valor_nuevo=0;
        //string cap;
        if(enrutadores.find(clave)!=enrutadores.end()){
            //cout << "Ingrese el nuevo enlace: ";
            //cin >> captura;
            //AGREGAR VALIDACIÓN
            for(it=enrutadores.begin(); it!=enrutadores.end();it++){
                if(enrutadores[clave] == enrutadores[it->first]){//Se busca el enlace a modificar
                    cout << "Ingrese el nuevo valor del enlace: ";
                    cin >> valor_nuevo;
                    //AGREGAR VALIDACIÓN


                    //cap = (it->second);
                    //cap = it->second;
                    //valor_antiguo = atoi(&cap[0]);
                }
                /*if(enrutadores[clave] == enrutadores[it->first]){
                    enrutadores.find(clave);
                    valor_antiguo = enrutadores[it->second];
                }*/
            }
            enrutadores.erase(clave); //Se eliminar el anterior enlace
            enrutadores.insert(pair<char, int>(captura,valor_nuevo)); //Se añade el nuevo enlace + su valor ingresado por consola
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
    else  enrutadores[clave] =costo;//if (enrutadores[clave] == -1){
}
