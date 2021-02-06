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

static pthread_mutex_t	*make_fork(t_table table) {
	int i;

	i = 0;
	if (!(table->fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * table->nb)))
		return NULL;
	while (i < opt->nb)
		if ((pthread_mutex_init(&table->fork[i++], NULL)) != 0)
		{
			free(table->fork);
			return NULL;
		}
	return table->fork;
}



static t_philosophe *make_philo(t_table table) {
	t_philosophe *fork;

	fork = NULL;
	if (!(fork = (t_philosophe *)malloc(sizeof(t_philosophe) * opt->nb)))
		return NULL;
	return fork;
}

static t_table *make_table(t_table table) {
	int i;

	if (!(table->fork = make_fork(table)))
		return NULL;
	i = pthread_mutex_init(&table->dead, NULL);
	if (!(table->philosofe = make_philo(table)) || i != 0) {
		free(table->fork);
		return NULL;
	}
	return table;
}

int main(int argc, char **argv) {
	t_table *table;
	
	if (!(table = make_opt(argc, argv, &table)))
		return write(1, "bad option", 10) & 1;
	if (!(table = make_table(table)))
		return -1;
	if (begin(table))
		return 1;
	pthread_mutex_lock(&table->dead);
	pthread_mutex_unlock(&table->dead);
	return (free_tables(table));
}
