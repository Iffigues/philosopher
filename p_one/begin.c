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

static void *one_fork(void *philo)
{

}

static void *two_fork(void *philo)
{
}

static void take_fork(void *philo)
{
}

static void *golang(void *philo)
{
}

static int must_die(void *philo)
{
	t_philosophe *p;
	pthread_t ppid;

	p = (t_philosophe *)philo;
	if (pthread_create(&ppid, NULL, golang, philo) != 0)
		return 0;
	pthread_detach(ppid);
	return 1;

}

static  void *r_philo(void *philo) 
{
	t_philosophe *p;

	p = (t_philosophe*)philo;
	must_die(philo);
	while (1)
	{
		take_rfork(p);
		unlock_fork(p);
	}
}

static void *l_philo(void *philo) 
{
	t_philosophe *p;

	p = (t_philosophe*)philo;
	must_die(philo);
	while (1)
	{
		take_lfork(p);
		unlock_fork(p);
	}		
}

static void *me(void *table)
{
}

static int must_eat(t_table *table)
{
	pthread_t ppid;

	if (pthread_create(&ppid, NULL, me, ((void*)table)))
		return (0);
	pthread_detach(ppid);
	return (1);
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
