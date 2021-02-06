/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:29:40 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 15:31:47 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static int give_fork(t_table *table)
{
	int i;
	i = 0;

	while (i < table->nb)
	{
		table->philosofe[i].table = table;
		table->philosofe[i].position = i;
		table->philosofe[i].id = i + 1;
		table->philosofe[i].eat = 0;
		pthread_mutex_init(&table->philosofe[i].w, NULL);
		table->philosofe[i].eating = 0;
		table->philosofe[i].hand = (i & 1);
		table->philosofe[i].l_fork = i;
		if (i == table->nb - 1)
			table->philosofe[i].r_fork = 0;
		else
			table->philosofe[i].r_fork = i + 1;
		i++;
	}
	return 1;
}

void *health(void *philo)
{
	t_philosophe *p;
	unsigned long long y;

	p = (t_philosophe*)philo;
	while ((y = micros()))
 	{
		pthread_mutex_lock(&p->w);
		if (y >= p->await && !p->eating) {
			message(p, " dying");		
			pthread_mutex_unlock(&p->table->dead);
		}
		pthread_mutex_unlock(&p->w);
		usleep(1000);
	}
	return p;
}

static int start_thread(t_table *table)
{
	pthread_t ppid;
	int i;
	
	i = 0;

	pthread_mutex_lock(&table->dead);
	if (table->me > 0 && !must_eat(table))
		return (1);
	table->start = micros();
	while (i < table->nb)
	{
		if (pthread_create(&ppid, NULL, b_philo, (void*)(&table->philosofe[i])) != 0)
			return (1);
		pthread_detach(ppid);
		usleep(100);
		i++;
	}
	return (0);
}

int begin(t_table *table) {
	give_fork(table);
/*	for (int i = 0; i < table.nb; i++) {
		printf("%d %d %d\n",i,table.philosofe[i].l_fork, table.philosofe[i].r_fork);
	}
	return 0;*/
	return start_thread(table);
}
