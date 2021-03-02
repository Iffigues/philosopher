/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:41:44 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/01 16:43:18 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

int	b_philo(t_philosophe *p)
{
	pthread_t ppid;

	if (!(p->id & 1))
		await(p->table->pair_wait);
	if (p->id == p->table->nb && p->id & 1)
		await(p->table->last_imp_wait);
	if (pthread_create(&ppid, NULL, routines, p) != 0)
		return (1);
	pthread_detach(ppid);
	while (p->table->died)
		take_fork(p);
	return (0);
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
		if (table->me)
			sem_wait(table->eat);
		if ((p->pid = fork()) == 0)
			exit(b_philo(p));
		else if (p->pid < 0)
			return (-1);
		i++;
	}
	return (0);
}