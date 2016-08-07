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
char *com7=NULL;
char *com8=NULL;

void verificarComando(char *com, char *atributos){
	limpiarVariables();

     char* inst=NULL;
     int cont=1;

    if(strcasecmp(com,"mkdisk")==0 ||  strcasecmp(com,"Mkdisk")==0 || strcasecmp(com,"MKDISK")==0 || strcasecmp(com,"MKdisk")==0) {
    printf("mkdisk\n");
    char atr[200];
         strcpy(atr,atributos);
         int j;
         for(j=0;j<200;j++){
         if(atr[j]=='\\'){
        	 atr[j]=' ';
         }
         }
     strcpy(atributos,atr);
     printf("ATR= %s\n",atributos);
    char aux[100];
    strcpy(aux, atributos);
    inst = strtok(atributos," ");
  //  printf("inst = %s\n",inst);
    while(inst!=NULL){
    	inst = strtok(NULL, " ");
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

    }else  if(strcasecmp(com,"rmdisk")==0 || strcasecmp(com,"Rmdisk")==0 || strcasecmp(com,"RMdisk")==0 || strcasecmp(com,"RMDISK")==0 ){
    	 printf("rmdisk\n");
    	    char atr[200];
    	         strcpy(atr,atributos);
    	         int j;
    	         for(j=0;j<200;j++){
    	         if(atr[j]=='\\'){
    	        	 atr[j]=' ';
    	         }
    	         }
    	     strcpy(atributos,atr);
    	     printf("ATR= %s\n",atributos);
    	    char aux[100];
    	    strcpy(aux, atributos);
    	    inst = strtok(atributos," ");
    	  //  printf("inst = %s\n",inst);
    	    while(inst!=NULL){
    	    	inst = strtok(NULL, " ");
    			switch(cont){
    			case 1:
    				com1=inst;
    				break;
    			}
    			cont++;
    	    }
    	    int i;
    	    for(i=1;i<cont-1;i++){
    	    	if(i==1){
    	    	atributoDisco(com1);
    	    	}
    	    }
    	    imprimirDatos();
    	    eliminarDisco();

    } else  if(strcasecmp(com,"fdisk")==0 || strcasecmp(com,"Fdisk")==0 || strcasecmp(com,"FDISK")==0 || strcasecmp(com,"FDisk")==0 ){
            printf("fdisk\n");
            char atr[200];
                    strcpy(atr,atributos);
                    int j;
                    for(j=0;j<200;j++){
                    if(atr[j]=='\\'){
                   	 atr[j]=' ';
                    }
                    }
                strcpy(atributos,atr);
                printf("ATR= %s\n",atributos);
               char aux[100];
               strcpy(aux, atributos);
               inst = strtok(atributos," ");
             //  printf("inst = %s\n",inst);
               while(inst!=NULL){
               	inst = strtok(NULL, " ");
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
           		case 5:
           		    com5=inst;
           		    break;
           		case 6:
           		    com6=inst;
           		    break;
           		case 7:
           		    com7=inst;
           		    break;
           		case 8:
           		      com8=inst;
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
               	}else if(i==5){
               	atributoDisco(com5);
               	}else if(i==6){
               	atributoDisco(com6);
               	}else if(i==7){
               	atributoDisco(com7);
               	}else if(i==8){
               	atributoDisco(com8);
               	}
               }
               imprimirDatos();


    } else  if(strcasecmp(com,"mount")==0 ||strcasecmp(com,"MOUNT")==0  ){
           printf("mount\n");
    } else  if(strcasecmp(com,"unmount")==0 ||strcasecmp(com,"UNMOUNT")==0  ){
             printf("unmount\n");

    }
}
