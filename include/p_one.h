#ifndef P_ONE_H
#define P_ONE_H

typedef struct	s_fork {
		
}		t_fork;

typedef struct	s_philosophe {
	int	state;
	t_fork	*r_fork;
	t_fork	*l_fork;
}		t_philosophe;

typedef struct		s_table {
	t_opt		*opt;
	t_philosophe	*philosofe;
	t_fork		*fork;
}			t_table;



#endif
