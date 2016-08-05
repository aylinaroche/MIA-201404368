/*
 * acciones.c
 *
 *  Created on: 4/08/2016
 *      Author: aylin
 */
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "acciones.h"
#include "estructuras.h"

char* siz=NULL;
char* unit=NULL;
char* path=NULL;
char* type=NULL;
char* fit=NULL;
char* dele=NULL;
char* name=NULL;
char* add=NULL;
char* id=NULL;

void atributoDisco(char* coman){
//printf("atributo disco %s\n",coman);
        char* token1;
        char* com=coman;
        token1=strtok(com,":");
        //printf("T = %s\n",token1);
        if(token1==NULL){ }else
        if(strcasecmp(token1,"-size")==0){ //Verifica cada atributo
            token1=strtok(NULL,":");
            siz=token1;
        }else if(strcasecmp(token1,"+unit")==0){
            token1=strtok(NULL,":");
            unit=token1;
        }else if(strcasecmp(token1,"-path")==0){
             token1=strtok(NULL,":");

             char direccion[200];
              strcpy(direccion,token1);
              if(direccion[0]=='"'){
            int i=0;
              while(direccion[i+1]!='"'){ //Le quita las comillas
                  direccion[i]=direccion[i+1];
                  if(direccion[i]==' '){
                   direccion[i]='_';
                  }
               i++;
              }
              direccion[i]='\0';
              direccion[i+1]='\0';
              }
           strcpy(token1,direccion);
       path=token1;
       }else if(strcasecmp(token1,"+type")==0){
            token1=strtok(NULL,":");
            type=token1;
        }else if(strcasecmp(token1,"+fit")==0){
            token1=strtok(NULL,":");
            fit=token1;
        }else if(strcasecmp(token1,"+delete")==0){
            token1=strtok(NULL,":");
            dele=token1;
        }else if(strcasecmp(token1,"-name")==0){
            token1=strtok(NULL,":");
            char nombre[200];
            strcpy(nombre,token1);
            if(nombre[0]=='"'){
            int i=0;
                  while(nombre[i+1]!='"'){ //Le quita las comillas
                     	nombre[i]=nombre[i+1];
                        if(nombre[i]==' '){
                          	nombre[i]='_';
                        }
                         i++;
                   }
                  nombre[i]='\0';
                  nombre[i+1]='\0';
             }
             strcpy(token1,nombre);
            name=token1;
        }else if(strcasecmp(token1,"+add")==0){
            token1=strtok(NULL,":");
            add=token1;
        }else if(strcasecmp(token1,"-id")==0){
            token1=strtok(NULL,":");
            id=token1;
}
}

void crearDisco(){
	cDisco(siz,unit,path,name);
}

int cDisco(char* siz, char* unit, char*path, char* name){
 int aux=0;
    if(strcmp(unit,"M")==0 || strcmp(unit,"m")==0 ){
       aux =1;
  }  else if(strcmp(unit,"K")==0 || strcmp(unit,"k")==0 ){
        aux=2;
    }else{
        printf("no existe esa unidad \n");
        return 0;}

   char direcc[200];
   char direcc2[200];
   int i=0;
   for(i=0;i<200;i++){
       direcc2[i] ='\0';
   }
  //strcat(path, name);
  //strcat(path, ".")
  printf("PATH = %s\n",path);
  strcpy(direcc, path);

  for(i=0;i<200;i++){
      if(direcc[i]=='/'){
          direcc2[i]=direcc[i];
          char *aux= (char*)malloc(200);
          strcpy(aux,"mkdir ");
          strcat(aux,direcc2);
          printf("direccion: %s\n",aux);
          system(aux);
          free(aux);
      }
      direcc2[i]=direcc[i];
      if(direcc[i]=='\0'){
          break;
      }
  }

  for(i=0;i<200;i++){
      if(direcc2[i]=='\n'){
          direcc2[i]='\0';
      }
  }
/*
  char buffer[1024];
   i=0;
  for(i=0;i<1024;i++){
      buffer[i]='0';
  }
*/
  mbr inf;
  /* inf.fecha = time(0);
   inf.sign = ran;
   i=0;
   for(i=0;i<4;i++){
       inf.part[i].siz =0;
        inf.part[i].sizaux =0;
       inf.part[i].start =0;
       inf.part[i].fit = '0';
       inf.part[i].status = '0';
       inf.part[i].type = '0';
int ii=0;
for(ii=0;ii<8;ii++){
inf.part[i].extendida[ii].status='0';
inf.part[i].extendida[ii].fit='0';
inf.part[i].extendida[ii].next=0;
inf.part[i].extendida[ii].siz=0;
inf.part[i].extendida[ii].sizaux=0;
inf.part[i].extendida[ii].start=0;
}

   }
   int cantidad=atoi(siz);
   if(cantidad<1){
    printf("el tamaño es ilegal \n");
       return 0;
   }
*/
   FILE *disco;
   disco = fopen(path,"wb+");
   if(disco){
	   printf("Se creo el archivo \n");
   }else{
	   printf("Error al crear archivo");
   }
/*
   if(aux==1){
       inf.siz = cantidad*1048576;
        inf.siz = cantidad*1048576;
       cantidad= cantidad*1024;
   }else if(aux==2){
       inf.siz = cantidad*1024;
   }

   i=0;
   for(i=0;i<cantidad;i++){
       fwrite(&buffer,1024,1,disco);
   }

  fseek(disco,0,SEEK_SET);
   fwrite(&inf,sizof(mbr),1,disco);
   fclose(disco);
       printf("se creo el Disco\n");
*/
 //return 1;
//

}

void imprimirDatos(){

printf("DATOS:\n");
printf("  unit = %s\n",unit);
printf("  siz = %s\n",siz);
printf("  path = %s\n",path);
printf("  name = %s\n",name);
printf("  type = %s\n",type);
printf("  add = %s\n",add);
printf("  delete = %s\n",dele);
printf("  fit = %s\n",fit);
//printf("  unit = %s\n",unit);

}

void metodoPrueba(){

}

int Disco(char* path){
    FILE* disco;
    disco = fopen(path,"rb+");
    if(disco== NULL){
      printf("no existe el Disco\n");
      return 0;
    }else{
        if(strcmp(path,"/home/jorgec8")==0||strcmp(path,"/home/jorgec8/")==0){
        printf("ingrese una direccion valida\n");
        }else{
            char com[5];
            printf("\n Desea eliminar el disco [s/n]: \n");
           fgets(com,5,stdin);
           if(com[0]=='s' || com[0]=='S'){
        char* aux;
        aux = (char*)malloc(160);
        strcpy(aux,"rm ");
        strcat(aux, path);
        system(aux);
        printf("Disco Eliminado con Exito\n");
          }else{
          printf("No se elimino el disco\n");
           }
    }}
    return 1;
}

int Archivos(char* path){

    FILE* disco;
    char caracter[1000];
    disco = fopen(path,"r+");
    if(disco== NULL){
      printf("no existe el Archivo \n");
      return 0;
    }else{
        int ii=0;
               for( ii=0;ii<1000;ii++){
                       caracter[ii] = '\0';
               }
        int i=0;
        while (feof(disco) == 0) {
     caracter[i] = fgetc(disco);
     printf(&caracter[i]);
      caracter[i]= tolower(caracter[i]);
            if(caracter[i]=='\n'){
                char *trozo = NULL;
                caracter[i]='\0';
                trozo = strtok(caracter, " ");
                if(trozo!=NULL || trozo!=0x0){
         verificarComando(trozo,trozo);}
                for( ii=0;ii<1000;ii++){
                        caracter[ii] = '\0';
                }
              printf("\n");
                i=0;
            }else if(caracter[i]=='\\'){
                i++;
                caracter[i] = ' ';
                 printf(&caracter[i]);
                while(feof(disco) == 0 && fgetc(disco)!='\n'){
                    caracter[i] = fgetc(disco);
                    printf(&caracter[i]);
                     caracter[i]= tolower(caracter[i]);
                     i++;
                }
               caracter[i] = ' ';
                printf(&caracter[i]);
               i++;
            }else{
            i++;
            }
             }
    }
}

