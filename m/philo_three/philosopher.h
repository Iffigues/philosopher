/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:44:38 by bordenoy          #+#    #+#             */
/*   Updated: 2021/03/01 16:42:00 by bordenoy         ###   ########.fr       */
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

struct s_table;
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
	long			pair_wait;
	long			last_imp_wait;
}					t_table;

void				message(t_philosophe *e, char *b, long h);
void				take_fork(t_philosophe *t);
void				routine(t_table *table);
void				routine_me(t_table *table);
void				*routines(void *p);
void				sem_name(int i, char *b);
int					start_thread(t_table *table);
t_table				*make_opt(int argc, char **argv);
void				await(unsigned int i);
int					ft_atoi(const char *str);
int					ft_strlen(char *b);
long				micros(void);
void				start(t_table table);
void				m(t_philosophe *e, char *b, int h);
char				*ft_itoa(int n);
int					free_tables(t_table *table);
#endif
