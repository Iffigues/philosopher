/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:39:32 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/01 14:39:33 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static pthread_mutex_t	*make_fork(t_opt *opt, t_table *table) {
	int i;

	i = 0;
	if (!(table->fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * opt->nb)))
		return NULL;
	while (i < opt->nb)
		if ((pthread_mutex_init(&table->fork[i++], NULL)) != 0)
		{
			free(table->fork);
			return NULL;
		}
	return table->fork;
}



static t_philosophe *make_philo(t_opt *opt) {
	t_philosophe *fork;

	fork = NULL;
	if (!(fork = (t_philosophe *)malloc(sizeof(t_philosophe) * opt->nb)))
		return NULL;
	fork->eat = 0;
	return fork;
}

static t_table *make_table(t_opt *opt) {
	t_table *table;
	int i;

	table = NULL;
	if (!(table = (t_table *)malloc(sizeof(t_table) * 1)))
		return NULL;
	if (!(table->fork = make_fork(opt, table))) {
		free(table);
		return NULL;
	}
	i = pthread_mutex_init(&table->dead, NULL);
	if (!(table->philosofe = make_philo(opt)) || i != 0) {
		free(table->fork);
		free(table);
		return NULL;
	}
	table->opt = opt;
	return table;
}

static int freeze(t_opt *opt)
{
	free(opt);
	return (0);
}

int main(int argc, char **argv) {
	t_opt *opt;
	t_table *table;
	
	if (!(opt = make_opt(argc, argv)))
		return write(1, "bad option", 10) & 1;
	if (!(table = make_table(opt)))
		return (freeze(opt));
	if (begin(table))
		return 1;
	pthread_mutex_lock(&table->dead);
	pthread_mutex_lock(&table->dead);
	return (free_tables(table));
}
