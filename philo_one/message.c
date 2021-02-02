/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:40:03 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 16:26:40 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void message(t_philosophe *e, char *t)
{
	unsigned long long y;
	int h;
	t_philosophe *p;

	p = (t_philosophe*)e;
	pthread_mutex_lock(&e->table->message);
	y = micros();
	h = (int)(y - p->table->start);
	m(e,t,h);
	pthread_mutex_unlock(&e->table->message);
}
