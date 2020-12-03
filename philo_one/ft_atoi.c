static	int	good(int a, char c, int d)
{
	if (214748364 == a)
	{
		if (d < 0 && c > '8')
			return (0);
		if (d > 0 && c > '7')
			return (-1);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int nbr;
	int s;

	s = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		s = ',' - *str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((good(nbr, *str, s) != 1))
			return (good(nbr, *str, s));
		nbr = (nbr * 10 + *str++ - '0');
	}
	return (nbr * s);
}
