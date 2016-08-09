/*
 * acciones.h
 *
 *  Created on: 4/08/2016
 *      Author: aylin
 */
#ifndef ACCIONES_H_
#define ACCIONES_H_
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include <time.h>


void atributoDisco(char* coman);
void crearDisco();
int  cDisco(char* siz, char* unit, char*path, char* nom);
void imprimirDatos();
void limpiarVariables();
void metodoPrueba(FILE *f1);
int  eliminarDisco();
void adminParticion();
int  crearParticion(char* path,char* name,char* siz,char* unit,char* type,char* fit);
int  agregarParticion(char* add,char* unit,char* path,char* name);
int  eliminarParticion(char* dele,char* path,char* name);


#endif /* ACCIONES_H_ */
