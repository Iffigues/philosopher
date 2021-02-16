/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:26:04 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/01 15:00:04 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	free_tables(t_table *table)
{
	int i;
	
	i = 0;
	while (i < table->ns)
	{
		pthread_mutex_destroy(&table->fork[i]);
		pthread_mutex_destroy(&table->philosofe[i++].w);
	}
	free(table->fork);
	pthread_mutex_destroy(&table->dead);
	pthread_mutex_destroy(&table->message);
	free(table->philosofe);
	free(table);
	return (0);
}
