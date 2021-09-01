#include "enrutador.h"
#include "red.h"
#include "funciones.h"
int main()
{

    //SECCION DE PRUEBAS:

    /*red global;
    char _name = 'A';
    char _name1 = 'B';
    char _name2 = 'C';

    global.agregar_enrutador(_name);
    global.agregar_enrutador(_name1);
    global.agregar_enrutador(_name2);
    //global.eliminar_enrutador(_name1);

    global.asignar_enlaceEnrutador(_name);
    global.asignar_enlaceEnrutador(_name1);
    //global.asignar_enlaceEnrutador(_name2);


    //global.mostrar_tablaEnrutador(_name);
    //global.modificar_Enrutador(_name);
    //global.mostrar_tablaEnrutador(_name);


    //global.asignar_enlaceEnrutador(_name1);

    global.mostrar_red();

    //global.origen_destino();*/





//------------------------------------              PROGRAMA            -------------------------------------------------------

    cout << "\tBienvenido! " << endl;
        char entrada, _name;
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

                    cout << "Ingrese el nombre del enrutador : "; cin >> _name;
                    validar(_name);
                    global.agregar_enrutador(_name);
                    cout  << endl;
                }


                if (entrada=='2'){
                    system("clear");
                    cout << "Ingrese el nombre del enrutador : "; cin >> _name;
                    validar(_name);
                    global.eliminar_enrutador(_name);
                    cout  << endl;
                }


                if (entrada=='3'){
                    system("clear");
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
                    cout << "Ingrese el nombre del enrutador que desea ver: "; cin >> _name;
                    validar(_name);
                    global.mostrar_red();
                    cout  << endl;
                }


                if (entrada=='6'){
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

                            }


                if (entrada=='9'){
                    cout<<"Nombre del archivo fuente: "; cin>> nombre_ar;
                    string datos,linea,nodo1,nodo2,peso;
                    fstream text;
                    int _peso, contador_txt=0;
                    char _nodo1,_nodo2;
                    vector < char > valores;

                    nombre_ar=nombre_ar+".txt";
                    text.open (nombre_ar,fstream::in);
                    if (text.is_open()){ //true-abrio
                           ifstream archivo(nombre_ar);
                            while(getline(archivo, linea)){
                                nodo1=linea.substr(0,1); //posicion y longitud
                                nodo2=linea.substr(2,1);
                                peso=linea.substr(4,linea.length()-4); //1 2 peso

                                _nodo1=nodo1[0]; //obtener chars
                                _nodo2=nodo2[0];
                                _peso=atoi(peso.c_str()); //convertir str a int 1

                                validar(_nodo1);
                                validar(_nodo2);

                               valores.push_back(_nodo1);
                               valores.push_back(_nodo2);

                               global.agregar_enrutador(_nodo1);
                               global.agregar_enrutador(_nodo2);

                               global.asignar_enlaceEnrutador_txt(_nodo1,_nodo2,_peso);
                               contador_txt++;

                            }

                            vector <char> :: iterator it_v;
                            for (it_v=valores.begin();it_v!=valores.end();it_v++){
                                global.iterar_txt(*it_v);


                            }
                            cout<<"funciona"<<endl;


                        }
                        else cout<< "El archivo no pudo ser abierto "   <<endl;
                        text.close();
                }

        }

    return 0;
}
