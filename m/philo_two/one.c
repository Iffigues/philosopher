/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:26:04 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/02 14:00:08 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	free_tables(t_table *table)
{
	int i;

	i = 0;
	free(table->philosofe);
	free(table);
	return (0);
}
