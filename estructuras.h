/*
 * estructuras.h
 *
 *  Created on: 4/08/2016
 *      Author: aylin
 */

#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

#include <time.h>

typedef struct Montar{ //Cola para realizar el mount
    char path[70];
    char name[40];
    int  var;
    int  part;
    char *vdID;
    int  estado;
    int	 uso;
}mount;

typedef struct EBR{
    char status;
    char fit;
    int  start;
    int  size;
    int  auxiliar;
    int  next; //Byte en el que esta el sigueinte ebr -1 si no hay
    char name[16];
}ebr;

typedef struct PARTICION{
    char status; //1 activa, 0 caida
    char type;
    char fit; //ajuste
    int  start;//en que byte inicia
    int  size;
    int  auxiliar;
    char name[16];
    ebr  exten[20];
}particion;


typedef struct MBR{ //Master Boot Record -> Registro de arranque principal
    int    size;
    time_t fecha;
    int    sign;
    particion part[4];
}mbr;

#endif /* ESTRUCTURAS_H_ */
