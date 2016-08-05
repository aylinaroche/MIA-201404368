/*
 * comandos.c
 *
 *  Created on: 4/08/2016
 *      Author: aylin
 */
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "comandos.h"

char *com1=NULL;
char *com2=NULL;
char *com3=NULL;
char *com4=NULL;
char *com5=NULL;
char *com6=NULL;

void verificarComando(char *com, char *atributos){
     char* inst=NULL;
     int cont=1;

    if(strcasecmp(com,"mkdisk")==0 ||  strcasecmp(com,"Mkdisk")==0 || strcasecmp(com,"MKDISK")==0 || strcasecmp(com,"MKdisk")==0) {
    printf("mkdisk\n");
    char aux[100];
    strcpy(aux, atributos);
    inst = strtok(atributos," ");
  //  printf("inst = %s\n",inst);
    while(inst!=NULL){
    	inst = strtok(NULL, " ");
		//printf("A = %s\n", inst);
		//printf("cont= %d\n",cont);
		switch(cont){
		case 1:
			com1=inst;
			break;
		case 2:
			com2=inst;
			break;
		case 3:
			com3=inst;
			break;
		case 4:
			com4=inst;
			break;
		}
		cont++;
    }
    int i;
    for(i=1;i<cont-1;i++){
    	if(i==1){
    	atributoDisco(com1);
    	}else if(i==2){
    	atributoDisco(com2);
    	}else if(i==3){
    	atributoDisco(com3);
    	}else if(i==4){
    	atributoDisco(com4);
    	}
    }
    imprimirDatos();
    crearDisco();

    }else  if(strcasecmp(inst,"rmdisk")==0 || strcasecmp(inst,"Rmdisk")==0 || strcasecmp(inst,"RMdisk")==0 || strcasecmp(inst,"RMDISK")==0 ){
    }
}
