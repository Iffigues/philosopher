/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begins.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:29:52 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 15:31:14 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void *b_philo(void *philo)
{
	t_philosophe *p;

	p = (t_philosophe*)philo;
	p->await = micros() +  p->table->ttd;
	while (1) {
		take_fork(p);
		eat(p);
		unlock_fork(p);
	}
	return NULL;
}

