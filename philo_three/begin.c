#include "../include/philosopher.h"

int b_philo(t_philosophe *p)
{
    pthread_t ppid;
 
    sem_wait(p->start);
    sem_wait(p->start);
    sem_post(p->start);
    p->await = micros() + p->table->ttd;
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
	while (i < table->nb)
	{
        table->philosofe[i].pid = fork();
        if (!table->philosofe[i].pid) 
 		    exit(b_philo(&table->philosofe[i]));
		i++;
	}
    table->start = micros();
	return (0);
}