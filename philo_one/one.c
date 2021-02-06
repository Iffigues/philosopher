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

int	free_tables(t_table table)
{
	int i;
	i = 0;
	while (i < table.nb)
		pthread_mutex_destroy(&table.fork[i++]);
	free(table.fork);
	free(table.philosofe);
	return (0);
}
