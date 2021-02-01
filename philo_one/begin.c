/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:29:40 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/01 13:29:44 by bordenoy         ###   ########.fr       */
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

static int start_thread(t_table *table)
{
	pthread_t ppid;
	int i;
	
	i = 0;
	if (table->opt->me > 0 && !must_eat(table))
		return (1);
	while (i < table->opt->nb)
	{
		if (is_peer(table->philosofe[i].state)) {
			if (pthread_create(&ppid, NULL, r_philo, (void*)(&table->philosofe[i])) != 0)
				return (1);
		} else
			if (pthread_create(&ppid, NULL, l_philo, ((void*)&table->philosofe[i])) != 0)
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
