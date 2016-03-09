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

/*
 * 
 */
int main(int argc, char** argv) 
{
    pthread_t a;
    pthread_create(&a, NULL, helloWorld, NULL);
    helloWorld();
    pthread_join(a,NULL);
    
    
    return (EXIT_SUCCESS);
}

void* helloWorld()
{
    printf("Hello from the %d side !\n", (int)pthread_self());
}

