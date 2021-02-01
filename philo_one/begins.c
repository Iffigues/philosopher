/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begins.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:29:52 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/01 14:37:39 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int must_die(void *philo)
{
	pthread_t ppid;

	if (pthread_create(&ppid, NULL, golang, philo) != 0)
		return 0;
	pthread_detach(ppid);
	return 1;

}

void *r_philo(void *philo)
{
	t_philosophe *p;

	p = (t_philosophe*)philo;
	p->start = micros(); 
	must_die(philo);
	while (1)
	{
		take_rfork(p);
		unlock_fork(p);
	}
	return NULL;
}

 void *l_philo(void *philo)
{
	t_philosophe *p;

	p = (t_philosophe*)philo;
	p->start = micros();
	must_die(philo);
	while (1)
	{
		take_lfork(p);
		unlock_fork(p);
	}
	return NULL;
}

void *me(void *table)
{
	t_table *p;
	int i;
	int b;

	p = (t_table*)table;
	while (1)
	{
		i = 0;
		b = 0;
		while(i <= p->opt->nb)
			if (p->philosofe[i++].eat < p->opt->me)
				b = 1;
		if (!b)
		{
			pthread_mutex_unlock(&p->dead);
		}
	}
	return table;
}

int must_eat(t_table *table)
{
	pthread_t ppid;

	if (table->opt->me > 0) {
		if (pthread_create(&ppid, NULL, me, ((void*)table)))
			return (0);
		pthread_detach(ppid);
	}
	return (1);
}
