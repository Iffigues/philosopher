#ifndef P_THREE_H
#define P_THREE_H

#include <fcntl.h>           /* Pour les constantes O_* */
#include <sys/stat.h>        /* Pour les constantes « mode » */
#include <semaphore.h>
#include <sys/types.h>
#include <signal.h>

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
