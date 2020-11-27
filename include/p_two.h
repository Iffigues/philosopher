#ifndef P_TWO_H
#define P_TWO_H

#include <fcntl.h>           /* Pour les constantes O_* */
#include <sys/stat.h>        /* Pour les constantes « mode » */
#include <semaphore.h>

typedef struct	s_fork {
		
}		t_fork;

typedef struct	s_philosophe {
	int	state;
	t_fork	*r_fork;
	t_fork	*l_fork;
}		t_philosophes;

typedef struct		s_table {
	t_philosophes	*philosofe;
	t_fork		*fork;
}			t_table;



#endif
