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
