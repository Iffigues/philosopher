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
		if (!(table->philosofe[i].le = malloc(sizeof(struct timeval))))
			return (0);
		table->philosofe[i].id = i + 1;
		table->philosofe[i].eat = 0;
		pthread_mutex_init(&table->philosofe[i].w, NULL);
		table->philosofe[i].eating = 0;
		table->philosofe[i].hand = (i & 1);
		table->philosofe[i].l_fork = i;
		if (table->nb == 1) {
			table->philosofe[0].r_fork = 0;
			table->philosofe[0].l_fork = 1;
		} else {
			if (i == table->nb - 1)
				table->philosofe[i].r_fork = 0;
			else
				table->philosofe[i].r_fork = i + 1;
		}
		i++;
	}
	return 1;
}


static int start_thread(t_table *table)
{
	pthread_t ppid;
	int i;
	
	i = 0;

	pthread_mutex_lock(&table->dead);
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
	return start_thread(table);
}
