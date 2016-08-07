/*
 * estructuras.h
 *
 *  Created on: 4/08/2016
 *      Author: aylin
 */

#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

#include <time.h>


typedef struct EBR{
    char status;
    char fit;
    int start;
    int size;
//    int sizeaux;
    int next;
    char name[16];
}ebr;

typedef struct PARTICION{
    char status; //1 activa, 0 caida
    char type;
    char fit;
    int start;
    int size;
   // int sizeaux;
    char name[16];
    ebr extendida[8];
}particion;


typedef struct MBR{ //Master Boot Record -> Registro de arranque principal
    int size;
    time_t fecha;
    int sign;
    particion part[4];
}mbr;

#endif /* ESTRUCTURAS_H_ */
