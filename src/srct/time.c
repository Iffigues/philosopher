/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:23:45 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/02 14:42:05 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"
#include <unistd.h>
#include <sys/time.h>

long	micros(void)
{
	struct timeval e;

	gettimeofday(&e, NULL);
	return (e.tv_sec * 1000L + e.tv_usec / 1000L);
}

void	await(unsigned int y)
{
	struct timeval h;
	struct timeval j;

	gettimeofday(&h, NULL);
	while (1)
	{
		usleep(1);
		gettimeofday(&j, NULL);
		if ((size_t)(((size_t)(j.tv_sec - h.tv_sec)) * 1000000 +
((size_t)(j.tv_usec - h.tv_usec))) > y)
			return ;
	}
	return ;
}
