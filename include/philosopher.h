#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

typedef struct s_opt {
	int nb;
	int ttd;
	int tte;
	int tts;
	int me;
} 	t_opt;

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

int					begin(t_table *table);
t_opt				*make_opt(int argc, char **argv);
void				await(int i);
int					ft_atoi(const char *str);
int					ft_strlen(char *b);
void				start(t_opt *opt);
unsigned long long	micros(void);
unsigned long long	addTime(int y);
void				message(t_philosophe *e, char *b);
void				m(t_philosophe *e, char *b, int h);

#endif
