#ifndef P_TWO_H
#define P_TWO_H

typedef struct		s_philosophe {
	struct s_table	*table;
	int				id;
    char            *sem_name;
	int				position;
	int				eat;
	long			await;
    pid_t			pid;
	sem_t           *w;
sem_t           *start;
}					t_philosophe;

typedef struct			s_table
{
	sem_t			    *dead;
	sem_t			    *message;
    sem_t               *fork;
    sem_t               *eat;
	int					died;
	char				b[100];
	long				start;
	t_philosophe		*philosofe;
	int					nb;
	long				ttd;
	long				tte;
	long				tts;
	int					me;
	int					pair_wait;
	int					last_imp_wait;
}						t_table;

void		message(t_philosophe *e, char *b, long h);
void take_fork(t_philosophe *t);
void		routine(t_table *table);
void		routine_me(t_table *table);
void		*routines(void *p);
#endif
