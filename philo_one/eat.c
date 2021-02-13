/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:20:39 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 15:53:36 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int eat(t_philosophe *p)
{
	pthread_mutex_lock(&p->w);
	message(p, " is eating\n", micros() - p->table->start);
	p->await = micros() +  p->table->ttd;
	pthread_mutex_unlock(&p->w);
	p->eat++;
	//gettimeofday(p->le, NULL);
	await(p->table->tte);
	return 1;
}
