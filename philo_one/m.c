/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:40:03 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 16:25:12 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static int cInt(int y)
{
	int u;

	u = 1;
	while ((y = y/ 10))
		u++;
	return (u);
}



void m(t_philosophe *e, char *t, int d)
{
	int i;
	int y;
	int ee;
	char *b;

	b = NULL;
	ee = ft_strlen(t);
	i = cInt(d);
	i = i + cInt(e->id);
	y = 0;
	if (!(b = (char *)malloc(sizeof(char) * (ee + i + 1))))
		return;
	
}
