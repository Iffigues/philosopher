/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:40:03 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/02 14:42:52 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

static int		ft_putnbr(t_table *table, long n, int fd)
{
	long	length;
	long	nn;

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
	return (fd);
}

static int		ft_addchar(t_table *t, char tt, int i)
{
	t->b[i] = tt;
	return (i + 1);
}

static int		ft_addstr(t_table *t, char *tt, int i)
{
	while (*tt)
		t->b[i++] = *tt++;
	return (i);
}

void			message(t_philosophe *e, char *t, long h)
{
	int i;

	sem_wait(e->table->message);
	if (e->table->died)
	{
		i = ft_putnbr(e->table, h, 0);
		i = ft_addchar(e->table, ' ', i);
		i = ft_putnbr(e->table, e->id, i);
		i = ft_addstr(e->table, t, i);
		write(1, e->table->b, i);
		if (t[1] == 'd' || t[1] == 'f')
			e->table->died = 0;
	}
	sem_post(e->table->message);
}
