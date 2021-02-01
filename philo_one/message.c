#include "../include/philosopher.h"

void message(t_philosophe *e)
{
	pthread_mutex_lock(&e->table->message);
	pthread_mutex_unlock(&e->table->message);
}
