#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>

sem_t s1;
sem_t s2;
sem_t s3;
void* t1 (void* parametro)
{
	sem_wait(&s1);
	printf("Ma ");
	sem_post(&s2);
	pthread_exit(NULL);
}
void* t2 (void* parametro)
{
	sem_wait(&s2);
	printf("ra ");
	sem_post(&s3);
	pthread_exit(NULL);
}
void* t3 (void* parametro)
{
	sem_wait(&s3);
	printf("doo...\n");
	sem_post(&s1);
	pthread_exit(NULL);
}
int main ()
{
	int iteraciones = 3;
//	printf("Inicializando semaforo.\n");
	sem_init(&s1,0,1);
	sem_init(&s2,0,0);
	sem_init(&s3,0,0);
//	printf("Semaforo inicializado\n");
	//pthread_mutex_init ( &mi_mutex, NULL);
//	printf("Creando thread\n");
	pthread_t p1; //una variable de tipo pthread_t sirve para identificar al hilo que se cree
	pthread_t p2;
	pthread_t p3;
	int rc;
	for(int i = 0; i < iteraciones; i++)
	{
		rc = pthread_create(&p1,NULL,t1,NULL);
		rc = pthread_create(&p2,NULL,t2,NULL);
		rc = pthread_create(&p3,NULL,t3,NULL);
	}
	if (rc){
	            printf("Error:unable to create thread, %d \n", rc);
	            exit(-1);
	       }
	//pthread_mutex_destroy(&mi_mutex);
//	printf("Saliendo\n");
	pthread_exit(NULL);
//	printf("Afuera\n");
}
			    

