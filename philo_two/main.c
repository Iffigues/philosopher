/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:39:32 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 16:16:17 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static sem_t	*make_fork(t_table *table)
{
    sem_unlink("fork");
	table->fork = sem_open("fork", O_CREAT | O_EXCL, 0644,table->nb);
	if (!table->fork)
		return (NULL);
	return (table->fork);
}

static t_philosophe		*make_philo(t_table *table)
{
	t_philosophe *fork;

	fork = NULL;
	if (!(fork = (t_philosophe *)malloc(sizeof(t_philosophe) * table->nb)))
		return (NULL);
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

	table = NULL;
	if (!(table = make_tabler(table, argc, argv)))
		return (-1);
	return (0);
}
