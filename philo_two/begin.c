/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:08:12 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/02 13:15:17 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	*b_philo(void *philo)
{
	t_philosophe *p;

	p = (t_philosophe*)philo;
	p->await = micros() + p->table->ttd;
	if (!(p->id & 1))
		usleep(p->table->pair_wait);
	if (p->id == (p->table->nb) && (p->id & 1))
		usleep(p->table->last_imp_wait);
	while (p->table->died)
	{
		take_fork(p);
		message(p, " is thinking\n", micros() - p->table->start);
	}
	p->table->nb--;
	return (NULL);
}

int		start_thread(t_table *table)
{
	pthread_t	ppid;
	int			i;

	i = 0;
	sem_wait(table->dead);
	table->start = micros();
	while (i < table->nb)
	{
		if (pthread_create(&ppid, NULL, b_philo, &table->philosofe[i]) != 0)
			return (1);
		pthread_detach(ppid);
		i++;
	}
	return (0);
}
