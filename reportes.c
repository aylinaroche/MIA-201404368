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

mount montar[50];

int reporteMBR(char* id, char* name, char* path){
	printf("ID = %s\n",id);
//VERIFICA SI EL EL ID EXISTE
	 char nombre[6];
	 strcpy(nombre,id);
	 char num=nombre[3];
	 char* numMontado=&num;
	 char* direcc;
	 int numID= atoi(numMontado);
	 int i=0;
	 for(i=0;i<50; i++){
	     if(montar[i].id[2]==nombre[2] &&  montar[i].disco==numID && montar[i].estado=='1'){
	    	 direcc= montar[i].path;
	     break;
	   }
	 }
	if(i==50){
	    printf("ERROR: El ID no existe.\n");
	    return 0;
	}

//VERIFICA SI EL ARCHIVO EXISTE
	FILE* archivo;
	archivo = fopen(direcc,"rb+");
	if(archivo== NULL){
	     printf("ERROR: No existe el archivo.\n");
	    return 0;
	}
	mbr structDisco;
	fseek(archivo,0,SEEK_SET);
	fread(&structDisco,sizeof(mbr),1,archivo);

//CREA LA CARPETA SI NO EXISTE
	char direccion[200];
	char auxDirecc[200];
	 for(i=0;i<200;i++){
		 auxDirecc[i] ='\0';
	 }
	strcpy(direccion, path);

	for(i=0;i<200;i++){
	    if(direccion[i]=='/'){
	    	auxDirecc[i]=direccion[i];
	        char *aux7= (char*)malloc(150);
	        strcpy(aux7,"mkdir ");
	        strcat(aux7,auxDirecc);
	        system(aux7);
	        free(aux7);
	    }
	    auxDirecc[i]=direccion[i];
	    if(direccion[i]=='\0'){
	        break;
	    }
	}

//CREA EL REPORTE
	FILE* report;
	report = fopen("/home/aylin/Documentos/EclipseNeon/FileSystem/reporteMBR.dot","w+");
	fprintf(report,"digraph mbr{\n");
	fprintf(report,"rankdir = LR;\n");
	fprintf(report,"node [shape = record, fontsize=12,fontname=\"%s\", style=filled ,fillcolor=grey88, height = 0.7]; ","UBUNTU");
	fprintf(report,"Particion[label=\"");
	char fecha[100];
	struct tm *timeinfo;
	timeinfo = localtime(&structDisco.fecha);
	strftime(fecha,100,"%c",timeinfo);


	fprintf(report,"{%s}|{nombre | valor}|{mbr_tamano:| %d }|{ mbr_fecha:| %s }|{ mbr_disk_signature: | %d } ",direcc,structDisco.size,fecha,structDisco.sign);
	int a=0;
	for(a = 0;a<4;a++){
	    if(structDisco.part[a].status=='1'){
	        fprintf(report,"|{part_status_%d: | %c}| { part_type_%d: | %c} |{ part_fit_%d : | %c}| { part_start_%d :| %d}|{ part_size_%d:| %d }|{ part_name_%d :| %s} ",a,structDisco.part[a].status,a,structDisco.part[a].type,a,structDisco.part[a].fit,a,structDisco.part[a].start,a,structDisco.part[a].size,a,structDisco.part[a].name);
	    }
	}

	fprintf(report,"\"];\n");

	for(a=0;a<4;a++){
	   if(structDisco.part[a].type=='E' || structDisco.part[a].type=='e' ){
	    int i=0;
	    int ii=0;
	       for(i=0; i<8; i++){
	         if(structDisco.part[a].exten[i].status=='1'){
	             ii++;
	             fprintf(report,"Particion%d[label=\"",ii);
	             fprintf(report,"{EBR_%d}|{part_status_%d: | %c}|{ part_fit_%d : | %c}| { part_start_%d :| %d}|{ part_size_%d:| %d }|{ part_next_%d:| %d }|{ part_name_%d :| %s} ",ii,ii,structDisco.part[a].exten[i].status,ii,structDisco.part[a].exten[i].fit,ii,structDisco.part[a].exten[i].start,ii,structDisco.part[a].exten[i].size,ii,structDisco.part[a].exten[i].next,ii,structDisco.part[a].exten[i].name);
	        fprintf(report,"\"];\n");
	         }
	       }
	   }
	}
	   fprintf(report,"}\n");
	fclose(report);

	char consola[300];
	strcpy(consola,"");
	strcat(consola, "dot -Tjpg /home/aylin/Documentos/EclipseNeon/FileSystem/reporteMBR.dot  -o ");
	strcat(consola, auxDirecc);
	printf("%s\n",consola);
	system(consola);
	printf("-> Se creo el reporte correctamente.\n");
	char consola2[300];
	strcpy(consola2,"");
	strcat(consola2, "xdg-open ");
	strcat(consola2, auxDirecc);
	system(consola2);

}

int reporteDISK(char* id,char* name, char* path){
	printf("ID = %s\n",id);
//VERIFICA SI EL EL ID EXISTE
	 char nombre[6];
	 strcpy(nombre,id);
	 char num=nombre[3];
	 char* numMontado=&num;
	 char* direcc;
	 int numID= atoi(numMontado);
	 int i=0;
	 for(i=0;i<50; i++){
	     if(montar[i].id[2]==nombre[2] &&  montar[i].disco==numID && montar[i].estado=='1'){
	    	 direcc= montar[i].path;
	     break;
	   }
	 }
	if(i==50){
	    printf("ERROR: El ID no existe.\n");
	    return 0;
	}

//VERIFICA SI EL ARCHIVO EXISTE
	FILE* archivo;
	archivo = fopen(direcc,"rb+");
	if(archivo== NULL){
	     printf("ERROR: No existe el archivo.\n");
	    return 0;
	}
	mbr structDisco;
	fseek(archivo,0,SEEK_SET);
	fread(&structDisco,sizeof(mbr),1,archivo);

	char direccion[200];
	char auxDirecc[200];
	for(i=0;i<200;i++){
	     auxDirecc[i] ='\0';
	 }
	strcpy(direccion, path);

	for(i=0;i<200;i++){
	    if(direccion[i]=='/'){
	        auxDirecc[i]=direccion[i];
	        char *aux7= (char*)malloc(150);
	        strcpy(aux7,"mkdir ");
	        strcat(aux7,auxDirecc);
	        printf("direccion: %s\n",aux7);
	        system(aux7);
	        free(aux7);
	    }
	    auxDirecc[i]=direccion[i];
	    if(direccion[i]=='\0'){
	        break;
	    }
	}
	int par=0;
	FILE* report = fopen("/home/aylin/Documentos/EclipseNeon/FileSystem/reporteDISK.dot","w+");
	fprintf(report, "digraph particiones{\nrankdir=TB;\n node[shape = record];\nsubgraph cluster{\n");
	fprintf(report,"label=\"%s\"",direcc);
	    fprintf(report,"node8[label=\"MBR");
	int j=3;
	for(j=0;j<4;j++){

	    if(structDisco.part[j].status == '1' && (structDisco.part[j].type == 'P'|| structDisco.part[j].type=='p')){
	        fprintf(report,"|Primaria");
	        par++;

	    }else if(structDisco.part[j].status =='0' && structDisco.part[j].size!=0){
	        fprintf(report,"|Libre");
	        par++;
	    }else if(structDisco.part[j].status == '1' && (structDisco.part[j].type == 'E'|| structDisco.part[j].type=='e')){
	        fprintf(report,"|{exten|{");
	        int i=7;
	        for(i=0;i<8;i++){
	         if(structDisco.part[j].exten[i].status=='1'){
	         fprintf(report,"EBR|Logica |");
	         }else if(structDisco.part[j].exten[i].status=='0' && structDisco.part[j].exten[i].size!=0){
	             fprintf(report,"EBR|Libre |");
	         }
	        }
	        par++;
	        fprintf(report,"}}");
	    }

	}
	fprintf(report,"\"];\n\t}\n}");
	fclose(report);

	char consola[300];
	strcpy(consola,"");
	strcat(consola, "dot -Tjpg /home/aylin/Documentos/EclipseNeon/FileSystem/reporteDISK.dot  -o ");
	strcat(consola, auxDirecc);
	printf("%s\n",consola);
	system(consola);
	printf("-> Se creo el reporte correctamente.\n");
	char consola2[300];
	strcpy(consola2,"");
	strcat(consola2, "xdg-open ");
	strcat(consola2, auxDirecc);
	system(consola2);
}

