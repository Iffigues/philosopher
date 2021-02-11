#include <unistd.h>

#include "../include/philosopher.h"

static int lent(uint64_t p) {
	int i;

	i = 1;
	while ((p/=10))
		i*=10;
	return i;
}

int ft_putnbr(t_table *table ,uint64_t n, int fd)
{
	int		length;

	length = lent(n);
	while (length != 0)
	{
		table->b[fd++] = '0' + (n / length);
		n = (n % length);
		length /= 10;
	}
	return fd;
}

int ft_addchar(t_table *t, char tt, int i){
	t->b[i] = tt;
	return i + 1;
}

int ft_addStr(t_table *t, char *tt, int i) {
	while(*tt)
		t->b[i++] = *tt++;
	return i;
}