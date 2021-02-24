#include "../include/philosopher.h"

int b_philo(t_philosophe *p)
{
    pthread_t ppid;
 
    p->pid = fork();
    if (p->pid != 0) 
        return 0;
    if (!(p->id & 1))
		usleep(p->table->pair_wait);
	if (p->id == (p->table->nb) && (p->id & 1))
		usleep(p->table->last_imp_wait);
        return 0;
    p->await = micros() + p->table->ttd;
    if (pthread_create(&ppid, NULL, routines, p) != 0)
	    return (1);
	pthread_detach(ppid);
	while (p->table->died)
        take_fork(p);
	return 0;
}

int start_thread(t_table *table)
{
	int i;
    t_philosophe *p;

	i = 0;

    table->start = micros();
    sem_wait(table->dead);
	while (i < table->nb)
	{
        p = (t_philosophe*)&table->philosofe[i];
 		    b_philo(p);
		i++;
	}
	return (0);
}