/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:29:40 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 12:35:08 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static int give_fork(t_table *table)
{
	int i;
	i = 0;

	while (i < table->opt->nb)
	{
		table->philosofe[i].table = table;
		table->philosofe[i].id = i + 1;
		table->philosofe[i].eat = 0;
		table->philosofe[i].hand = (i & 1);
		table->philosofe[i].l_fork = i;
		if (i == table->opt->nb - 1)
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

	p = (t_philosophe*)philo;
	return p;
}

static int start_thread(t_table *table)
{
	pthread_t ppid;
	int i;
	
	i = 0;

	pthread_mutex_lock(&table->dead);
	if (table->opt->me > 0 && !must_eat(table))
		return (1);
	while (i < table->opt->nb)
	{
		if (pthread_create(&ppid, NULL, b_philo, (void*)(&table->philosofe[i])) != 0)
			return (1);
		pthread_detach(ppid);
		i++;
	}
	return (0);
}

int begin(t_table *table) {
	give_fork(table);
	return start_thread(table);
}
