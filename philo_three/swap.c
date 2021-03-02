/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:02:47 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/02 17:19:10 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define SIZE 5

void ft_swap(int *y,  int o)
{
	int i;
	int u;
	int j;

	j = o;
	if (o & 1)
		o--;
	u = 0;
	i = 0;
	while (i < o)
	{
		y[u] = i + 1;
		u++;
		i += 2;
	}
	i = 1;
	while (i < o) 
	{
		y[u] = i + 1;
		u++;
		i +=2;
	}
}

int main()
{
	int i[SIZE] = {1,2,3,4,5};
	ft_swap(i, SIZE);
	for (int o = 0; o < SIZE; o++) {
		printf("%d\n", i[o]);
	}
}
