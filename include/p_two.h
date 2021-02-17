#ifndef P_TWO_H
#define P_TWO_H

#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>


typedef struct		s_philosophe {
	struct s_table	*table;
	int				id;
    char            *sem_name;
	int				position;
	int				eat;
	long			await;
	sem_t           *w;
}					t_philosophe;

typedef struct			s_table {
	sem_t			*dead;
	sem_t			*message;
    sem_t           *fork;
	int					died;
	char				b[100];
	long				start;
	t_philosophe		*philosofe;
	int					nb;
	int ns;
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
#endif
