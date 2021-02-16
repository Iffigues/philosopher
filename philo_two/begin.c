#include "../include/philosopher.h"

void *b_philo(void *philo)
{
	t_philosophe *p;

	p = (t_philosophe*)philo;
	p->await = micros() +  p->table->ttd;
	while (p->table->died) {
	}
	p->table->nb--;
	return NULL;
}

int start_thread(t_table *table)
{
	pthread_t ppid;
	int i;

	i = 0;
	table->start = micros();
	while (i < table->nb)
	{
		if (!(table->philosofe[i].id & 1))
			usleep(table->pair_wait);
		if (i == (table->nb - 1) && (table->philosofe[i].id & 1))
			usleep(table->last_imp_wait);
		if (pthread_create(&ppid, NULL, b_philo, &table->philosofe[i]) != 0)
			return (1);
		pthread_detach(ppid);
		i++;
	}
	return (0);
}