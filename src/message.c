/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:40:03 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 16:26:40 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void message(t_philosophe *e, char *t)
{
	int i;

	pthread_mutex_lock(&e->table->message);
		i = ft_putnbr(e->table, 0,0);
		i = ft_addchar(e->table,' ',i);
		i = ft_putnbr(e->table, e->id, i);
		i = ft_addStr(e->table, t, i);
		write(1, e->table->b, i);
	pthread_mutex_unlock(&e->table->message);
}
