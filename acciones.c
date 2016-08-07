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
int boolCrearDisco=1;

void atributoDisco(char* coman){
//printf("atributo disco %s\n",coman);
        char* token1;
        char* com=coman;
        token1=strtok(com,":");
        //printf("T = %s\n",token1);
        if(token1==NULL){ }else
        if(strcasecmp(token1,"-size")==0 || strcasecmp(token1,"–size")==0){ //Verifica cada atributo
            token1=strtok(NULL,":");
            siz=token1;
        }else if(strcasecmp(token1,"+unit")==0){
            token1=strtok(NULL,":");
            unit=token1;
        }else if(strcasecmp(token1,"-path")==0 || strcasecmp(token1,"–path")==0){
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
        }else if(strcasecmp(token1,"-name")==0 || strcasecmp(token1,"–name")==0){
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
        }else if(strcasecmp(token1,"-id")==0 || strcasecmp(token1,"–id")==0){
            token1=strtok(NULL,":");
            id=token1;
}
}

void crearDisco(){
	boolCrearDisco = 1;
	 if(unit==NULL){
	          unit="m";
	      }
	 if(siz==NULL || path==NULL  || name==NULL){
	 printf("ERROR: Falta un atributo obligatorio.\n");
	 }else{
		 if(siz>9){
			int d =cDisco(siz,unit,path,name);
			if(d==0){
				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
			}
		 }else{
			printf("ERROR: El tamanio minimo para un disco es de 10Mb.\n");

		 }
	    }
}

int cDisco(char* siz, char* unit, char* path, char* name){
 int aux=0;
 //COMPROBAR POSIBLES ERRORES
    if(strcmp(unit,"M")==0 || strcmp(unit,"m")==0 ){
       aux =1;
    }  else if(strcmp(unit,"K")==0 || strcmp(unit,"k")==0 ){
        aux=2;
    }else{
        printf("ERROR: La unidad no existe. \n");
        boolCrearDisco =0;
        return 0;
    }
  /*  int s=0;
    char c[80];
    strcpy( c, siz);
    s = atoi(c);
    printf("S= %d\n",s);
    /*if(s<1){
    	printf("ERROR: El tamanio es menor a 0.\n");
    	boolCrearDisco =0;
    	return 0;
    }*/
    char* ext=NULL;
    ext=name;
    printf("N=%s\n",ext);
    int boolExt=0;

 //   ext = strtok(name,".");
  /*  printf("Ext=%s\n",ext);
    while(ext!=NULL){
    	ext = strtok(NULL,".");
    	if(strcmp(ext,"dsk")==0){
    		boolExt=1;
    	}
    }
    if(boolExt==0){
    	printf("ERROR: El nombre no tiene extension.\n");
    	boolCrearDisco =0;
    	return 0;
    }*/
/////////////////////////////////////////////////////////////////
    printf("-* %d\n",boolCrearDisco);
if(boolCrearDisco ==1){
	   char direcc[200];
	   char direcc2[200];
	   int i=0;
	   for(i=0;i<200;i++){
		   direcc2[i] ='\0';
	   }
	  strcat(path, name);
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
	  mbr inf;
	  inf.fecha = time(0);
	  inf.sign = 0;
	   i=0;
	   for(i=0;i<4;i++){
		   inf.part[i].size =0;
		   //inf.part[i].sizaux =0;
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
		//	inf.part[i].extendida[ii].sizaux=0;
			inf.part[i].extendida[ii].start=0;
			}
	   }
		  char buffer[1024];
		   i=0;
		  for(i=0;i<1024;i++){
			  buffer[i]='0';
		  }

	   int cantidad=atoi(siz);
	   if(cantidad<1){
		printf("el tamaño es ilegal \n");
		   return 0;
	   }

	   FILE *disco;
	   disco = fopen(path,"wb+");
	   if(disco){
		   printf("Se creo el archivo \n");
/*
		   //fseek(disco,0,SEEK_SET);
		   int tam=5*1024*1024;
		   for(int i=0;i<tam; i++){
		   fwrite("\0",1,1,disco);

		   }
		   fclose(disco);*/
	   }else{
		   printf("Error al crear archivo");
	   }

	   if(aux==1){
		   inf.size = cantidad*1048576;
		   inf.size = cantidad*1048576;
		   cantidad= cantidad*1024;
	   }else if(aux==2){
		   inf.size = cantidad*1024;
	   }

	   i=0;
	   for(i=0;i<cantidad;i++){
		   fwrite(&buffer,1024,1,disco);
	   }
	   printf("SIZE = %d\n",sizeof(mbr));
/*
	  fseek(disco,0,SEEK_SET);
	  fwrite(&inf,sizeof(mbr),1,disco);
	  */
	   metodoPrueba(disco);
	   fclose(disco);

	  printf("Se creo el Disco\n");

	 return 1;
	//
}
}

void iniciarParamDisco(){

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

void limpiarVariables(){
	siz=NULL;
	unit=NULL;
	path=NULL;
	type=NULL;
	fit=NULL;
	dele=NULL;
	name=NULL;
	add=NULL;
	id=NULL;
}

void metodoPrueba(FILE *f1){
	char buffer[1024];
	/* Para guardar el número de items leidos o si ha habido error */
	int leidos;
	/* Lectura e if para detectar posibles errores */
	leidos = fread (buffer, 1, 1024, f1);
	printf("Leidos=%d\n",leidos);

	printf("->> %s\n\n",buffer);
}

int eliminarDisco(){
    FILE* disco;
    disco = fopen(path,"wb+");
    if(disco== NULL){
      printf("ERROR:No existe el Disco.\n");
      return 0;
    }else{
        if(strcmp(path,"/home/aylin")==0||strcmp(path,"/home/aylin/")==0){
        printf("Ingrese una direccion valida\n");
        }else{
            char com[5];
            printf("\n > Desea eliminar el disco [s/n]: \n");
           fgets(com,5,stdin);
           if(com[0]=='s' || com[0]=='S'){
        char* aux;
        aux = (char*)malloc(160);
        strcpy(aux,"rm ");
        strcat(aux, path);
        system(aux);
        printf("Disco eliminado con exito\n");
          }else{
          printf("No se elimino el disco\n");
           }
    }}
    return 1;
}

void crearParticion(){
	 if(unit==NULL){
	   unit="k";
	 }
	 if(type==NULL){
	  type="p";
	 }
	 if(fit==NULL){
	  fit="w";
	 }
	    if(add==NULL && dele==NULL){
	    	if(path==NULL || siz ==NULL || name ==NULL){
	    		printf("ERROR: Falta un atributo obligatorio.\n");
	    	}else{
	    		CrearParticion(path,name,siz,unit,type,fit);
	    	}
	    }else if(dele==NULL){
	    	if(path==NULL || name ==NULL){
	    		printf("ERROR: Falta un atributo obligatorio.\n");
	       	}else{
	       		AgregarParticion(add,unit,path,name);
	       	}
	    } else if(add==NULL){
	    	if(path==NULL || name ==NULL){
	    		printf("ERROR: Falta un atributo obligatorio.\n");
	      	}else{
	      		EliminarParticion(dele,path,name);
	      	}
	    }else{
	    	if(path==NULL || name ==NULL){
	    		printf("ERROR: Falta un atributo obligatorio.\n");
	    	}else{
	    		AgregarParticion(add,unit,path,name);
	    	}
	    }
/*
	int d =cDisco(siz,unit,path,name);
	if(d==0){
		printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
	}
*/
}

int CrearParticion(char* path,char* name,char* siz,char* unit,char* type,char* fit){
    int tam= atoi(siz);
    int libre=0;
    int par=0;

    FILE* disco;
    disco = fopen(path,"rb+");
    if(disco== NULL){
        printf("no existe el disco");
        return 0;
    }
  mbr lec;
  fseek(disco,0,SEEK_SET);
  fread(&lec,sizeof(mbr),1,disco);
  int tipo=0;
  char fi[5];

  if(strcasecmp(type,"P")==0 || strcasecmp(type,"p")==0){
	  tipo=1;
  }else if(strcasecmp(type,"L")==0 || strcasecmp(type,"l")==0) {
	  tipo=2;
  }else if(strcasecmp(type,"E")==0 || strcasecmp(type,"e")==0) {
	  tipo=3;
  }else{
      printf("ERROR: Tipo de particion incorrecta.\n");
      return 0;
  }

  if(strcasecmp(fit,"B")==0 || strcasecmp(fit,"W")==0 || strcasecmp(fit,"F")==0){
      strcpy(fi,fit);
  }else{
      printf("ERROR: No existe el ajuste indicado.\n");
      return 0;
  }
   int i=0;
   for(i=0;i<4;i++){
           if(strcasecmp(name,lec.part[i].name)==0){
               printf("ya existe el nombre");
               return 0;
           }
       }
  if(tipo==1){
      for(i=0;i<4;i++){
          if(strcasecmp(name,lec.part[i].name)==0){
              printf("ya existe el nombre");
              return 0;
          }
      }
  }else if(tipo==3){
      for(i=0;i<4;i++){
          char p;
          p=lec.part[i].type;
          if(lec.part[i].type == 'E' || lec.part[i].type == 'e' || strcasecmp(name,lec.part[i].name)==0){
              printf("ya existe una particion extendida");
              return 0;
          }
  }
  }else{
      for(i=0;i<4;i++){
          char pa= lec.part[i].type;
          if(lec.part[i].type == 'E' || lec.part[i].type == 'e' ){
              int ii=0;
              for(ii=0; ii<8; ii++){
                  if(strcasecmp(name,lec.part[i].extendida[ii].name)==0){
                     printf("ya existe el nombre");
                     return 0;
                  }
              }break;
         }
      }
    if(i==4){
        printf("no existe una particion extendida");
        return 0;
    }
  }

}

int AgregarParticion(char* add,char* unit,char* path,char* name){

}

int EliminarParticion(char* dele,char* path,char* name){

}
