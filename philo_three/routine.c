/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:41:22 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/02 17:20:12 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

static void	*dier(t_philosophe *table)
{
	int i;

	i = 0;
	message(table, " died\n", micros() - table->table->start);
	sem_post(table->w);
	sem_post(table->table->dead);
	table->table->died = 0;
	return (NULL);
}

void		*routines(void *pp)
{
	t_philosophe *p;

	p = (t_philosophe*)pp;
	p->await = micros() + p->table->ttd;
	while (p->table->died)
	{
		sem_wait(p->w);
		if (micros() > p->await)
			return (dier(p));
		if (p->table->me > 0)
			if (p->eat >= p->table->me)
			{
				sem_post(p->table->eat);
				p->table->died = 0;
				return (NULL);
			}
		sem_post(p->w);
		//usleep(1000);
	}
	return (NULL);
}
