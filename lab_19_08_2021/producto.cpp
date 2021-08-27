#include "producto.h"

void producto::modificar_interno(string name, string value)
{
    //map<string, string>::iterator it;
    if(ca.find(name)!=ca.end()){
        ca[name]=value;
    }
}

void producto::agregar(string name, string value)
{
    if(ca.find(name)==ca.end()){ // si un elemento existe dentro de un mapa
        ca.insert(pair<string,string>(name,value)); //Agregar un nuevo elemento dentro del contenedor
    }
}

void producto::eliminar(string name)
{
    if(ca.find(name)!=ca.end()){
        ca.erase(name);
    }
}

void producto::mostrar()
{
    map<string, string>::iterator it;
    for(it=ca.begin(); it!=ca.end();it++){
        cout << it->second << '\t';
    }

}
