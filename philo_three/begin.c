/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:41:44 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/26 15:05:33 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	b_philo(t_philosophe *p)
{
	pthread_t ppid;

	if ((p->pid = fork()) != 0)
		return (0);
    sem_wait(p->w);
    sem_post(p->w);
	if (!(p->id & 1))
		await(p->table->pair_wait);
	if (p->id == p->table->nb && p->id & 1)
		await(p->table->last_imp_wait);
	if (pthread_create(&ppid, NULL, routines, p) != 0)
		return (1);
	pthread_detach(ppid);
	while (p->table->died)
		take_fork(p);
	exit(0);
}

int	start_thread(t_table *table)
{
	int				i;
	t_philosophe	*p;

	i = 0;
	table->start = micros();
	sem_wait(table->dead);
	while (i < table->nb)
	{
		p = &table->philosofe[i];
        sem_wait(p->w);
		if (table->me)
			sem_wait(table->eat);
		b_philo(p);
		i++;
	}
	return (0);
}
