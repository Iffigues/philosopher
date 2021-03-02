/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:16:45 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/02 16:44:53 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	dier(t_table *table, int i)
{
	//table->died = 0;
	message(&table->philosofe[i], " died\n", micros() - table->start);
	pthread_mutex_unlock(&table->philosofe[i].w);
	pthread_mutex_unlock(&table->dead);
}

static void	fully(t_table *table)
{
	message(&table->philosofe[0], " full\n", micros() - table->start);
	pthread_mutex_unlock(&table->dead);
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
			pthread_mutex_lock(&table->philosofe[i].w);
			if (table->philosofe[i].eat < table->me)
				c = 0;
			if (micros() > table->philosofe[i].await)
				return (dier(table, i));
			pthread_mutex_unlock(&table->philosofe[i].w);
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
			pthread_mutex_lock(&table->philosofe[i].w);
			if (micros() > table->philosofe[i].await)
				return (dier(table, i));
			pthread_mutex_unlock(&table->philosofe[i].w);
			i++;
		}
	}
}
