/*
** EPITECH PROJECT, 2022
** panoramix.h
** File description:
** header file
*/

#ifndef PANORAMIX_PANORAMIX_H
    #define PANORAMIX_PANORAMIX_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <pthread.h>
    #include <semaphore.h>
    #include <string.h>
    #include <stdbool.h>

    #define USAGE "USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights>" \
    " <nb_refills>"
    #define AWAKE "Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I" \
    " can only make %ld more refills after this one.\n"
    #define DRINK "Villager %d: I need a drink... I see %ld servings left.\n"
    #define FIGHT "Villager %d: Take that roman scum! Only %ld left.\n"
    #define PANO "Villager %d: Hey Pano wake up! We need more potion.\n"

typedef struct village_s {
    long villagers;
    long pot_size;
    long nb_fights;
    long nb_refills;
} village_t;

pthread_mutex_t *my_mutex(void);
sem_t *druid_sem(void);
sem_t *villager_sem(void);
village_t *village(void);

void parse_args(char **av);
void *thread_druid(void *av);
void *thread_villager(void *av);
void get_drink(unsigned int idx);
void fight(void);

    #define DEF_OR_ARG(value, ...) value
    #define ASSERT(v, ...) \
if (v) { \
    fprintf(stderr, "[%s:%d] %s\n", __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stderr, "%s\n", DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) USAGE)); \
    exit(84); \
}
    #define DESTROY(v) \
if (v) { \
    free(v); \
}
#endif
