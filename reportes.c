/*
 * reportes.c
 *
 *  Created on: 9/08/2016
 *      Author: aylin
 */
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "reportes.h"
#include "estructuras.h"

mount mont[50];
/*
int reporte(){


	  char aux[6];
	    strcpy(aux,id);
	    char aux2=aux[3];
	    char* aux3=&aux2;
	    char* aux4;
	    int id2= atoi(aux3);
	    int i=0;
	    for(i=0;i<50; i++){
	        if(mont[i].id[2]==aux[2] &&  mont[i].disco==id2 && mont[i].estado=='1'){
	        aux4= mont[i].path;
	        break;
	      }
	    }
	if(i==50){
	    printf("el ID no existe");
	    return 0;
	}

	FILE* disco;
	disco = fopen(aux4,"rb+");
	if(disco== NULL){
	     printf("no existe el disco");
	    return 0;
	}
	mbr lec;
	fseek(disco,0,SEEK_SET);
	fread(&lec,sizeof(mbr),1,disco);


	char aux5[200];
	 char aux6[200];
	 for(i=0;i<200;i++){
	     aux6[i] ='\0';
	 }
	strcpy(aux5, path);

	for(i=0;i<200;i++){
	    if(aux5[i]=='/'){
	        aux6[i]=aux5[i];
	        char *aux7= (char*)malloc(150);
	        strcpy(aux7,"mkdir ");
	        strcat(aux7,aux6);
	        system(aux7);
	        free(aux7);
	    }
	    aux6[i]=aux5[i];
	    if(aux5[i]=='\0'){
	        break;
	    }
	}

	FILE* report;
	report = fopen("/home/aylin/Documentos/EclipseNeon/FileSystem/MBRreporte.dot","w+");
	fprintf(report,"digraph mbr{\n");
	fprintf(report,"rankdir = LR;\n");
	fprintf(report,"node [shape = record, fontsize=12,fontname=\"%s\", style=filled ,fillcolor=grey88, height = 0.7]; ","UBUNTU");
	fprintf(report,"Particion[label=\"");
	char fecha[100];
	struct tm *timeinfo;
	timeinfo = localtime(&lec.
}
	*/
