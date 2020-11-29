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



#endif
