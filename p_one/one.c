#include "../include/philosopher.h"


static t_fork *make_fork(t_opt *opt) {
	t_fork *fork;

	fork = NULL;
	if (!(fork = (t_fork *)malloc(sizeof(t_fork) * opt->nb)))
		return NULL;
	pthread_mutex_init(&fork->mutex, NULL);
	return fork;
}



static t_philosophe *make_philo(t_opt *opt) {
	t_philosophe *fork;

	fork = NULL;
	if (!(fork = (t_philosophe *)malloc(sizeof(t_philosophe) * opt->nb)))
		return NULL;
	fork->l_fork = NULL;
	fork->r_fork = NULL;
	return fork;
}

static t_table *make_table(t_opt *opt) {
	t_table *table;

	table = NULL;
	if (!(table = (t_table *)malloc(sizeof(t_table) * 1)))
		return NULL;
	if (!(table->fork = make_fork(opt))) {
		free(table);
		return NULL;
	}
	if (!(table->philosofe = make_philo(opt))) {
		free(table->fork);
		free(table);
		return NULL;
	}
	table->opt = opt;
	return table;
}

void free_tables(t_table *table) {
	int i;

	i = 0;
	while (i < table->opt->nb)
		pthread_mutex_destroy(&table->fork[i++].mutex);
	free(table->fork);
	free(table->philosofe);
	free(table->opt);
	free(table);
}

void start(t_opt *opt) {
	t_table *table;

	if (!(table = make_table(opt))) {
		free(opt);
		return;
	}
	begin(table);
	free_tables(table);
}
