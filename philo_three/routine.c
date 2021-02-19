#include "../include/philosopher.h"

static void	dier(t_philosophe *table)
{
	message(table, " died\n", micros() - table->table->start);
	sem_post(table->w);
	sem_post(table->table->dead);
}

void		*routines(void *pp)
{
    t_philosophe *p;
    p = (t_philosophe*)pp;
    
    p->await = micros() +  p->table->ttd;
    while (1) {
        sem_wait(p->w);
	    if (micros() > p->await) {
	        dier(p);
            sem_post(p->w);
            return NULL;
        }
		sem_post(p->w);
    }
    return NULL;
}
