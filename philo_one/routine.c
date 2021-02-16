#include "../include/philosopher.h"

static void	dier(t_table *table, int i)
{
	message(&table->philosofe[i], " died\n", micros() - table->start);
	pthread_mutex_unlock(&table->philosofe[i].w);
	pthread_mutex_unlock(&table->dead);
}

void		routine_me(t_table *table)
{
	int i;
	int c;

	while (table->died)
	{
		c = 1;
		i = 0;
		while (i < table->ns)
		{
			pthread_mutex_lock(&table->philosofe[i].w);
			if (table->philosofe[i].eat < table->me)
				c = 0;
			if (micros() > table->philosofe[i].await)
			{
				dier(table, i);
				return ;
			}
			pthread_mutex_unlock(&table->philosofe[i].w);
			i++;
		}
		if (c)
		{
			message(&table->philosofe[0], " full\n", micros() - table->start);
			pthread_mutex_unlock(&table->dead);
			return ;
		}
	}
}

void		routine(t_table *table)
{
	int i;

	while (table->died)
	{
		i = 0;
		while (i < table->ns)
		{
			pthread_mutex_lock(&table->philosofe[i].w);
			if (micros() > table->philosofe[i].await)
			{
				dier(table, i);
				return ;
			}
			pthread_mutex_unlock(&table->philosofe[i].w);
			i++;
		}
	}
}
