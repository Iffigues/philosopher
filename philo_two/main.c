/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:39:32 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/01 16:58:32 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	sem_name(int i, char *b)
{
	char	*t;
	int		k;

	k = 0;
	t = ft_itoa(i);
	b[k++] = 'p';
	b[k++] = '_';
	while (*t)
		b[k++] = *t++;
	b[k] = 0;
}

static t_philosophe	*make_philo(t_table *table)
{
	t_philosophe	*fork;
	int				i;
	char			m[6];

	i = 0;
	fork = NULL;
	if (!(fork = (t_philosophe *)malloc(sizeof(t_philosophe) * table->nb)))
		return (NULL);
	while (i < table->nb)
	{
		fork[i].id = i + 1;
		sem_name(i + 1, m);
		sem_unlink(m);
		fork[i].w = sem_open(m, O_CREAT | O_EXCL, 0644, 1);
		fork[i].table = table;
		fork[i].eat = 0;
		i++;
	}
	return (fork);
}

static int				make_table(t_table *table)
{
	if (!(table->fork = make_fork(table)))
	{
		free(table);
		return (0);
	}
	if (!(table->philosofe = make_philo(table)))
	{
		free(table->fork);
		return (0);
	}
	return (1);
}

static t_table			*make_tabler(t_table *table, int argc, char **argv)
{
	if (!(table = (make_opt(argc, argv))))
	{
		write(1, "bad option", 10);
		return (NULL);
	}
	if (!(make_table(table)))
		return (NULL);
	if (start_thread(table))
		return (NULL);
	return (table);
}

int						main(int argc, char **argv)
{
	t_table	*table;
	int		h;

	table = NULL;
	if (!(table = make_tabler(table, argc, argv)))
		return (-1);
	if (table->me)
		routine_me(table);
	else
		routine(table);
	sem_wait(table->dead);
	sem_post(table->dead);
	while (table->nb)
	{
		h = 0;
		while (h < table->ns)
		{
			sem_post(table->fork);
			h++;
		}
	}
	return (0);
}
