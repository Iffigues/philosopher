#include "../include/philosopher.h"
#include <stdio.h>

static int opt_verif(t_opt *l, int argc) {
	if (l->nb <= 0 || l->ttd <= 0 || l->tts <= 0 || l->tte <= 0)
		return 0;
	if (argc == 6 && l->me <= 0)
		return 0;
	return (1);
}

t_opt *make_opt(int argc, char **argv) {
	t_opt *l;

	if (argc == 1 || argc > 6 || argc < 5)
		return NULL;
	if (!(l = (t_opt *)malloc(sizeof(t_opt) * 1)))
		return NULL;
	l->nb = ft_atoi(argv[1]);
	l->ttd = ft_atoi(argv[2]);
	l->tte = ft_atoi(argv[3]);
	l->tts = ft_atoi(argv[4]);
	l->me = 0;
	if (argc == 6)
		l->me = ft_atoi(argv[5]);
	if (opt_verif(l, argc) == 0) {
		free(l);
		l = NULL;
	}
	return l;
}
