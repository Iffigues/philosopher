/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_three.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:35:01 by bordenoy          #+#    #+#             */
/*   Updated: 2021/02/26 16:40:16 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_THREE_H
# define P_THREE_H

typedef struct		s_philosophe
{
	struct s_table	*table;
	int				id;
	int				position;
	int				eat;
	long			await;
	pid_t			pid;
	sem_t			*w;
	sem_t			*start;
}					t_philosophe;

typedef struct		s_table
{
	sem_t			*dead;
	sem_t			*message;
	sem_t			*fork;
	sem_t			*eat;
	int				died;
	char			b[100];
	long			start;
	t_philosophe	*philosofe;
	int				nb;
	long			ttd;
	long			tte;
	long			tts;
	int				me;
	long				pair_wait;
	long				last_imp_wait;
}					t_table;

void				message(t_philosophe *e, char *b, long h);
void				take_fork(t_philosophe *t);
void				routine(t_table *table);
void				routine_me(t_table *table);
void				*routines(void *p);
void				sem_name(int i, char *b);
#endif
