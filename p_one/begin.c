#include "../include/philosopher.h"
#include <stdio.h>

static int give_fork(t_table *table)
{
	int i;
	i = 0;

	while (i < table->opt->nb)
	{
		printf("%d\n",table->philosofe[i].state);
		table->philosofe[i].state = 0;
		
		table->philosofe[i].l_fork = table->fork[i];
		if (i == table->opt->nb - 1)
			table->philosofe[i].r_fork = table->fork[0];
		else
		 table->philosofe[i].r_fork = table->fork[i + 1];
		i++;
	}
	return 1;
}

static void *one_fork(void *philo)
{
	t_philosophe *p;

	p = (t_philosophe*)philo;
	pthread_mutex_lock(&p->l_fork);
	p->state++;
	//pthread_mutex_unlock(p->l_fork);
	write(1,"a", 1);
	//pthread_mutex_unlock(philo->l_fork);

}

static void *two_fork(void *philo)
{
	t_philosophe *p;
	write(1,"y",1);
	p = (t_philosophe*)philo;
	pthread_mutex_lock(&p->r_fork);
	write(1,"m",1);
	p->state++;
	//pthread_mutex_unlock(philo->r_fork);
}

static void take_fork(void *philo)
{
	t_philosophe *p;
	pthread_t ppid;
	p = (t_philosophe*)philo;

	if (pthread_create(&ppid, NULL, one_fork, ((void*)philo)))
		return;
	pthread_detach(ppid);
	if (pthread_create(&ppid, NULL, two_fork, ((void*)philo)))
		return;
	pthread_detach(ppid);
	while (p->state != 2)
	{
		//printf("%d\n", p->state);
	}
	p->state = 0;
	write(1, "z",1);
}

static  void *philo(void *philo) 
{
	take_fork(philo);
	while (1)
	{
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
		if (pthread_create(&ppid, NULL, philo, (void*)(&table->philosofe[i++])) != 0)
		;
		pthread_detach(ppid);
		printf("%d\n",i);
	}
	printf("hahai\n");
}

void begin(t_table *table) {
	give_fork(table);
	start_thread(table);
	while (1);
}
