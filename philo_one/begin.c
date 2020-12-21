#include "../include/philosopher.h"

static int give_fork(t_table *table)
{
	int i;
	i = 0;

	while (i < table->opt->nb)
	{
		table->philosofe[i].table = table;
		table->philosofe[i].state = i + 1;
		table->philosofe[i].l_fork = i;
		if (i == table->opt->nb - 1)
			table->philosofe[i].r_fork = 0;
		else
		 table->philosofe[i].r_fork = i + 1;
		i++;
	}
	return 1;
}

void *golang(void *philo)
{
	t_philosophe *p;

	p = (t_philosophe*)philo;
	return p;
}

static void start_thread(t_table *table)
{
	pthread_t ppid;
	int i;
	
	i = 0;
	if (table->opt->me > 0 && !must_eat(table))
		return;
	while (i < table->opt->nb)
	{
		if (is_peer(table->philosofe[i].state)) {
			if (pthread_create(&ppid, NULL, r_philo, (void*)(&table->philosofe[i])) != 0)
				return;
		} else
			if (pthread_create(&ppid, NULL, l_philo, ((void*)&table->philosofe[i])) != 0)
				return;
		pthread_detach(ppid);
		i++;
	}
}

void begin(t_table *table) {
	give_fork(table);
	start_thread(table);
	while (1);
}
