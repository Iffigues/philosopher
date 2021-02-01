#include "../include/philosopher.h"

int free_tables(t_table *table) {
//	int i;

//	i = 0;
	//while (i < table->opt->nb)
	//	pthread_mutex_destroy(&table->fork[i++].mutex);
	free(table->fork);
	free(table->philosofe);
	free(table->opt);
	free(table);
	return 0;
}
