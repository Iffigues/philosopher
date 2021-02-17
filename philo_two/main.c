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
    sem_unlink("dead");
    table->dead = sem_open("dead", O_CREAT | O_EXCL, 0644, 1);
	if (!table->dead)
		return (NULL);

    sem_unlink("message");
    table->message = sem_open("message", O_CREAT | O_EXCL, 0644,1);
	if (!table->message)
		return (NULL);

	return (table->fork);
}

static char *sem_name(int i) {
    char *t;
    char *p;
    int ii;

    ii = 0;
    p = NULL;
    t = ft_itoa(i);
    p = (char *)malloc(sizeof(char) * 3 + ft_strlen(t));
    p[0] = 'p';
    p[1] = '_';
    while (t[ii])
    {
        p[ii + 2] = t[ii];
        ii++;
     }
    p[2+ii] = 0;
    return p;
}

static t_philosophe		*make_philo(t_table *table)
{
	t_philosophe *fork;
    int i;

    i = 0;
	fork = NULL;
	if (!(fork = (t_philosophe *)malloc(sizeof(t_philosophe) * table->nb)))
		return (NULL);
    while (i < table->nb)
    {
        fork[i].id = i + 1;
        fork[i].sem_name = sem_name(i + 1);
        sem_unlink(fork[i].sem_name);
         fork[i].w = sem_open(fork[i].sem_name, O_CREAT | O_EXCL, 0644,1);
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

	table = NULL;
	if (!(table = make_tabler(table, argc, argv)))
		return (-1);
	return (0);
}
