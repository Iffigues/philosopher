/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:23:45 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/01 15:49:59 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"
#include <unistd.h>
#include <sys/time.h>

unsigned long long	micros(void)
{
	struct timeval e;

	gettimeofday(&e, NULL);
	return ((e.tv_usec) / 1000. + (e.tv_sec) * 1000.);
}

void await(int y)
{
	unsigned long long h;

	h = micros() + (unsigned long long)y;
}