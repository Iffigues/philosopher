#ifndef P_ONE_H
#define P_ONE_H

struct s_table;

typedef struct			s_philosophe {
	struct s_table	*table;
	int					id;
	int			position;
	int					eat;
	int			eating;
	int 				hand;
	uint64_t	await;
	int			r_fork;
	pthread_mutex_t		w;
	int			l_fork;
}				t_philosophe;

typedef struct			s_table {
	pthread_mutex_t		dead;
	pthread_mutex_t		message;
	uint64_t 	start;
	t_philosophe		*philosofe;
	pthread_mutex_t 	*fork;
	int nb;
	uint64_t ttd;
	uint64_t tte;
	uint64_t tts;
	int me;
}				t_table;

void take_fork(t_philosophe *t);
int must_eat(t_table table);
int eat(t_philosophe *e);
void *health(void *philo);
void *b_philo(void *philo);
void unlock_fork(t_philosophe *t);
int free_tables(t_table *table);

#endif
