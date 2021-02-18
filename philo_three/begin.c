#include "../include/philosopher.h"

int b_philo(t_philosophe *p)
{
    pthread_t ppid;

    if (!(p->id & 1))
			    usleep(p->table->pair_wait);
	    if (p->id == (p->table->nb) && (p->id & 1))
		    	usleep(p->table->last_imp_wait);
    if (pthread_create(&ppid, NULL, routines, p) != 0)
			    return (1);
		pthread_detach(ppid);
	while (p->table->died) {
        take_fork(p);
		message(p, " is thinking\n", micros() - p->table->start);
	}
	p->table->nb--;
    exit(0);
	return 0;
}

int start_thread(t_table *table)
{
	int i;

	i = 0;
    sem_wait(table->dead);
	table->start = micros();
	while (i < table->nb)
	{
        table->philosofe[i].pid = fork();
        if (table->philosofe[i].pid == 0) {
 		    b_philo(&table->philosofe[i]);
            exit(0);
        }
		i++;
	}
	return (0);
}