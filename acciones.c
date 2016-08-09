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
	   if(cantidad<10){
		printf("ERROR: El tamaño es incorrecto. Tiene que ser mayor a 10 Mb.\n");
		   return 0;
	   }

	   FILE *disco;
	   disco = fopen(path,"wb+");
	   if(disco){
		   printf("Se creo el archivo correctamente.\n");
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
//	   metodoPrueba(disco);
	   fclose(disco);

	  printf("Se creo el Disco\n");

	 return 1;
	//
}
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
	/* structDiscotura e if para detectar posibles errores */
	leidos = fread (buffer, 1, 1024, f1);
	printf("Leidos=%d\n",leidos);

	printf("->> %s\n\n",buffer);
}

int eliminarDisco(){
    FILE* disco;
    disco = fopen(path,"wb+");
    if(disco== NULL){
      printf("ERROR: No existe el Disco.\n");
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

void adminParticion(){
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
	    		int d =	crearParticion(path,name,siz,unit,type,fit);
	    		if(d==0){
	    				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
	    			}
	    	}
	    }else if(dele==NULL){
	    	if(path==NULL || name ==NULL){
	    		printf("ERROR: Falta un atributo obligatorio.\n");
	       	}else{
	       		int d =agregarParticion(add,unit,path,name);
	       		if(d==0){
	       				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
	       			}
	       	}
	    } else if(add==NULL){
	    	if(path==NULL || name ==NULL){
	    		printf("ERROR: Falta un atributo obligatorio.\n");
	      	}else{
	      		int d =eliminarParticion(dele,path,name);
	      		if(d==0){
	      				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
	      			}
	      	}
	    }else{
	    	if(path==NULL || name ==NULL){
	    		printf("ERROR: Falta un atributo obligatorio.\n");
	    	}else{
	    		int d =agregarParticion(add,unit,path,name);
	    		if(d==0){
	    				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
	    			}
	    	}
	    }
}

int crearParticion(char* path,char* name,char* siz,char* unit,char* type,char* fit){
    int tam= atoi(siz);
    int libre=0;
    int particion=0;

    FILE* archivo;
    archivo = fopen(path,"rb+");
    if(archivo== NULL){
        printf("ERROR: No existe el disco.\n");
        return 0;
    }
  mbr structDisco;
  fseek(archivo,0,SEEK_SET);
  fread(&structDisco,sizeof(mbr),1,archivo);
  int tipo=0;
  char fi[5];
//VERIFICAR EL TIPO
  if(strcasecmp(type,"P")==0 || strcasecmp(type,"p")==0){ //primaria
	  tipo=1;
  }else if(strcasecmp(type,"L")==0 || strcasecmp(type,"l")==0) { //logica
	  tipo=2;
  }else if(strcasecmp(type,"E")==0 || strcasecmp(type,"e")==0) { //extendida
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
           if(strcasecmp(name,structDisco.part[i].name)==0){
               printf("ERROR: Ya existe el nombre.\n");
               return 0;
           }
       }
   //VERIFICAR NOMBRE REPETIDO
  if(tipo==1){
      for(i=0;i<4;i++){
          if(strcasecmp(name,structDisco.part[i].name)==0){
              printf("ERROR: Ya existe el nombre.\n");
              return 0;
          }
      }
  }else if(tipo==3){
      for(i=0;i<4;i++){
          char p;
          p=structDisco.part[i].type;
          if(structDisco.part[i].type == 'E' || structDisco.part[i].type == 'e' || strcasecmp(name,structDisco.part[i].name)==0){
              printf("ERROR: Ya existe una particion extendida.\n");
              return 0;
          }
  }
  }else{
      for(i=0;i<4;i++){
          if(structDisco.part[i].type == 'E' || structDisco.part[i].type == 'e' ){
              int ii=0;
              for(ii=0; ii<8; ii++){
                  if(strcasecmp(name,structDisco.part[i].extendida[ii].name)==0){
                     printf("ERROR: Ya existe el nombre.\n");
                     return 0;
                  }
              }break;
         }
      }
    if(i==4){
        printf("ERROR: No existe una particion extendida.\n");
        return 0;
    }
  }
  //VERIFICAR EL TAMANIO DE LA PARTICION Y LA CANTIDAD DE PARTICIONES
  int contParticion=0;
  for(i=0;i<4;i++){
      if(structDisco.part[i].status=='1'){
    	  particion = particion + structDisco.part[i].size;
          contParticion++;
      }
  }
  if(contParticion==4){
      printf("ERROR: Ya existen 4 particiones.\n");
      return 0;
  }
  //VERIFICAR LA UNIDAD
  int bytes=0;
  if(strcasecmp(unit,"k")==0||strcasecmp(unit,"K")==0){ //Kilobyte -> 1024 bytes
      bytes = tam*1024;
  }else if(strcasecmp(unit,"m")==0||strcasecmp(unit,"M")==0){ //megabyte -> 1024 Kb
      bytes = tam*1024*1024;
  }else if(strcasecmp(unit,"b")==0||strcasecmp(unit,"B")==0) { //byte -> 8bits
     bytes=tam;
  }else{
      printf("ERROR: La unidad no existe.\n");
      return 0;
  }
//VERIFICAR TAMANIO DE PARTICION
  libre = structDisco.size-particion;

  int espacio=0;

if(tipo==1 || tipo==3){ // Si la particion es primaria o extendida
       if(libre < bytes){
           printf("ERROR: No hay tamaño disponible.\n");
           return 0;
       }
 //ASINGAR TIPO, AJUSTE, TAMANIO
  for(i=0;i<4;i++){
      if(structDisco.part[i].status == '0'){
          if(structDisco.part[i].size ==0 || bytes<structDisco.part[i].size){
          if(fi[0]=='F' ||fi[0]=='f'){
          structDisco.part[i].fit = 'f';
          }else   if(fi[0]=='B' ||fi[0]=='b'){
              structDisco.part[i].fit = 'b';
          }else{
               structDisco.part[i].fit = 'w';
          }
              strcpy(structDisco.part[i].name,name);
              structDisco.part[i].size = bytes;
              structDisco.part[i].sizeAux = bytes;
              if(i==0){
            	  printf("Size of=%d\n",sizeof(mbr));
                  structDisco.part[i].start = sizeof(mbr)+1;
                  espacio =1;
              }else{
                  structDisco.part[i].start = structDisco.part[i-1].start+structDisco.part[i-1].size;
                  espacio =1;
              }
              structDisco.part[i].status ='1';

  if(strcasecmp(type,"E")==0||strcasecmp(type,"e")==0){
   structDisco.part[i].type ='e';
  }else{
      structDisco.part[i].type ='p';
  }
              espacio =1;
              break;
          }
      }
  }
   }else{ //Si la particion es logica
       for(i=0;i<4;i++){
           if(structDisco.part[i].type == 'E' || structDisco.part[i].type == 'e' ){ //Si existe una extendida antes
              int ii=0;
               for(ii=0;ii<8;ii++){
                   int j=0;
                   int espa=0; //suma de todas las particiones extendidas
                for(j=0;j<8;j++){
                	espa= espa + structDisco.part[i].extendida[j].size;
                }
               espa= structDisco.part[i].sizeAux-espa;
			   if(espa < bytes){
				   printf("ERROR: No hay tamaño disponible.\n");
				   return 0;
			   }

		    if(structDisco.part[i].extendida[ii].status == '0'){
			   if(structDisco.part[i].extendida[ii].size ==0 || bytes<structDisco.part[i].extendida[ii].size){

				   if(fi[0]=='F' ||fi[0]=='f'){ //Primer ajuste
				   structDisco.part[i].extendida[ii].fit = 'f';
				   }else   if(fi[0]=='B' ||fi[0]=='b'){ //Mejor Ajuste
					   structDisco.part[i].extendida[ii].fit = 'b';
				   }else{
						structDisco.part[i].extendida[ii].fit = 'w'; //Peor ajuste
				   }
				   strcpy(structDisco.part[i].extendida[ii].name,name);
				   structDisco.part[i].extendida[ii].size = bytes;
				   structDisco.part[i].extendida[ii].sizeAux = bytes;

				   if(ii==0){ //
					   structDisco.part[i].extendida[ii].start = structDisco.part[i].start+1;
					   structDisco.part[i].extendida[ii].next = -1;
					   espacio =1;
				   }else{
					   structDisco.part[i].extendida[ii].start = structDisco.part[i].extendida[ii-1].start+structDisco.part[i].extendida[ii-1].size;
					   structDisco.part[i].extendida[ii-1].next= structDisco.part[i].extendida[ii-1].start+structDisco.part[i].extendida[ii-1].size;
					   espacio =1;
				   }
				   structDisco.part[i].extendida[ii].status ='1';
				   espacio =1;
				   break;
			   }
		   }
              }
           }
       }

   }

if (espacio==0){
     printf("ERROR: No existe espacio suficiente.\n");
    return 0;
}
fseek(archivo,0,SEEK_SET);
printf("Size2 = %d\n",sizeof(mbr));
fwrite(&structDisco,sizeof(mbr),1,archivo);
fclose(archivo);
    printf("-> Se creo la particion correctamente.\n");
return 1;


}

int agregarParticion(char* add,char* unit,char* path,char* name){
	int tam= atoi(add);
	int libre=0;
	int par=0;

//VERIFICA SI EL DISCO EXISTE
	FILE* archivo;
	archivo = fopen(path,"rb+");
	if(archivo== NULL){
	   printf("ERROR: No existe el disco.\n");
	   return 0;
	}
	    mbr structDisco;
	    fseek(archivo,0,SEEK_SET);
	    fread(&structDisco,sizeof(mbr),1,archivo);

//VERIFICA LA UNIDAD DEL DISCO
	    int bytes=0;
	    if(strcasecmp(unit,"k")==0||strcasecmp(unit,"K")==0){
	        bytes = tam*1024;
	    }else if(strcasecmp(unit,"m")==0||strcasecmp(unit,"M")==0){
	        bytes = tam*1024*1024;
	    }else if(strcasecmp(unit,"b")==0||strcasecmp(unit,"B")==0) {
	       bytes=tam;
	    }else{
	        printf("ERROR: Unidad incorrecta.\n");
	        return 0;
	    }
	int i=0;
	int a=0;
	int ii=0;
//VERIFICA SI EL NOMBRE EXISTE
	for(i=0;i<4;i++){
	        if(strcasecmp(name, structDisco.part[i].name)==0){
	            break;
	        }
	        for(ii=0; ii<8; ii++){
	            if(strcasecmp(name, structDisco.part[i].extendida[ii].name)==0){
	                a=1;
	                break;
	            }
	        }
	        if(a>0){
	            break;
	        }
	    }
   if(i==4 && a==0){
      printf("ERROR: El nombre indicado no existe.\n");
      return 0;
   }

//VERIFICAR SI EL ESPACIO ES SUFICIENTE
   if(a>0){
    if(bytes>0){
		 if(ii<7){
			 printf("ii = %d\n",ii);
			 if(structDisco.part[i].extendida[ii+1].start!=0){ //
			   int sig = structDisco.part[i].extendida[ii].start + structDisco.part[i].extendida[ii].sizeAux ;
			   int ant = structDisco.part[i].extendida[ii+1].start;

			   int resta= ant-sig;

			   if(resta<bytes){
				   printf("ERROR: No hay espacio.\n");
				   return 0;
			   }
			   structDisco.part[i].extendida[ii].sizeAux = structDisco.part[i].extendida[ii].sizeAux + bytes;

			   if(structDisco.part[i].extendida[ii].sizeAux >  structDisco.part[i].extendida[ii].size){
				   structDisco.part[i].extendida[ii].size = structDisco.part[i].extendida[ii].size + (structDisco.part[i].extendida[ii].sizeAux- structDisco.part[i].extendida[ii].size);
			   }

			   }else{
				  int j=0;
				  int sum=0;
					for(j=0; j<8; j++){
						sum = sum +structDisco.part[i].extendida[j].size;
					}
					int resta= structDisco.part[i].sizeAux-sum;
					if(resta<bytes){
						printf("ERROR: No hay espacio.\n");
						return 0;
					}
					structDisco.part[i].extendida[ii].sizeAux = structDisco.part[i].extendida[ii].sizeAux+bytes;
					if(structDisco.part[i].extendida[ii].sizeAux> structDisco.part[i].extendida[ii].size){
						structDisco.part[i].extendida[ii].size= structDisco.part[i].extendida[ii].size+(structDisco.part[i].extendida[ii].sizeAux- structDisco.part[i].extendida[ii].size);
					}
			  }
		 }else{
			 int j=0;
			 int sum=0;
		   for(j=0; j<8; j++){
			   sum=sum +structDisco.part[i].extendida[j].size;
		   }
		   int resta= structDisco.part[i].sizeAux-sum;
		   if(resta<bytes){
			   printf("ERROR: No hay espacio.\n");
			   return 0;
		   }
		   structDisco.part[i].extendida[ii].sizeAux = structDisco.part[i].extendida[ii].sizeAux + bytes;
		   if(structDisco.part[i].extendida[ii].sizeAux > structDisco.part[i].extendida[ii].size){
			   structDisco.part[i].extendida[ii].size = structDisco.part[i].extendida[ii].size+(structDisco.part[i].extendida[ii].sizeAux- structDisco.part[i].extendida[ii].size);
		   }

		 }
    }else{
       if(ii<7){
			if(structDisco.part[i].extendida[ii+1].start!=0){
				int resta= bytes+ structDisco.part[i].extendida[ii].sizeAux;
				if(resta>0){
					structDisco.part[i].extendida[ii].sizeAux=resta;
				}else{
					printf("ERROR: No hay espacio para borrar.\n");
					return 0;
				}
			}else{
				int resta= bytes+ structDisco.part[i].extendida[ii].sizeAux;
				if(resta>0){
					structDisco.part[i].extendida[ii].sizeAux=resta;
				structDisco.part[i].extendida[ii].size=resta;
				}else{
					printf("ERROR: No hay espacio.\n");
					return 0;
				}
			}
       }else{
           int resta=bytes+ structDisco.part[i].extendida[ii].sizeAux;
           if(resta>0){
        	   structDisco.part[i].extendida[ii].sizeAux=resta;
        	   structDisco.part[i].extendida[ii].size=resta;
           }else{
        	   printf("ERROR: No hay espacio.\n");
        	   return 0;
           }
       }
     }
    }
	fseek(archivo,0,SEEK_SET);
	fwrite(&structDisco,sizeof(mbr),1,archivo);
	fclose(archivo);
	printf("-> Se realizo la modificacion correctamente.\n");
	return 1;
   }

int eliminarParticion(char* dele,char* path,char* name){

//VERIFICA SI EXISTE EL DISCO
	FILE* archivo;
	archivo = fopen(path,"rb+");
	    if(archivo== NULL){
	         printf("ERROR: No existe el disco.\n");
	        return 0;
	    }
	    mbr structDisco;
	    fseek(archivo,0,SEEK_SET);
	    fread(&structDisco,sizeof(mbr),1,archivo);

	    int existe=0;
	    int tipoDelete=0;
	    int i=0;
	    int ii=0;

//VERIFICA SI EL NOMBRE EXISTE
	    for(i=0;i<4;i++){
	        if(strcasecmp(structDisco.part[i].name,name)==0){
	            break;
	        }
	        for(ii=0;ii<8;ii++){
	            if(strcasecmp(structDisco.part[i].extendida[ii].name,name)==0){
	            	existe=1;
	                break;
	            }
	        }
	            if(existe==1){
	                break;
	            }
	    }
	    if(i==4 && existe==0){
	        printf("ERROR: No existe el nombre.\n");
	       return 0;
	    }
	if(strcasecmp(dele,"full")==0){
		tipoDelete=1;
	}else if(strcasecmp(dele,"fast")==0){
		tipoDelete=2;
	}else{
	    printf("ERROR: Tipo de Delete incorrecto.\n");
	   return 0;
	}

	fseek(archivo,0,SEEK_SET);
	fwrite(&structDisco,sizeof(mbr),1,archivo);
	fclose(archivo);
	printf("-> Se elimino correctamente.\n");
	return 1;
	return 1;
}

