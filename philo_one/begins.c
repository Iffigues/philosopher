/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begins.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:29:52 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 15:31:14 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int must_die(void *philo)
{
	pthread_t ppid;

	if (pthread_create(&ppid, NULL, health, philo) != 0)
		return 0;
	pthread_detach(ppid);
	return 1;
}

void *b_philo(void *philo)
{
	t_philosophe *p;

	p = (t_philosophe*)philo;
	if (!(must_die(philo)))
		pthread_mutex_unlock(&p->table->dead);
	while (1) {
		take_fork(p);
		eat(p);
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
		while(i < p->nb)
			if (p->philosofe[i++].eat < p->me)
				b = 1;
		if (!b)
		{
			pthread_mutex_unlock(&p->dead);
		}
	}
	return table;
}

int must_eat(t_table table)
{
	pthread_t ppid;

	if (table.me > 0) {
		if (pthread_create(&ppid, NULL, me, ((void*)&table)))
			return (0);
		pthread_detach(ppid);
	}
	return (1);
}
