/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:44:38 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/26 17:03:52 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>
# if defined(DIR)
#  if DIR == 2
#   include "./p_two.h"
#  elif DIR == 1
#   include "./p_one.h"
#  elif DIR == 3
#   include "./p_three.h"
#  endif
# else
#  include "./p_one.h"
# endif

int		start_thread(t_table *table);
t_table	*make_opt(int argc, char **argv);
void	await(unsigned int i);
int		ft_atoi(const char *str);
int		ft_strlen(char *b);
long	micros(void);
void	start(t_table table);
void	m(t_philosophe *e, char *b, int h);
char	*ft_itoa(int n);
#endif
