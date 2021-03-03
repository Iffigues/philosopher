/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:40:18 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/02 13:16:50 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

sem_t		*make_fork(t_table *table)
{
	sem_unlink("fork");
	table->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, table->nb);
	if (!table->fork)
		return (NULL);
	sem_unlink("dead");
	table->dead = sem_open("dead", O_CREAT | O_EXCL, 0644, 1);
	if (!table->dead)
		return (NULL);
	sem_unlink("message");
	table->message = sem_open("message", O_CREAT | O_EXCL, 0644, 1);
	if (!table->message)
		return (NULL);
	return (table->fork);
}

static int	opt_verif(t_table *l, int argc)
{
	if (l->nb <= 0 || l->nb > 200 || l->ttd <= 60)
		return (0);
	if (l->tts <= 60 || l->tte <= 60)
		return (0);
	if (argc == 6 && l->me <= 0)
		return (0);
	return (1);
}

t_table		*make_opt(int argc, char **argv)
{
	t_table *l;

	if (argc == 1 || argc > 6 || argc < 5)
		return (NULL);
	if (!(l = (t_table*)malloc(sizeof(t_table))))
		return (NULL);
	l->nb = ft_atoi(argv[1]);
	l->ttd = ft_atoi(argv[2]);
	l->tte = ft_atoi(argv[3]) * 1000;
	l->pair_wait = ft_atoi(argv[3]) / 2;
	l->last_imp_wait = (1.5) * ft_atoi(argv[3]);
	l->died = 1;
	l->ns = l->nb;
	l->tts = ft_atoi(argv[4]) * 1000;
	l->me = 0;
	if (argc == 6)
		l->me = ft_atoi(argv[5]);
	if (opt_verif(l, argc) == 0)
		return (NULL);
	return (l);
}
