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

void take_fork(t_philosophe *t)
{
	message(t, " is thinking");
	if (t->hand) {
		pthread_mutex_lock(&t->table->fork[t->l_fork]);
		message(t, " taken fork");
		pthread_mutex_lock(&t->table->fork[t->r_fork]);
		message(t, " taken fork");
		return ;
	}
		pthread_mutex_lock(&t->table->fork[t->r_fork]);
		message(t, " taken fork");
		pthread_mutex_lock(&t->table->fork[t->l_fork]);
		message(t, " taken fork");
		return ;	
}

void unlock_fork(t_philosophe *t)
{
	if (t->hand) {
		pthread_mutex_unlock(&t->table->fork[t->l_fork]);
		pthread_mutex_unlock(&t->table->fork[t->r_fork]);
		usleep(t->table->tts * 1000);
		return;
	}
	pthread_mutex_unlock(&t->table->fork[t->r_fork]);
	pthread_mutex_unlock(&t->table->fork[t->l_fork]);
	usleep(t->table->tts * 1000);	
	return ;
}
