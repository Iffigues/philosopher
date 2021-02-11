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

static int ft_putnbr(t_table *table ,uint64_t n, int fd)
{
	int		length;
	uint64_t nn;

	length = 1;
	nn = n;
	while ((nn /= 10))
		length *= 10;
	while (length != 0)
	{
		table->b[fd++] = '0' + (n / length);
		n = (n % length);
		length /= 10;
	}
	return fd;
}

static int ft_addchar(t_table *t, char tt, int i){
	t->b[i] = tt;
	return i + 1;
}

static int ft_addStr(t_table *t, char *tt, int i) {
	while(*tt)
		t->b[i++] = *tt++;
	return i;
}

void message(t_philosophe *e, char *t)
{
	int i;

	pthread_mutex_lock(&e->table->message);
		i = ft_putnbr(e->table, 0,0);
		i = ft_addchar(e->table,' ',i);
		i = ft_putnbr(e->table, e->id, i);
		i = ft_addStr(e->table, t, i);
		write(1, e->table->b, i);
	pthread_mutex_unlock(&e->table->message);
}
