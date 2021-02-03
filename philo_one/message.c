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
#include <unistd.h>
void message(t_philosophe *e, char *t)
{
	unsigned long long y;
	int h;
	t_philosophe *p;

	p = (t_philosophe*)e;
	pthread_mutex_lock(&e->table->message);
	y = micros();
	h = (int)(y - p->table->start);
	ft_putnbr(h);
	write(1," ",1);
	ft_putnbr(e->id);
	printf("%s\n",t);
	//write(1,"\n",1);
	pthread_mutex_unlock(&e->table->message);
}
