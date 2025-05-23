// sem_solo_uno.c
// Programa que simula múltiples hilos compartiendo un recurso controlado con semáforo

#include <pthread.h>     // Para manejo de hilos
#include <semaphore.h>   // Para semáforos POSIX
#include <stdio.h>       // Para printf
#include <stdlib.h>      // Para rand, srand, malloc
#include <unistd.h>      // Para sleep
#include <time.h>        // Para inicializar la semilla de random
#include "config.h"      // Configuraciones del laboratorio

// Semáforo global que representa los recursos disponibles
sem_t sem_recursos;

// Función que ejecuta cada hilo
void* trabajador(void* arg) {
    long id = (long)arg; // ID del hilo

    for (int i = 0; i < N_ITER; i++) {
        // Espera a que haya recurso disponible
        sem_wait(&sem_recursos);

        // Registro en consola: el hilo ha tomado 1 recurso
        printf("Hilo %ld consumió 1 recurso (iteración %d)\n", id, i);

        // Simula el uso del recurso
        sleep(rand() % 3 + 1); // Espera entre 1 y 3 segundos

        // Devuelve el recurso
        sem_post(&sem_recursos);

        // Registro en consola: el hilo devolvió el recurso
        printf("Hilo %ld devolvió 1 recurso (iteración %d)\n", id, i);
    }

    return NULL;
}

int main() {
    srand(time(NULL)); // Semilla para números aleatorios

    // Inicializa el semáforo con N_RECURSOS disponibles
    sem_init(&sem_recursos, 0, N_RECURSOS);

    // Crea los hilos
    pthread_t threads[N_THREADS];

    for (long i = 0; i < N_THREADS; i++) {
        pthread_create(&threads[i], NULL, trabajador, (void*)i);
    }

    // Espera que todos los hilos terminen
    for (int i = 0; i < N_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Libera el semáforo
    sem_destroy(&sem_recursos);

    return 0;
}
