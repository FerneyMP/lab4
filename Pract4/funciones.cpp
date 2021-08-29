#include "funciones.h"

string leer(string nombre)// lectura del archivo de texto
{
    string datos;
    fstream text;
        //nos basamos en el caracter de fin de candena
        text.open (nombre,fstream::in);
        //modo lectura, no se inventa en el archivo, errores de comprobacion
        if (text.is_open()){ //true-abrio
            // terminan con eof
            while(!text.eof())datos.push_back(text.get());
            datos.pop_back(); //elimina el ultimo caracter
        }
        else cout<< "El archivo no pudo ser abierto "   <<endl;
        text.close();
        return datos;
}

void validar(char name){
    bool flag=true;
    int letra;
    while(flag){
       letra=name;
       if ( (letra>=65 && letra<=90)||(letra>=97 && letra<=122 ) ){
           flag=false;
       }
       else {
           cout << "El nombre de la red debe ser un caracter letra\nIngrese el nombre de la red: "; cin >> name;
       }
}
}
