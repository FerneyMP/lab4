#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "enrutador.h"

void validar(char &name);
void validar(int &nodo);
void validar(float &probabilidad);
bool random (float &probabilidad);

void imprimir (map <char, map <char,int>>red);// (redes random )


#endif // FUNCIONES_H
