#include <stdio.h>
#include <limits.h>

int main() {
    //creamos un puntero a un archivo
    FILE *fp;

    //abrimos el archivo
    fp = fopen("/tmp/proceso.log", "w+");

    //empezamos un ciclo infinito
    int i_max = INT_MAX/100;
    	while(1){
   	 //imprimir un mensaje para el usuario
   	 printf("Esperando...\n Presione cualquier tecla...");
   	 //esperar un enter por parte del usuario   	 
   	 getchar();
   	 ///////////////////////////////////////////////////////////////    
   	 //en este punto el proceso esta en Estado Bloqueado (S+ ó D)*//
   	 ///////////////////////////////////////////////////////////////                               	 

   	 //imprimir mensaje para el usuario
   	 printf(" Recalculando...\n\n");
   	 
   	 //empezamos un ciclo donde el proceso hace operaciones aritmeticas (usa la cpu)
   	 int contador=0;
   	 while(contador < i_max){
   		 //mientras no llego al entero maximo sigo sumando y usando procesador
   		 contador = contador + 1;
   		 ////////////////////////////////////////////////////////////    
   		 //en este punto el proceso esta en Estado de Ejecucion (R)//          	 
   		 ////////////////////////////////////////////////////////////    
   		 
   		 //escribo la variable contador en fp   		 
   		 fprintf(fp, "Linea...%d \n",contador);
   	 }
    }
    fclose(fp);
    return 0;
    //////////////////////////////////////////////////////////
    	// en este punto el proceso está en Estado Terminado (T)//
    //////////////////////////////////////////////////////////
 
}


/*
Compilar:
    gcc ejemplo.c -o ejemplo

Ejecutar:
    ./ejemplo

Ver Proceso con mas opciones y colores:
    htop

*/


