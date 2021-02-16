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

static void ff(t_table *table, int i) {
	table->philosofe[i].table = table;
	table->philosofe[i].position = i;
	table->philosofe[i].id = i + 1;
	table->philosofe[i].eat = 0;
	pthread_mutex_init(&table->philosofe[i].w, NULL);
	table->philosofe[i].l_fork = i;
	if (table->nb == 1)
	{
		table->philosofe[0].r_fork = 0;
		table->philosofe[0].l_fork = 0;
	}
	else
	{
		if (i == table->nb - 1)
			table->philosofe[i].r_fork = 0;
		else
			table->philosofe[i].r_fork = i + 1;
	}
}

static int	give_fork(t_table *table)
{
	int i;

	i = 0;
	while (i < table->nb)
	{
		ff(table, i);
		i++;
	}
	return 1;
}

void *b_philo(void *philo)
{
	t_philosophe *p;

	p = (t_philosophe*)philo;
	p->await = micros() +  p->table->ttd;
	while (p->table->died) {
		take_fork(p);
		message(p, " is thinking\n",micros() - p->table->start);
	}
	p->table->nb--;
	return NULL;
}

int start_thread(t_table *table)
{
	pthread_t ppid;
	int i;

	i = 0;
	give_fork(table);
	pthread_mutex_lock(&table->dead);
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
