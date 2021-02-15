#include "../include/philosopher.h"

void routine_me(t_table *table)
{
    int i;
    int c;

    while (1)
    {
        c = 1;
        i = 0;
        while (i < table->nb)
        {
            pthread_mutex_lock(&table->philosofe[i].w);
            if (table->philosofe[i].eat < table->me)
                c = 0;
            if (micros() > table->philosofe[i].await) {
                    message(&table->philosofe[i]," died\n", micros() - table->start);
                    return;
            }
            pthread_mutex_unlock(&table->dead);
            pthread_mutex_unlock(&table->philosofe[i].w);
            i++;
        }
        if (c)
            exit(0);
    }
}

void routine(t_table *table)
{
    int i;
    while (1)
    {
        i = 0;
        while (i < table->nb)
        {
            pthread_mutex_lock(&table->philosofe[i].w);
            if (micros() > table->philosofe[i].await) {
                    message(&table->philosofe[i]," died\n", micros() - table->start);
                    return;
            }
            pthread_mutex_unlock(&table->dead);
            pthread_mutex_unlock(&table->philosofe[i].w);
            i++;
        }
    }
}