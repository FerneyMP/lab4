#include "enrutador.h"
#include "red.h"
#include "funciones.h"
int main()
{

    //SECCION DE PRUEBAS:

    red global;
    char _name = 'A';
    char _name1 = 'B';
    char _name2 = 'C';

    global.agregar_enrutador(_name);
    global.agregar_enrutador(_name1);
    global.agregar_enrutador(_name2);
    //global.eliminar_enrutador(_name1);

    global.asignar_enlaceEnrutador(_name);
    //global.mostrar_tablaEnrutador(_name);
    global.modificar_Enrutador(_name);
    //global.mostrar_tablaEnrutador(_name);


    //global.asignar_enlaceEnrutador(_name1);

    global.mostrar_red();

    //global.origen_destino();





//------------------------------------              PROGRAMA            -------------------------------------------------------

    cout << "\tBienvenido! " << endl;
        char entrada;
        int precio;
        short int menu_principal=0;
        string texto, nombre_ar;

        //random redes
        float probabilidad;
        int nodo;

        red global;

        while (menu_principal==0){

            cout << "0. Salir"
                    "\n1. Agregar enrutador"
                    "\n2. Eliminar enrutador"
                    "\n3. Cambiar costo de un enlace"
                    "\n4. Visualizar la tabla del enrutador"
                    "\n5. Visualizar la tabla de la red"
                    "\n6. Precio del envio"
                    "\n7. Camino eficiente"
                    "\n8. Generar redes de forma aleatoria"
                    "\n9. Cargar desde un .txt"
                    "\nFavor ingresar una opcion: " ;
            cin>>entrada;

            while ((entrada<'0') || (entrada>'9')){
                cout << "El valor no esta permitido, intente nuevamente  " ;  cin>>entrada;
           }
                if (entrada=='0'){
                    cout<<"Gracias por usar nuestros servicios :)"<<endl;
                    cout  << endl;
                    menu_principal =1;
                }


                if (entrada=='1'){
                    system("clear");
                    char _name;
                    cout << "Ingrese el nombre del enrutador : "; cin >> _name;
                    validar(_name);
                    global.agregar_enrutador(_name);
                    cout  << endl;
                }


                if (entrada=='2'){
                    system("clear");
                    char _name;
                    cout << "Ingrese el nombre del enrutador : "; cin >> _name;
                    validar(_name);
                    global.eliminar_enrutador(_name);
                    cout  << endl;
                }


                if (entrada=='3'){
                    system("clear");
                    char _name;
                    cout << "Ingrese el nombre del enrutador que desea modificar: "; cin >> _name;
                    validar(_name);
                    global.modificar_Enrutador(_name);
                    cout  << endl;
                }


                if (entrada=='4'){
                    system("clear");
                    char _name;
                    cout << "Ingrese el nombre del enrutador que desea ver: "; cin >> _name;
                    validar(_name);
                    global.mostrar_tablaEnrutador(_name);
                    cout  << endl;
                }


                if (entrada=='5'){
                    system("clear");
                    char _name;
                    cout << "Ingrese el nombre del enrutador que desea ver: "; cin >> _name;
                    validar(_name);
                    global.mostrar_red();
                    cout  << endl;
                }


                if (entrada=='6'){
                //metodo de djstra
                    cout << "6  " ;
                }


                if (entrada=='7'){
                    cout << "7  " ;
                    cout  << endl;
                }


                if (entrada=='8'){

                    cout << "Ingrese un numero entre 2 y 54 para los nodos: "; cin >> nodo;
                    validar(nodo);
                    cout << "Ingrese un valor entre el 0 y el 1 para la probabilidad: "; cin >> probabilidad;
                    validar(probabilidad); //poca probabilidad, pocos enlaces
                    //booleano de forma aleatoria de acuerdo a la probabilidad y asi decidir cuales enlaces se mantienen
                    srand(time(NULL)); //crear la semilla

                            //-----------------------------------------------------------------------
                            //implementar en las clases?

                            map<char, map<char,int>>red; //matriz d adyacencia, red, se aplica operaciones
                            map <char,int>fila;//representa lo que tiene una fila por dentro
                            map<char, int >::iterator itCol; //iterador que recorra las columnas
                            map<char, map<char, int >>:: iterator itRed; //iterador que recorra las filas de la red

                            char name='A';
                            int contador,contador_, enlaces;
                            //generar matriz de ceros y -1

                            //recorremos por filas y luego dentro de cada una de ellas
                            for (int i=0;i<nodo;i++){//para inicializar nombres para filas y columnas
                                for ( int j=0;j<nodo;j++){
                                    if (i==j) fila.insert(pair<char,int>(name+j,0)); //i==j diagonal principal=0
                                    else fila.insert(pair<char,int>(name+j,-1)); //clave y dato
                            }
                            red.insert(pair<char, map <char,int>>(name+i,fila));
                            fila.clear();//eliminar la fila para poder ejecutar el ciclo
                             }
                            //recorrer triangulo superior de la matriz y refrejar en el opuesto
                            //garantizar que todos los nodos tengan por lo menos una conexion
                            for(itRed=red.begin(),contador=1; itRed!= red.end(); itRed++,contador++){ //ciclo doble que permita recorrer la red //A+1=B ...
                                if (itRed!=red.begin() && contador_==0){//el it ya ejecuto el codigo por una vez, no se realizo ninguna conexion
                                    contador--;
                                    itRed--;//devolverse a la fila  anterior
                                }
                                contador_=0; //cada que se inicie un nuevo nodo se reinicia el contador
                                for(itCol = itRed->second.find(name+contador); itCol!=itRed->second.end(); itCol++){//empieza a moverse desde la segunda clave ...
                                      if (random(probabilidad)){ //probabilidad de los enlaces
                                          enlaces=rand()%100+1;
                                          itCol->second=enlaces; //al valor del mapa se le pasa un n aleatorio entre 1 y 100 del triangulo sup
                                          red[itCol->first][itRed->first]=enlaces;// mapa intero,clave del externo en el momento para el triangulo inf
                                          contador_++;
                                      }
                                  }
                            }
                            imprimir(red);
                  }



                if (entrada=='9'){
                    cout<<"Nombre del archivo fuente: "; cin>> nombre_ar;
                    string datos,linea,nodo1,nodo2,peso;
                    fstream text;
                    int _peso;
                    char _nodo1,_nodo2;

                    nombre_ar=nombre_ar+".txt";
                    text.open (nombre_ar,fstream::in);
                    if (text.is_open()){ //true-abrio
                           ifstream archivo(nombre_ar);
                            while(getline(archivo, linea)){
                                nodo1=linea.substr(0,1); //posicion y longitud
                                nodo2=linea.substr(2,1);
                                peso=linea.substr(4,linea.length()-4); //1 2 peso

                                //agregar enrutadores y pesos
                                //agregar a los otros enrutadores

                                _nodo1=nodo1[0]; //obtener chars
                                _nodo2=nodo2[0];
                                _peso=atoi(peso.c_str()); //convertir str a int 1

                                //cout<<_nodo1 << _nodo2 << _peso<<endl<<endl;

                                validar(_nodo1);
                                global.agregar_enrutador(_nodo1);//TERMINAR
                               // global.asignar_enlaceEnrutador_txt(_nodo1, _peso);//TERMINAR
                                cout  << endl;

                            }
                        }
                        else cout<< "El archivo no pudo ser abierto "   <<endl;
                        text.close();
                }

        }

    return 0;
}
