/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "panoramix.h"

int main(int ac, char **av)
{
    ASSERT(ac != 5);
    parse_args(av);
    ASSERT(sem_init(druid_sem(), 0, 0), "SEM INIT ERROR");
    ASSERT(sem_init(villager_sem(), 0, 0), "SEM INIT ERROR");
    ASSERT(pthread_mutex_init(my_mutex(), NULL), "MUTEX INIT ERROR");
    fight();
    sem_destroy(druid_sem());
    sem_destroy(villager_sem());
    pthread_mutex_destroy(my_mutex());
    DESTROY(village());
}

void parse_args(char **av)
{
    char *end_ptr;

    village()->villagers = strtol(av[1], &end_ptr, 10);
    ASSERT(av[1] == end_ptr || village()->villagers < 1)
    village()->pot_size = strtol(av[2], &end_ptr, 10);
    ASSERT(av[2] == end_ptr || village()->pot_size < 1)
    village()->nb_fights = strtol(av[3], &end_ptr, 10);
    ASSERT(av[3] == end_ptr || village()->nb_fights < 1)
    village()->nb_refills = strtol(av[4], &end_ptr, 10);
    ASSERT(av[4] == end_ptr || village()->nb_refills < 1)
}
