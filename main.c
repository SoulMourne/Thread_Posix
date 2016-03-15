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

/*
 * 
 */
int main(int argc, char** argv) 
{
    printf("--------- exercice 1 -----------\n");
    exercice1();
    
    return (EXIT_SUCCESS);
}

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
