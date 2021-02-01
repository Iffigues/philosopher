
#include "../include/philosopher.h"
#include <unistd.h>
#include <sys/time.h>

unsigned long long	micros()
{
	struct timeval e;

	gettimeofday(&e, NULL);
	return ((e.tv_usec) / 1000. + (e.tv_sec) * 1000.);
}
