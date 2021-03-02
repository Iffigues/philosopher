/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:15:31 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/02 13:55:49 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	dier(t_table *table, int i)
{
	message(&table->philosofe[i], " died\n", micros() - table->start);
	sem_post(table->philosofe[i].w);
	sem_post(table->dead);
}

static void	fully(t_table *table)
{
	table->died = 0;
	message(&table->philosofe[0], " full\n", micros() - table->start);
	sem_post(table->dead);
}

void		routine_me(t_table *table)
{
	int i;
	int c;

	while (table->died)
	{
		c = 1;
		i = 0;
		while (i < table->ns)
		{
			sem_wait(table->philosofe[i].w);
			if (table->philosofe[i].eat < table->me)
				c = 0;
			if (micros() > table->philosofe[i].await)
				return (dier(table, i));
			sem_post(table->philosofe[i].w);
			i++;
		}
		if (c)
			return (fully(table));
	}
}

void		routine(t_table *table)
{
	int i;

	while (table->died)
	{
		i = 0;
		while (i < table->ns)
		{
			sem_wait(table->philosofe[i].w);
			if (micros() > table->philosofe[i].await)
				return (dier(table, i));
			sem_post(table->philosofe[i].w);
			i++;
		}
	}
}
