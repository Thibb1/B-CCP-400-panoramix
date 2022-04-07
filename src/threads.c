/*
** EPITECH PROJECT, 2022
** threads.c
** File description:
** thread
*/

#include "panoramix.h"

void fight(void)
{
    long nb = village()->villagers + 1;
    pthread_t *thread = calloc(nb, sizeof(pthread_t));
    unsigned int *idx = calloc(nb, sizeof(unsigned int));

    ASSERT(!thread || !idx)
    pthread_create(&thread[nb - 1], NULL, thread_druid, NULL);
    for (unsigned int i = 0; i < nb - 1; i++) {
        idx[i] = i;
        pthread_create(&thread[i], NULL, thread_villager, &idx[i]);
    }
    for (unsigned int i = 0; i < nb - 1; i++)
        pthread_join(thread[i], NULL);
}

void *thread_druid(void *av)
{
    (void) av;
    long pot_size = village()->pot_size - 1;

    printf("Druid: I'm ready... but sleepy...\n");
    sem_post(villager_sem());
    while (village()->nb_refills) {
        sem_wait(druid_sem());
        pthread_mutex_lock(my_mutex());
        village()->pot_size = pot_size;
        printf(AWAKE, --village()->nb_refills);
        pthread_mutex_unlock(my_mutex());
        sem_post(villager_sem());
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    pthread_exit(NULL);
}

void *thread_villager(void *av)
{
    unsigned idx = *((unsigned int *) av);
    long fights = village()->nb_fights;

    sem_wait(villager_sem());
    printf("Villager %d: Going into battle!\n", idx);
    sem_post(villager_sem());
    sleep(1);
    while (fights) {
        sem_wait(villager_sem());
        printf(DRINK, idx, village()->pot_size);
        get_drink(idx);
        printf(FIGHT, idx, --fights);
        sem_post(villager_sem());
    }
    printf("Villager %d: I'm going to sleep now.\n", idx);
    pthread_exit(NULL);
}

void get_drink(unsigned int idx)
{
    if (village()->pot_size) {
        pthread_mutex_lock(my_mutex());
        village()->pot_size--;
        pthread_mutex_unlock(my_mutex());
    } else if (village()->nb_refills) {
        printf(PANO, idx);
        sem_post(druid_sem());
        sem_wait(villager_sem());
    } else {
        sem_post(villager_sem());
        pthread_exit(NULL);
    }
}
