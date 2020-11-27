#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>

typedef struct s_opt {
	int nb;
	int ttd;
	int tte;
	int tts;
	int me;
} t_opt;


t_opt  *make_opt(int argc, char **argv);
int	ft_atoi(const char *str);

#if defined(DIR)
#if DIR == 2
#include "./p_two.h"
#elif DIR == 1
#include "./p_one.h"
#elif DIR == 3
#include "./p_three.h"
#endif
#else
#include "./p_one.h"
#endif
#endif
