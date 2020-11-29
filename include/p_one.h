#ifndef P_ONE_H
#define P_ONE_H

struct s_table;

typedef struct	s_philosophe {
	int	state;
	int	r_fork;
	int	l_fork;
	struct	s_table *table;
}		t_philosophe;

typedef struct		s_table {
	t_opt		*opt;
	t_philosophe	*philosofe;
	pthread_mutex_t *fork;
}			t_table;

int take_rfork(t_philosophe *t);
int take_lfork(t_philosophe *t);
int unlock_fork(t_philosophe *t);


#endif
