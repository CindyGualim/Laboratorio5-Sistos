// monitor_recursos.c
// Programa que usa un monitor (mutex + condición) para controlar recursos

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "config.h"

// Variables para controlar acceso
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int available = N_RECURSOS;

// Función para que un hilo consuma varios recursos
int decrease_count(int count) {
    pthread_mutex_lock(&mtx);

    while (available < count) {
        pthread_cond_wait(&cond, &mtx);
    }

    available -= count;

    pthread_mutex_unlock(&mtx);
    return 0;
}

// Función para devolver varios recursos
int increase_count(int count) {
    pthread_mutex_lock(&mtx);

    available += count;
    pthread_cond_broadcast(&cond); // Despierta a todos los hilos esperando

    pthread_mutex_unlock(&mtx);
    return 0;
}

// Función que ejecuta cada hilo
void* trabajador_monitor(void* arg) {
    long id = (long)arg;

    for (int i = 0; i < N_ITER; i++) {
        int c = rand() % MAX_PETICION + 1; // Pide entre 1 y MAX_PETICION

        decrease_count(c);
        printf("Hilo %ld consumió %d recurso(s) (iteración %d)\n", id, c, i);

        sleep(rand() % 3 + 1); // Simula uso

        increase_count(c);
        printf("Hilo %ld devolvió %d recurso(s) (iteración %d)\n", id, c, i);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    pthread_t threads[N_THREADS];
    for (long i = 0; i < N_THREADS; i++) {
        pthread_create(&threads[i], NULL, trabajador_monitor, (void*)i);
    }

    for (int i = 0; i < N_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
