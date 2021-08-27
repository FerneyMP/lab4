#include "inventario.h"

inventario::inventario()
{
    cr[0]="Codigo";
    cr[1]="Nombre";
    cr[2]="Cantidad";
    cr[3]="Bodega";
    cr[4]="Precio";
    cr[5]="Seccion";
    cr[6]="Peso";
}

void inventario::agregar_producto(unsigned long long cod)
{
    producto pro;
    string cu;
    if(inv.find(cod)==inv.end()){
        for(int i=0; i<7; i++){
            cout << "Ingrese la cualidad " << cr[i] << " del producto: ";
            getline(cin,cu);
            getline(cin,cu);
            pro.agregar(cr[i],cu); //Agregando desde el inventario en un producto particular
        }
        inv.insert(pair<unsigned long long, producto>(cod,pro)); //Se guarda en el mapa de inventario
    }
}

void inventario::eliminar(unsigned long long cod)
{
    if(inv.find(cod)!=inv.end()){
        inv.erase(cod);
    }
}

void inventario::modificar(unsigned long long cod)
{
    string g;
    int m;
    if(inv.find(cod)!=inv.end()){
        cout << "Ingrese:\n 0 mod Codigo\n 1 mod Nombre\n2 mod Cantidad\n3 mod Bodega\n4  mod precio\n5 mod Seccion\n6 mod Peso";
        cin >> m;
        cout << "Ingrese el nuevo valor de la cualidad: ";
        getline(cin,g);
        if(m>=0 && m<=6) inv[cod].modificar_interno(cr[m], g);
    }
}

void inventario::print()
{
    map<unsigned long long, producto>::iterator it;
    for(int i=0; i<7;i++){
        cout << cr[i] << '\t';
        cout << "\n\n";
    }
    for(it=inv.begin(); it!=inv.end();it++){
        cout << it->first << '\t';
        it->second.mostrar();
        cout << '\n';
    }
}
