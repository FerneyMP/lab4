#include "funciones.h"


void validar(char &name){
    bool flag=true;
    int letra;
    while(flag){
       letra=name;
       if ( (letra>=65 && letra<=90)||(letra>=97 && letra<=122 ) ){//letra>=63 && letra<=92
           flag=false;
       }
       else {
           cout << "El nombre de la red debe ser un caracter letra\nIngrese el nombre de la red: "; cin >> name;
       }
    }
}

void validar(int &nodo)
{
    bool flag=true;
    while(flag){
        if (nodo>=2 && nodo<=54) flag=false;
        else {
            cout << "Ingrese UNICAMENTE un numero entre 2 y 54 para los nodos: "; cin >> nodo;
        }
    }

}

void validar(float &probabilidad)
{
    bool flag=true;
    while(flag){
        if (probabilidad>=0 && probabilidad<=1) flag=false;
        else {
            cout <<  "Ingrese UNICAMENTE un numero entre 0 y 1 para la probabilidad: "; cin >> probabilidad;
        }
    }

}

bool random(float &probabilidad)
{
  float y;
  int ran;
  bool l;

  y=probabilidad*(RAND_MAX+1)-1;//numero cualquiera menor a un valor particular
  ran=rand();//crear numero aleatorio
  //rand:genera numeros aleatorios con densidad de probabilidad uniforme (igual probabilidad para todos: 1/randmax+1(total))
  l= ran<=y ;//l va a ser verdadero si ran <= a el limite y

  return l;

}

//crear n nodos, generar nombres para los n nodos
//enlaces y pesos aleatorios (usar simetria)
//booleano sobre cada conexion


void imprimir(map<char, map<char, int>> red)//imprime la matriz
{
    map<char, int >::iterator itCol; //iterador que recorra las columnas
    map<char, map<char, int >>:: iterator itRed; //iterador que recorra las filas de la red
    bool ban=true;
    cout<<endl;

    for(itRed=red.begin(); itRed!= red.end(); itRed++){   //recorrer filas y columnas de la tabla
        if (ban==true){//solo se realiza una vez
          cout<<' '<<'\t';  //imprime el espacio inicial
          for(itCol = itRed->second.begin(); itCol!=itRed->second.end(); itCol++){
                cout<<itCol->first<<'\t';//imprimir el nombre de red (parte superior)
          }
          cout<<endl<<endl;
          ban=false;
        }
        cout<<itRed->first<<'\t';  //imprimir el nombre de red fila tras fila (parte lateral)
        for(itCol = itRed->second.begin(); itCol!=itRed->second.end(); itCol++){//se posiciona en el valor que se encuentra dentro de itred, se ejecuta hasta llegar al final de la fila
            cout<<itCol->second<<'\t';
        }
        cout<<endl<<endl;
}
}
