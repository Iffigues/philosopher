/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:39:45 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/01 13:39:47 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int take_lfork(t_philosophe *t)
{
	pthread_mutex_lock(&t->table->fork[t->l_fork]);
	pthread_mutex_lock(&t->table->fork[t->r_fork]);
	return 1;
}

int take_rfork(t_philosophe *t)
{
	pthread_mutex_lock(&t->table->fork[t->r_fork]);
	pthread_mutex_lock(&t->table->fork[t->l_fork]);
	return 1;
}

int unlock_fork(t_philosophe *t)
{
	pthread_mutex_unlock(&t->table->fork[t->l_fork]);
	pthread_mutex_unlock(&t->table->fork[t->r_fork]);
	return 1;
}
