#include "enrutador.h"
#include "red.h"
#include "funciones.h"
int main()
{
    /*
    //SECCION DE PRUEBAS:
    red global;
    char _name = 'A';
    char _name1 = 'B';

    global.agregar_enrutador(_name);
    global.asignar_enlaceEnrutador(_name);
    //global.mostrar_tablaEnrutador(_name);
    //global.modificar_costoEnrutador(_name);
    //global.mostrar_tablaEnrutador(_name);

    global.agregar_enrutador(_name1);
    global.asignar_enlaceEnrutador(_name1);

    global.mostrar_red();
*/

//------------------------------------              PROGRAMA            -------------------------------------------------------

    cout << "\tBienvenido! " << endl;
        char entrada;
        int precio;
        short int menu_principal=0;
        string texto, nombre_ar;

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
                    global.modificar_costoEnrutador(_name);
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
                    cout << "6  " ;
                }
                if (entrada=='7'){
                    cout << "7  " ;
                    cout  << endl;
                }
                if (entrada=='8'){
                    cout << "8  " ;
                    cout  << endl;
                }
                if (entrada=='9'){

                    cout<<"Nombre del archivo fuente: "; cin>> nombre_ar;
                    texto=leer(nombre_ar+".txt");
                    cout<<texto;
                    cout<< endl<< endl;
                    char n,m,p;
                    for( int contador=0; texto[contador]!='\0';contador++){
                       for( int cont=0; texto[cont]!='\n';cont++){
                            n=texto[0];
                            m=texto[2];
                            p=texto[4];


                        }
                    }
                    cout << n;
                    cout << m ;
                    cout << p ;

                }

        }

    return 0;
}
