#include <stdio.h>
#include <pthread.h>

int saldo;

void * printHola(void* arg) {
    int pid = *((int *)arg);
    printf("Hola desde el hilo. Soy el hilo %d\n", pid);
    pthread_exit(NULL);

    return NULL;
}

void *incrementa_saldo(void *arg) {
    saldo += 100;
}

int main() {
    int NUM_THREADS = 20;
    pthread_t thread_status[NUM_THREADS];
    int pids[20];

    saldo = 0;

    for (int i = 0; i < NUM_THREADS; i++) {
        pids[i] = i;
        // pthread_create(&thread_status[i], NULL, printHola, (void *)&pids[i]);
        pthread_create(&thread_status[i], NULL, incrementa_saldo, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_status[i], NULL);
    }

    printf("El saldo final es de: %d\n", saldo);
    pthread_exit(NULL); // Esta función tiene un return, así que todo el código después de esto no se ejecuta   
}