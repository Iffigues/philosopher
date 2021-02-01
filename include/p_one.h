#ifndef P_ONE_H
#define P_ONE_H

struct				s_table;

typedef struct			s_philosophe {
	int			state;
	unsigned long long 	start;
	unsigned long long	await;
	int			r_fork;
	int			l_fork;
	struct			s_table *table;
}				t_philosophe;

typedef struct			s_table {
	t_opt			*opt;
	pthread_mutex_t		dead;
	pthread_mutex_t		message;
	t_philosophe		*philosofe;
	pthread_mutex_t 	*fork;
}				t_table;

int take_rfork(t_philosophe *t);
int take_lfork(t_philosophe *t);
int must_eat(t_table *table);
void *golang(void *philo);
void *r_philo(void *philo);
void *l_philo(void *philo);
int unlock_fork(t_philosophe *t);
int free_tables(t_table *table);

#endif
