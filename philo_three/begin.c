#include "../include/philosopher.h"

int b_philo(t_philosophe *p)
{
    pthread_t ppid;
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
        if (!(table->philosofe[i].id & 1))
			usleep(table->pair_wait);
		if (i == (table->nb - 1) && (table->philosofe[i].id & 1))
			usleep(table->last_imp_wait);
        table->philosofe[i].pid = fork();
        if (table->philosofe[i].pid == 0) {
 		    b_philo(&table->philosofe[i]);
            exit(0);
        }
		i++;
	}
	return (0);
}