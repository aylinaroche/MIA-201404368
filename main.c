#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int opcion=1;
int salida;

void verificarComando(char *a, char *com);

int main()
{
    printf("* * * * * * * * * * * * * COMANDOS . APP * * * * * * * * * * * * * \n");
    char com[1000];
    char com2[1000];
    char com3[1000];

   while(opcion!=0){

        printf("-> Comando: ");
        fgets(com,500,stdin);
        int i;
          for( i=0;i<1000;i++){
              if(com[i] == '\n'){
                  com[i] = '\0';
              }
          }
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
    printf("%s\n",com);
    if(strcasecmp(com,"mkdisk")==0 ||  strcasecmp(com,"Mkdisk")==0 || strcasecmp(com,"MKDISK")==0 || strcasecmp(com,"MKdisk")==0) {
    printf("mkdisk\n");
    com = strtok(NULL, " ");
    printf("A = %s\n", com);
    }
}


