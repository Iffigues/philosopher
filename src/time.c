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
	return ((e.tv_sec * (uint64_t)1000) + (e.tv_usec / 1000));
	return ((e.tv_usec) / 1000. + (e.tv_sec) * 1000.);
}

/*unsigned long long addTime(int y)
{
	return (micros() + (unsigned long long) y);
}*/

void await(int y)
{
	unsigned long long h;
	unsigned long long j;

	h = micros() + (unsigned long long)y;
	while (1)
	{
		usleep(50);
		j = micros();
		if (j >= h)
			return;
	}
}
