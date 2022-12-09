#include "../include/ft_printf.h"

static void	print_multi(int n, char c)
{
	while (n-- > 0)
		write(1, &c, 1);
}

static int	ft_nblen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putnb(unsigned int n, char *str, int pos)
{
	if (n > 9)
		ft_putnb(n / 10, str, pos - 1);
	str[pos] = n % 10 + '0';
}

static char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	nbr;

	if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	len = ft_nblen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_putnb(nbr, str, len - 1);
	return (str);
}

int	ft_printf_di(va_list *argc, t_flags flags)
{
	int		v;
	char	*nbr;
	int		l;
	int		spaces;
	int		zeros;

	v = va_arg(*argc, int);
	nbr = ft_itoa(v);
	l = max(ft_strlen(nbr), max(flags.point, flags.minimal_length - (v < 0)));
	zeros = calcul_zeros(flags.point, ft_strlen(nbr));
	spaces = l - ft_strlen(nbr) - zeros;
	if (v < 0 && flags.zero)
		write(1, "-", 1);
	while (spaces-- > 0 && !flags.tiret)
		write(1, &" 0"[flags.zero], 1);
	if (flags.plus && v >= 0)
		write(1, "+", 1);
	else if (flags.espace && v >= 0)
		write(1, " ", 1);
	else if (v < 0 && !flags.zero)
		write(1, "-", 1);
	print_multi(zeros, '0');
	write(1, nbr, ft_strlen(nbr));
	print_multi(spaces + 1, ' ');
	return (free(nbr), l + (flags.plus || flags.espace || v < 0));
}
