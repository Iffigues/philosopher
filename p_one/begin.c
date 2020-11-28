#include "../include/philosopher.h"

static int give_fork(t_table *table)
{
	int i;
	i = 0;

	while (i < table->opt->nb)
	{
		table->philosofe[i].l_fork = &table->fork[i];
		if (i == table->opt->nb - 1)
			table->philosofe[i].r_fork = &table->fork[0];
		else
		 table->philosofe[i].l_fork = &table->fork[i];
		i++;
	}
	return 1;
}

static  void *philo(void *philo) {
}

static void start_thread(t_table *table)
{
	pthread_t ppid;
	int i;
	
	i = 0;
	while (i < table->opt->nb)
	{
		if (pthread_create(&ppid, NULL, philo, (void*)(&table->philosofe[i])) != 0)
			return ;
		pthread_detach(ppid);
		i++;
	}
}

void begin(t_table *table) {
	give_fork(table);
	start_thread(table);
}
