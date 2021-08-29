#include "funciones.h"

int main()
{
    string texto, nombre_ar;
    cout<<"Nombre del archivo fuente: "; cin>> nombre_ar;
    texto=leer(nombre_ar+".txt");
    cout<<texto;
    cout<< endl<< endl;
    char n,m;
    string p;
    int inicio=0;
    int medio=2;

    for( int contador=0; texto[contador]!='\0';contador++){
        inicio = 0;
        medio+=2;
       for( int cont=0; texto[cont]!='\n';cont++){
            n=texto[inicio];
            m=texto[medio];
            p+=texto[cont];
        }

       //TODO EL MENU PRINCIPAL

       inicio++;
       medio+=2;
    }


    cout << n;
    cout << m ;
    cout << p ;







    //-------------------------------------------****-------------------------------------------------------



    /*
    //GENERACIÓN DE TABLA DE ADYACENCIA:

    unsigned int n = 4;
    //int costo = 0;
    string AB = "4";
    string BD = "6";
    string BC = "5";
    string DC = "7";




    //int *tabla = new int[n];

    unsigned int **tabla = new unsigned int*[n];
    for (unsigned int i = 0; i < n; i++) {
        tabla[i] = new unsigned int[n];
    }

    for(unsigned int i = 0; i<(2*n); i++){
        for(unsigned int j=0; j<n; j++){
            if(i==j){
                tabla[i][j] = 0;
            }
            if()
        }
    }

    delete[] tabla;*/

    return 0;
}
