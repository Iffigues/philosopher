#ifndef P_ONE_H
#define P_ONE_H

typedef struct	s_philosophe {
	int		state;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;
}		t_philosophe;

typedef struct		s_table {
	t_opt		*opt;
	t_philosophe	*philosofe;
	pthread_mutex_t *fork;
}			t_table;



#endif
