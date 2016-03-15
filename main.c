/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: etude
 *
 * Created on 9 mars 2016, 14:41
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* helloWorld();
void exercice1();

void exercice2();
void* sortieThread(void* args);

void exercice4();
void* incrementation(void* arg);
/*
 * 
 */
int main(int argc, char** argv) 
{
    printf("--------- exercice 1 -----------\n");
    exercice1();
    
    exercice2();

    exercice4();
    
    return (EXIT_SUCCESS);
}

/* EXERCICE 1*/

void* helloWorld(void* args)
{
    printf("Hello from the %lu side !\n", (long unsigned int)args);
}

void exercice1()
{
        //Creation de 2 threads
    
    pthread_t a;
    pthread_create(&a, NULL, helloWorld, (void*)pthread_self());
    pthread_t b;
    pthread_create(&b, NULL, helloWorld, (void*)pthread_self());
    pthread_join(a,NULL);
    pthread_join(b,NULL);
    
    printf("%lu\n",pthread_self());
}


/* EXERCICE 2*/

void exercice2()
{
    int* i;
    int codeThread1 = 8;
    pthread_t a;
    pthread_create(&a, NULL, sortieThread, (void*)codeThread1);
    pthread_join(a,(void**)&i);
    
    int* j;
    int codeThread2 = 3;
    pthread_t b;
    pthread_create(&b, NULL, sortieThread, (void*)codeThread2);
    pthread_join(b,(void**)&j);
    
    printf("Thread 1 = %d\nThread 2 = %d\n",i,j);

}

void* sortieThread(void* args)
{
    int* i = malloc(sizeof(int));
    i = args;
    pthread_exit((void*)i);
}

/* EXERCICE 4 */

void exercice4()
{
    int* i = malloc(sizeof(int));
    *i=0;

    pthread_t a;
    pthread_create(&a, NULL, incrementation,(void*)i);

    pthread_t b;
    pthread_create(&b,NULL,incrementation,(void*)i);

    pthread_join(a,NULL);
    pthread_join(b,NULL);
}

void* incrementation(void* arg)
{
    int* i;
    i = arg;
    printf("%d\n", *i);

    int j;
    for (j=0; j<10000; j++)
    {
        if (pthread_mutex_lock(i) == 0)
        {
            *i = *i+1;
            printf("%d\n", *i);
            pthread_mutex_unlock(i);
        }
        else
        {
            j--;
        }
    }
}