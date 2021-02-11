/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:23:45 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 14:16:19 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"
#include <unistd.h>
#include <sys/time.h>

uint64_t	micros(void)
{
	struct timeval e;

	gettimeofday(&e, NULL);
	//return ((e.tv_sec * (uint64_t)1000) + (e.tv_usec / 1000));
	return ((e.tv_usec) / 1000. + (e.tv_sec) * 1000.);
}

void await(unsigned int y)
{
	struct timeval h;
	struct timeval j;

	gettimeofday(&h, NULL);
	while (1)
	{
		usleep(50);
		gettimeofday(&j, NULL);
		if ((size_t)(((size_t)(j.tv_sec - h.tv_sec)) * 1000000 +
((size_t)(j.tv_usec - h.tv_usec))) > y)
		return;
	}
	return ;
}
