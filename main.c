#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "acciones.h"
#include "estructuras.h"
#include "comandos.h"

int opcion=1;
int salida;
char* auxAtributos;

int main(){
    printf("* * * * * * * * * * * * * COMANDOS . APP * * * * * * * * * * * * * \n");
    char com[1000];
    char com2[1000];
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
        strcpy(com2, com);
        char *trozo = NULL;
        trozo = strtok( com, " ");
        if(trozo!=NULL){
               if(strcmp(trozo,"salida")==0 || strcmp(trozo,"SALIDA")==0 || strcmp(trozo,"Salida")==0 ){
                    break;
                }
        }
      char *atr;
       if(trozo!=NULL){
      atr = com2;

       verificarComando(trozo, atr);
        }
    }
    return 0;
}


