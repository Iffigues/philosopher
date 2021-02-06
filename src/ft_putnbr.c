#include <unistd.h>

/*static int ft_putchar(char c)
{
	return  write(1, &c, 1);
}*/

/*void  ft_putnbr(int h)
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
}*/


void
	ft_putnbr(uint64_t n, int fd)
{
	char	str[13];
	int		length;

	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + (n % 10);
		n = (n / 10);
	}
	if (length > 0)
		length--;
	while (length >= 0)
		write(fd, &str[length--], 1);
}
