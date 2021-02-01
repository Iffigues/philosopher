/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:40:03 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/01 13:40:05 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void message(t_philosophe *e)
{
	pthread_mutex_lock(&e->table->message);
	pthread_mutex_unlock(&e->table->message);
}
