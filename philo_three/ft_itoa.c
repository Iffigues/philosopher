/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:06:09 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/26 15:07:25 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosopher.h"

static	int		len(int n)
{
	int	b;

	b = 1 + (n < 0);
	while ((n /= 10))
		b++;
	return (b);
}

static char	*ft_putnbr(char *table, int n)
{
	int	length;
	int nn;
	int fd;

	fd = 0;
	length = 1;
	nn = n;
	while ((nn /= 10))
		length *= 10;
	while (length != 0)
	{
		table[fd++] = '0' + (n / length);
		n = (n % length);
		length /= 10;
	}
	table[fd] = 0;
	return (table);
}

char			*ft_itoa(int n)
{
	char	*b;
	int		i;
	int		c;

	c = 0;
	i = len(n);
	if ((b = (char *)malloc(sizeof(char) * (i + 1))))
	{
		return (ft_putnbr(b, n));
	}
	return ((void *)0);
}
