/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:20:39 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/02 15:53:36 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int eat(t_philosophe *p)
{
	if (p->hand)
		take_rfork(p);
	else
		take_lfork(p);
	p->await = addTime(p->table->opt->ttd);
	await(p->table->opt->tte);
	unlock_fork(p);
	p->eat++;
	await(p->table->opt->tts);
	return 1;
}
