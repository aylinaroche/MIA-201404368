#include <stdio.h>
#include <stdlib.h>
#include "string.h"
//#include "comandos.h"
//#include "acciones.h"

int opcion=1;
int salida;
char* size=NULL;
char* unit=NULL;
char* path=NULL;
char* type=NULL;
char* fit=NULL;
char* del=NULL;
char* name=NULL;
char* add=NULL;
char* id=NULL;
/*char* ruta=NULL;
/*char* p=NULL;
char* cont=NULL;
char* dest=NULL;
char* iddest=NULL;*/
char prueba;

void verificarComando(char *a, char *com);
void crearDisco(char* comando);
int cDisco(char* size, char* unit, char*path, int ran);


int main(){
    printf("* * * * * * * * * * * * * COMANDOS . APP * * * * * * * * * * * * * \n");
    char com[1000];
    char com2[1000];
    char com3[1000];

   while(opcion!=0){

        printf("-> Comando: ");
        fgets(com,500,stdin);
        int i;
     /*     for( i=0;i<1000;i++){
              if(com[i] == '\n'){
                  com[i] = '\0';
              }
          }
          */
        //printf("TT = %s\n",com);
        strcpy(com2, com);
        char *trozo = NULL;
        trozo = strtok( com, " ");
        if(trozo!=NULL){
               if(strcmp(trozo,"salida")==0 || strcmp(trozo,"SALIDA")==0 || strcmp(trozo,"Salida")==0 ){
                    salida=1;
                    break;
                }
        }
      char *atr;
       if(trozo!=NULL){
      //  printf("TT = %s\n",com2);
      atr = com2;

       verificarComando(trozo, atr);
        }
    }
    return 0;
}

void verificarComando(char *com, char *atributos){
     char* inst=NULL;
     char* inst1=NULL;
     //string datos[5];
    if(strcasecmp(com,"mkdisk")==0 ||  strcasecmp(com,"Mkdisk")==0 || strcasecmp(com,"MKDISK")==0 || strcasecmp(com,"MKdisk")==0) {
    printf("mkdisk\n");

    while(atributos!=NULL){
    atributos = strtok(NULL, " ");
    printf("A = %s\n", atributos);

    }
    }else  if(strcasecmp(inst,"rmdisk")==0 || strcasecmp(inst,"Rmdisk")==0 || strcasecmp(inst,"RMdisk")==0 || strcasecmp(inst,"RMDISK")==0 ){
    }
}

void crearDisco(char* comando){



int cDisco(char* size, char* unit, char*path, int name){
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
  strcpy(direcc, path);

  for(i=0;i<200;i++){
      if(direcc[i]=='/'){
          direcc2[i]=direcc[i];
          char *aux= (char*)malloc(150);
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

  char buffer[1024];
   i=0;
  for(i=0;i<1024;i++){
      buffer[i]='0';
  }
  /*
   mbr inf;
   inf.fecha = time(0);
   inf.sign = ran;
   i=0;
   for(i=0;i<4;i++){
       inf.part[i].size =0;
        inf.part[i].sizeaux =0;
       inf.part[i].start =0;
       inf.part[i].fit = '0';
       inf.part[i].status = '0';
       inf.part[i].type = '0';
int ii=0;
for(ii=0;ii<8;ii++){
inf.part[i].extendida[ii].status='0';
inf.part[i].extendida[ii].fit='0';
inf.part[i].extendida[ii].next=0;
inf.part[i].extendida[ii].size=0;
inf.part[i].extendida[ii].sizeaux=0;
inf.part[i].extendida[ii].start=0;
}
*/
   }
   int cantidad=atoi(size);
   if(cantidad<1){
    printf("el tamaño es ilegal \n");
       return 0;
   }

   FILE *disco;
   disco = fopen(path,"wb+");
/*
   if(aux==1){
       inf.size = cantidad*1048576;
        inf.size = cantidad*1048576;
       cantidad= cantidad*1024;
   }else if(aux==2){
       inf.size = cantidad*1024;
   }
*/
   i=0;
   for(i=0;i<cantidad;i++){
       fwrite(&buffer,1024,1,disco);
   }

  fseek(disco,0,SEEK_SET);
   fwrite(&inf,sizeof(mbr),1,disco);
   fclose(disco);
       printf("se creo el Disco\n");

 return 1;
}



        char* token1;
        char* com=comando;
        token1=strtok(com,":");
        printf("T = %s\n",token1);
        if(token1==NULL){ }else
        if(strcasecmp(token1,"-size")==0){ //Verifica cada atributo
            token1=strtok(NULL,":");
            size=token1;
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
            del=token1;
        }else if(strcasecmp(token1,"-name")==0){
            token1=strtok(NULL,":");
            name=token1;
        }else if(strcasecmp(token1,"+add")==0){
            token1=strtok(NULL,":");
            add=token1;
        }else if(strcasecmp(token1,"-id")==0){
            token1=strtok(NULL,":");
            id=token1;
}
}
