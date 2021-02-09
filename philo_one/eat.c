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
	p->eating = 1;
	message(p," eating");
	p->eating = 0;
	p->eat++;
	p->await = micros() +  p->table->ttd;
	//gettimeofday(p->le, NULL);
	await(p->table->tte * 1000);
	pthread_mutex_unlock(&p->w);
	return 1;
}
