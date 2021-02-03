#include <unistd.h>

static int ft_putchar(char c)
{
	return  write(1, &c, 1);
}

void  ft_putnbr(int h)
{
	int s;

	s =10;
	while (s < h)
		s = s * 10;
	if (s > h)
		s = s / 10;
	while (s > 1)
	{
		ft_putchar((h / s) + '0');
		h = h % s;
		s = s / 10;
	}
	ft_putchar((h / s) + '0');
}
