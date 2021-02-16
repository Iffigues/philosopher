/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:39:45 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 15:55:15 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	take_fork(t_philosophe *t)
{
	pthread_mutex_lock(&t->table->fork[t->l_fork]);
	message(t, " has taken a fork\n", micros() - t->table->start);
	pthread_mutex_lock(&t->table->fork[t->r_fork]);
	message(t, " has taken a fork\n", micros() - t->table->start);
	pthread_mutex_lock(&t->w);
	message(t, " is eating\n", micros() - t->table->start);
	t->eat++;
	t->await = micros() + t->table->ttd;
	await(t->table->tte);
	pthread_mutex_unlock(&t->w);
	pthread_mutex_unlock(&t->table->fork[t->r_fork]);
	pthread_mutex_unlock(&t->table->fork[t->l_fork]);
	usleep(t->table->tts);
	message(t, " is sleeping\n", micros() - t->table->start);
}
