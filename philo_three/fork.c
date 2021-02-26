/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:00:18 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/26 15:01:00 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	sem_name(int i, char *b)
{
	char	*t;
	int		k;

	k = 0;
	t = ft_itoa(i);
	b[k++] = 'p';
	b[k++] = '_';
	while (*t)
		b[k++] = *t++;
	b[k] = 0;
}

void	take_fork(t_philosophe *t)
{
	sem_wait(t->table->fork);
	message(t, " has taken a fork\n", micros() - t->table->start);
	sem_wait(t->table->fork);
	message(t, " has taken a fork\n", micros() - t->table->start);
	sem_wait(t->w);
	message(t, " is eating\n", micros() - t->table->start);
	t->eat++;
	t->await = micros() + t->table->ttd;
	await(t->table->tte);
	sem_post(t->w);
	sem_post(t->table->fork);
	sem_post(t->table->fork);
	await(t->table->tts);
	message(t, " is sleeping\n", micros() - t->table->start);
	message(t, " is thinking\n", micros() - t->table->start);
}
