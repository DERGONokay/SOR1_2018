#include <stdio.h>
#include <stdlib.h>    
#include <unistd.h>         // para castear de puntero a entero
#include <string.h>
#include <time.h> 
#include <pthread.h>
#include <semaphore.h>

///////////////////////////////////////////////////////////////////////////
// Semaforos
///////////////////////////////////////////////////////////////////////////
sem_t SEM_GRUPOS, SEM_OCTAVOS, SEM_CUARTOS, SEM_SEMI;

///////////////////////////////////////////////////////////////////////////
// Info de grupos
///////////////////////////////////////////////////////////////////////////
#define CANTIDAD_GRUPOS 8
char* grupos_labels[] = {"A", "B", "C", "D", "E", "F", "G", "H"};


//cada grupo tiene
//4 filas, una por cada pais
//y 8 columnas:          
//columna 1 = Pts(Puntos)     
//columna 2 = PJ(Partidos Jugados)
//columna 3 = PG(Partidos Ganados)
//columna 4 = PE(Partidos Empatados)
//columna 5 = PP(Partidos Perdidos)
//columna 6 = GF(Goles a Favor)
//columna 7 = GC(Goles en contra)
//columna 8 = Dif(Diferencia de Gol)
char* grupo_A[] = {"Rusia", "Arabia Saudita", "Egipto", "Uruguay"};
int grupo_A_favoritos[] = {1, 0, 0, 1};
int grupo_A_puntos[4][8] = { { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} };


char* grupo_B[] = {"Portugal", "España", "Marruecos", "Irán"};
int grupo_B_favoritos[] = {1, 1, 0, 0};
int grupo_B_puntos[4][8] = { { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} };


char* grupo_C[] = {"Francia", "Australia", "Peru", "Dinamarca"};
int grupo_C_favoritos[] = {1, 0, 0, 0};
int grupo_C_puntos[4][8] = { { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} };


char* grupo_D[] = {"Argentina", "Islandia", "Croacia", "Nigeria"};
int grupo_D_favoritos[] = {1, 0, 0, 0};
int grupo_D_puntos[4][8] = { { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} };


char* grupo_E[] = {"Brasil","Suiza", "Costa Rica", "Serbia"};
int grupo_E_favoritos[] = {1, 0, 0, 0};
int grupo_E_puntos[4][8] = { { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} };


char* grupo_F[] = {"Alemania", "Mexico", "Suecia", "Korea del Sur"};
int grupo_F_favoritos[] = {1, 1, 0, 0};
int grupo_F_puntos[4][8] = { { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} };


char* grupo_G[] = {"Belgica", "Panama", "Tunez", "Inglaterra"};
int grupo_G_favoritos[] = {0, 0, 0, 1};
int grupo_G_puntos[4][8] = { { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} };


char* grupo_H[] = {"Polonia", "Senegal", "Colombia", "Japón"};
int grupo_H_favoritos[] = {0, 0, 1, 0};
int grupo_H_puntos[4][8] = { { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} ,
                             { 0,0,0,0,0,0,0,0} };


void print_tabla_grupo(char* grupo_data[], int tabla[][8]){
  int i, j;
  for (i = 0; i < 4; i++){
        printf ("%s ,",grupo_data[i]);
   
        for (j = 0; j < 8; j++){
          printf ("%d ,",tabla[i][j]);
        }
        printf("\n");
  }
}




///////////////////////////////////////////////////////////////////////////
// End Info de grupos
///////////////////////////////////////////////////////////////////////////


void llenar_tabla(int tabla[][8], int equipo_1, int equipo_2, int goles_equipo_1, int goles_equipo_2)
{
  //columna 2 = PJ(Partidos Jugados)
  tabla[equipo_1][1] = tabla[equipo_1][1]+1;
  tabla[equipo_2][1] = tabla[equipo_2][1]+1;


  if(goles_equipo_1 > goles_equipo_2){
        //gano el equipo 1
        //columna 1 = Pts(Puntos)
        tabla[equipo_1][0] = tabla[equipo_1][0]+3;          
        //columna 3 = PG(Partidos Ganados)
        tabla[equipo_1][2] = tabla[equipo_1][2]+1;
        //columna 5 = PP(Partidos Perdidos)
        tabla[equipo_2][4] = tabla[equipo_2][4]+1;


  }else if (goles_equipo_1 == goles_equipo_2){
        //empataron
        tabla[equipo_1][0] = tabla[equipo_1][0]+1;          
        tabla[equipo_2][0] = tabla[equipo_2][0]+1;
        //columna 4 = PE(Partidos Empatados)
        tabla[equipo_1][3] = tabla[equipo_1][3]+1;
        tabla[equipo_2][3] = tabla[equipo_2][3]+1;          
  }else{
        //gano el equipo 2
        tabla[equipo_2][0] = tabla[equipo_2][0]+3;          
        tabla[equipo_2][2] = tabla[equipo_2][2]+1;
        //columna 5 = PP(Partidos Perdidos)
        tabla[equipo_1][4] = tabla[equipo_1][4]+1;
  }


  //columna 6 = GF(Goles a Favor)
  tabla[equipo_1][5] = tabla[equipo_1][5]+goles_equipo_1;
  tabla[equipo_2][5] = tabla[equipo_2][5]+goles_equipo_2;


  //columna 7 = GC(Goles en contra)
  tabla[equipo_1][6] = tabla[equipo_1][6]+goles_equipo_2;
  tabla[equipo_2][6] = tabla[equipo_2][6]+goles_equipo_1;


  //columna 8 = Dif(Diferencia de Gol)
  tabla[equipo_1][7] = 0; //TODO:revisar
  tabla[equipo_2][7] = 0; //TODO:revisar
}


void jugar_partido (int equipo_1, int equipo_2, int instancia, char* grupo_data[] , int grupo_puntos[][8], int grupo_favoritos[] ){
  char * nombre_equipo_1;
  char * nombre_equipo_2;
  int goles_equipo_1;
  int goles_equipo_2;


  nombre_equipo_1=grupo_data[equipo_1];
  nombre_equipo_2=grupo_data[equipo_2];
 
  /* random int entre 0 y 10 */
  int rango_gol_equipo1 = 1;
  int rango_gol_equipo2 = 1;
  int base=0;
  if(grupo_favoritos[equipo_1]){
        rango_gol_equipo1 = 7;
        base=3;
  }


  if(grupo_favoritos[equipo_2]){
        rango_gol_equipo2 = 7;
        base=3;
  }


  goles_equipo_1 = (rand() % rango_gol_equipo1)+base;
  goles_equipo_2 = (rand() % rango_gol_equipo2)+base;


  printf("Resultado %s %d -- %s %d \n", nombre_equipo_1, goles_equipo_1, nombre_equipo_2, goles_equipo_2);


  switch(instancia) {
  case 0 :
        //es instancia de grupos
        llenar_tabla(grupo_puntos, equipo_1, equipo_2, goles_equipo_1, goles_equipo_2);
        break;
  default :
        printf("Invalid instancia\n" );
  }
}


void* jugar_grupo (void* indice)
{
  //Casteo el apuntador a un int
  int* pointer = indice;
  int grupo = *pointer;
  free(indice);
  switch(grupo) 
  {
  case 0 :
        //jugar los 6 partidos del grupo
        jugar_partido(0,1, 0, grupo_A, grupo_A_puntos, grupo_A_favoritos);
        jugar_partido(0,2, 0, grupo_A, grupo_A_puntos, grupo_A_favoritos);
        jugar_partido(2,1, 0, grupo_A, grupo_A_puntos, grupo_A_favoritos);
        jugar_partido(2,3, 0, grupo_A, grupo_A_puntos, grupo_A_favoritos);
        jugar_partido(3,1, 0, grupo_A, grupo_A_puntos, grupo_A_favoritos);
        jugar_partido(3,0, 0, grupo_A, grupo_A_puntos, grupo_A_favoritos);
        sem_post(&SEM_GRUPOS);
        pthread_exit(NULL);
        break;
  case 1 :
        //jugar los 6 partidos del grupo
        jugar_partido(0,1, 0, grupo_B, grupo_B_puntos, grupo_B_favoritos);
        jugar_partido(0,2, 0, grupo_B, grupo_B_puntos, grupo_B_favoritos);
        jugar_partido(2,1, 0, grupo_B, grupo_B_puntos, grupo_B_favoritos);
        jugar_partido(2,3, 0, grupo_B, grupo_B_puntos, grupo_B_favoritos);
        jugar_partido(3,1, 0, grupo_B, grupo_B_puntos, grupo_B_favoritos);
        jugar_partido(3,0, 0, grupo_B, grupo_B_puntos, grupo_B_favoritos);
        sem_post(&SEM_GRUPOS);
        pthread_exit(NULL);
        break;
  case 2 :
        //jugar los 6 partidos del grupo
        jugar_partido(0,1, 0, grupo_C, grupo_C_puntos, grupo_C_favoritos);
        jugar_partido(0,2, 0, grupo_C, grupo_C_puntos, grupo_C_favoritos);
        jugar_partido(2,1, 0, grupo_C, grupo_C_puntos, grupo_C_favoritos);
        jugar_partido(2,3, 0, grupo_C, grupo_C_puntos, grupo_C_favoritos);
        jugar_partido(3,1, 0, grupo_C, grupo_C_puntos, grupo_C_favoritos);
        jugar_partido(3,0, 0, grupo_C, grupo_C_puntos, grupo_C_favoritos);
        sem_post(&SEM_GRUPOS);
        pthread_exit(NULL);
        break;
  case 3 :
        //jugar los 6 partidos del grupo
        jugar_partido(0,1, 0, grupo_D, grupo_D_puntos, grupo_D_favoritos);
        jugar_partido(0,2, 0, grupo_D, grupo_D_puntos, grupo_D_favoritos);
        jugar_partido(2,1, 0, grupo_D, grupo_D_puntos, grupo_D_favoritos);
        jugar_partido(2,3, 0, grupo_D, grupo_D_puntos, grupo_D_favoritos);
        jugar_partido(3,1, 0, grupo_D, grupo_D_puntos, grupo_D_favoritos);
        jugar_partido(3,0, 0, grupo_D, grupo_D_puntos, grupo_D_favoritos);
        sem_post(&SEM_GRUPOS);
        pthread_exit(NULL);
        break;
  case 4 :
        //jugar los 6 partidos del grupo
        jugar_partido(0,1, 0, grupo_E, grupo_E_puntos, grupo_E_favoritos);
        jugar_partido(0,2, 0, grupo_E, grupo_E_puntos, grupo_E_favoritos);
        jugar_partido(2,1, 0, grupo_E, grupo_E_puntos, grupo_E_favoritos);
        jugar_partido(2,3, 0, grupo_E, grupo_E_puntos, grupo_E_favoritos);
        jugar_partido(3,1, 0, grupo_E, grupo_E_puntos, grupo_E_favoritos);
        jugar_partido(3,0, 0, grupo_E, grupo_E_puntos, grupo_E_favoritos);
        sem_post(&SEM_GRUPOS);
        pthread_exit(NULL);
        break;
  case 5 :
        //jugar los 6 partidos del grupo
        jugar_partido(0,1, 0, grupo_F, grupo_F_puntos, grupo_F_favoritos);
        jugar_partido(0,2, 0, grupo_F, grupo_F_puntos, grupo_F_favoritos);
        jugar_partido(2,1, 0, grupo_F, grupo_F_puntos, grupo_F_favoritos);
        jugar_partido(2,3, 0, grupo_F, grupo_F_puntos, grupo_F_favoritos);
        jugar_partido(3,1, 0, grupo_F, grupo_F_puntos, grupo_F_favoritos);
        jugar_partido(3,0, 0, grupo_F, grupo_F_puntos, grupo_F_favoritos);
        sem_post(&SEM_GRUPOS);
        pthread_exit(NULL);
        break;
  case 6 :
        //jugar los 6 partidos del grupo
        jugar_partido(0,1, 0, grupo_G, grupo_G_puntos, grupo_G_favoritos);
        jugar_partido(0,2, 0, grupo_G, grupo_G_puntos, grupo_G_favoritos);
        jugar_partido(2,1, 0, grupo_G, grupo_G_puntos, grupo_G_favoritos);
        jugar_partido(2,3, 0, grupo_G, grupo_G_puntos, grupo_G_favoritos);
        jugar_partido(3,1, 0, grupo_G, grupo_G_puntos, grupo_G_favoritos);
        jugar_partido(3,0, 0, grupo_G, grupo_G_puntos, grupo_G_favoritos);
        sem_post(&SEM_GRUPOS);
        pthread_exit(NULL);
        break;
  case 7 :
        //jugar los 6 partidos del grupo
        jugar_partido(0,1, 0, grupo_H, grupo_H_puntos, grupo_H_favoritos);
        jugar_partido(0,2, 0, grupo_H, grupo_H_puntos, grupo_H_favoritos);
        jugar_partido(2,1, 0, grupo_H, grupo_H_puntos, grupo_H_favoritos);
        jugar_partido(2,3, 0, grupo_H, grupo_H_puntos, grupo_H_favoritos);
        jugar_partido(3,1, 0, grupo_H, grupo_H_puntos, grupo_H_favoritos);
        jugar_partido(3,0, 0, grupo_H, grupo_H_puntos, grupo_H_favoritos);
        sem_post(&SEM_GRUPOS);
        pthread_exit(NULL);
        break;
  default :
        printf("Invalid grupo\n" );
  }
}


void jugar_grupos ()
{
  printf("***************************************** \n");
  printf("Jugando grupos\n");
  //Creo un "arreglo" para los threads
  pthread_t *threads;
  threads = (pthread_t*) calloc(sizeof(pthread_t)*CANTIDAD_GRUPOS,sizeof(pthread_t));
  int i;
  for( i=0; i < CANTIDAD_GRUPOS; i++ )
  {
    //Creo un apuntador al indice
    int *indice = malloc(sizeof(int));
    *indice = i;
    pthread_create(&(threads[i]) ,NULL,&jugar_grupo,indice);  
  }
}




char* winer_octavos[] = {"Wp49", "Wp50", "Wp51", "Wp52", "Wp53", "Wp54", "Wp55", "Wp56"};




void* jugar_partido_winners(char * nombre_equipo_1, char * nombre_equipo_2, int index_partido, char* data_winners[]){
  printf("Jugando partido entre %s y %s \n", nombre_equipo_1, nombre_equipo_2);
  int goles_equipo_1;
  int goles_equipo_2;
  /* random int entre 0 y 10 */
  goles_equipo_1 = rand() % 10;
  goles_equipo_2 = rand() % 10;
  if(goles_equipo_1 > goles_equipo_2){
        data_winners[index_partido]=nombre_equipo_1;
  }else{
        data_winners[index_partido]=nombre_equipo_2;
  }
}


int obtener_primero(int grupo_puntos[][8]){
  int i;
  int puntaje_maximo=-1;
  int index_maximo=-1;
  for (i = 0; i < 4; i++){
        if(grupo_puntos[i][0]>=puntaje_maximo){
          index_maximo=i;
          puntaje_maximo=grupo_puntos[i][0];
        }
  }
  return index_maximo;
}


int obtener_segundo(int grupo_puntos[][8]){
  int i;
  int puntaje_maximo=-1;
  int index_segundo=-1;


  int index_primero=obtener_primero(grupo_puntos);
  for (i = 0; i < 4; i++){
        if(grupo_puntos[i][0]>=puntaje_maximo && i!=index_primero){
          index_segundo=i;
          puntaje_maximo=grupo_puntos[i][0];
        }
  }
  return index_segundo;
}
void* jugar_partido_octavos(void* indice)
{
  int* pointer = indice;
  int partido = *pointer;
  free(indice);
  int index_1;
  char * nombre_equipo_1;
  int index_2;
  char * nombre_equipo_2;
  switch(partido)
  {
    case 0:
          index_1=obtener_primero(grupo_A_puntos);
          nombre_equipo_1=grupo_A[index_1];
          index_2=obtener_segundo(grupo_B_puntos);
          nombre_equipo_2=grupo_B[index_2];
          jugar_partido_winners(nombre_equipo_1, nombre_equipo_2, 0, winer_octavos);
          sem_post(&SEM_OCTAVOS);
          break;
    case 1:
          index_1=obtener_primero(grupo_C_puntos);
          nombre_equipo_1=grupo_C[index_1];
          index_2=obtener_segundo(grupo_D_puntos);
          nombre_equipo_2=grupo_D[index_2];
          jugar_partido_winners(nombre_equipo_1, nombre_equipo_2, 1, winer_octavos);
          sem_post(&SEM_OCTAVOS);
          break;
    case 2:
          index_1=obtener_primero(grupo_B_puntos);
          nombre_equipo_1=grupo_B[index_1];
          index_2=obtener_segundo(grupo_A_puntos);
          nombre_equipo_2=grupo_A[index_2];
          jugar_partido_winners(nombre_equipo_1, nombre_equipo_2, 2, winer_octavos);
          sem_post(&SEM_OCTAVOS);
          break;
    case 3:
          index_1=obtener_primero(grupo_D_puntos);
          nombre_equipo_1=grupo_D[index_1];
          index_2=obtener_segundo(grupo_C_puntos);
          nombre_equipo_2=grupo_C[index_2];
          jugar_partido_winners(nombre_equipo_1, nombre_equipo_2, 3, winer_octavos);
          sem_post(&SEM_OCTAVOS);
          break;
    case 4:
          index_1=obtener_primero(grupo_E_puntos);
          nombre_equipo_1=grupo_E[index_1];
          index_2=obtener_segundo(grupo_F_puntos);
          nombre_equipo_2=grupo_F[index_2];
          jugar_partido_winners(nombre_equipo_1, nombre_equipo_2, 4, winer_octavos);
          sem_post(&SEM_OCTAVOS);
          break;
    case 5:
          index_1=obtener_primero(grupo_G_puntos);
          nombre_equipo_1=grupo_G[index_1];
          index_2=obtener_segundo(grupo_H_puntos);
          nombre_equipo_2=grupo_H[index_2];
          jugar_partido_winners(nombre_equipo_1, nombre_equipo_2, 5, winer_octavos);
          sem_post(&SEM_OCTAVOS);
          break;
    case 6:
          index_1=obtener_primero(grupo_F_puntos);
          nombre_equipo_1=grupo_F[index_1];
          index_2=obtener_segundo(grupo_E_puntos);
          nombre_equipo_2=grupo_E[index_2];
          jugar_partido_winners(nombre_equipo_1, nombre_equipo_2, 6, winer_octavos);
          sem_post(&SEM_OCTAVOS);
          break;
    case 7:
          index_1=obtener_primero(grupo_H_puntos);
          nombre_equipo_1=grupo_H[index_1];
          index_2=obtener_segundo(grupo_G_puntos);
          nombre_equipo_2=grupo_G[index_2];
          jugar_partido_winners(nombre_equipo_1, nombre_equipo_2, 7, winer_octavos);
          sem_post(&SEM_OCTAVOS);
          break;
    default:
          printf("Partido de octavos invalido\n");

  }
}

void jugar_octavos ()
{
  //Espero a que termine la fase de grupos
  for (int i = 0; i < CANTIDAD_GRUPOS; ++i)
  {
    sem_wait(&SEM_GRUPOS);
  }
  printf("***************************************** \n");
  printf("Jugando octavos \n");

  pthread_t *threads;
  threads = (pthread_t*) calloc(sizeof(pthread_t)*CANTIDAD_GRUPOS,sizeof(pthread_t));
  int i;
  for( i=0; i < CANTIDAD_GRUPOS; i++ )
  {
    //Creo un apuntador al indice
    int *indice = malloc(sizeof(int));
    *indice = i;
    pthread_create(&(threads[i]) ,NULL,&jugar_partido_octavos,indice);  
  }
}


char* winer_cuartos[] = {"Wp57", "Wp58", "Wp59", "Wp60"};
void* jugar_partido_cuartos(void* indice)
{
  int* pointer = indice;
  int partido = *pointer;
  free(indice);
  switch(partido)
  {
    case 0:
      jugar_partido_winners(winer_octavos[0], winer_octavos[1], 0, winer_cuartos);
      sem_post(&SEM_CUARTOS);
      pthread_exit(NULL);
      break;
    case 1:
      jugar_partido_winners(winer_octavos[4], winer_octavos[5], 1, winer_cuartos);
      sem_post(&SEM_CUARTOS);
      pthread_exit(NULL);
      break;
    case 2:
      jugar_partido_winners(winer_octavos[2], winer_octavos[3], 2, winer_cuartos);
      sem_post(&SEM_CUARTOS);
      pthread_exit(NULL);
      break;
    case 3:
      jugar_partido_winners(winer_octavos[6], winer_octavos[7], 3, winer_cuartos);
      sem_post(&SEM_CUARTOS);
      pthread_exit(NULL);
      break;
    default:
      printf("Cuartos de final invalido\n");
  }
}

void jugar_cuartos ()
{
  //Espero a que terminen los octavos
  for (int i = 0; i < 8 ; ++i)
  {
    sem_wait(&SEM_OCTAVOS);
  }
  printf("***************************************** \n");
  printf("Jugando cuartos \n");

  pthread_t *threads;
  threads = (pthread_t*) calloc(sizeof(pthread_t)*4,sizeof(pthread_t));
  int i;
  for( i=0; i < 4; i++ )
  {
    //Creo un apuntador al indice
    int *indice = malloc(sizeof(int));
    *indice = i;
    pthread_create(&(threads[i]) ,NULL,&jugar_partido_cuartos,indice);  
  }
}

char* winer_semis[] = {"Wp61", "Wp62"};
char* champion[] = {"Wfinal"};

void* jugar_partido_semis(void* indice)
{
  int* pointer = indice;
  int partido = *pointer;
  free(indice);
  switch(partido)
  {
    case 0:
      jugar_partido_winners(winer_cuartos[0], winer_cuartos[1], 0, winer_semis);
      sem_post(&SEM_SEMI);
      pthread_exit(NULL);
      break;
    case 1:
      jugar_partido_winners(winer_cuartos[2], winer_cuartos[3], 1, winer_semis);
      sem_post(&SEM_SEMI);
      pthread_exit(NULL);
      break;
    default:
      printf("Semifinal no válida\n");
  }
}
void jugar_semis ()
{
  //espero a que terminen los cuartos
  for (int i = 0; i < 4; ++i)
  {
    sem_wait(&SEM_CUARTOS);
  }
  printf("***************************************** \n");
  printf("Jugando semis \n");
  //Reservo memoria para los threads
  pthread_t *threads;
  threads = (pthread_t*) calloc(sizeof(pthread_t)*2,sizeof(pthread_t));
  int i;
  for( i=0; i < 2; i++ )
  {
    //Creo un apuntador al indice
    int *indice = malloc(sizeof(int));
    *indice = i;
    pthread_create(&(threads[i]) ,NULL,&jugar_partido_semis,indice);  
  }
}
void jugar_final ()
{
  //Espero a que terminen las semis
  for (int i = 0; i < 2; ++i)
  {
    sem_wait(&SEM_SEMI);
  }
  printf("***************************************** \n");
 
  printf("Jugando final \n");
  //final: Wp91 vs Wp62
  jugar_partido_winners(winer_semis[0], winer_semis[1], 0, champion);
  printf("***************************************** \n");
  printf("El nuevo campeon del mundo es %s \n", champion[0]);
  printf("***************************************** \n");
}
int main ()
{
  //Inicializo los semaforos
  sem_init(&SEM_GRUPOS,0,0);
  sem_init(&SEM_OCTAVOS,0,0);
  sem_init(&SEM_CUARTOS,0,0);
  sem_init(&SEM_SEMI,0,0);
  //////////////////////////////////////////////////////////////////////
  // start mundial
  //////////////////////////////////////////////////////////////////////
  srand(time(NULL));


  jugar_grupos();
  jugar_octavos();
  jugar_cuartos();
  jugar_semis();
  jugar_final();
  /////////////////////////////////////////////////////////////////////
  // end mundial
  //////////////////////////////////////////////////////////////////////
}


//Para compilar:   gcc simulador_paralelo-v2.1.c -o compilados/simulador_paralelo-v2.1 -pthread
//Para ejecutar:   ./compilados/simulador_paralelo-v2.1 || ./simulador_paralelo-v2
