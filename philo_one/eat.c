/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:20:39 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/01 16:40:00 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void eat(t_philosophe *p)
{
	if (p->hand)
		take_rfork(p);
	else
		take_lfork(p);
	await(p->table->opt->tte);
	unlock_fork(p);
}
