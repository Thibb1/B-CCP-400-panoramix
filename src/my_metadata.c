/*
** EPITECH PROJECT, 2022
** my_metadata.c
** File description:
** metadata
*/

#include "panoramix.h"

sem_t *druid_sem(void)
{
    static sem_t sem;

    return &sem;
}

sem_t *villager_sem(void)
{
    static sem_t sem;

    return &sem;
}

pthread_mutex_t *my_mutex(void)
{
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    return &mutex;
}

village_t *village(void)
{
    static village_t *village;

    if (!village)
        village = calloc(1, sizeof(village_t));
    return village;
}
