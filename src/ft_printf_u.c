#include "../include/ft_printf.h"

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

static char	*ft_itoa(unsigned int n)
{
	char			*str;
	int				len;

	len = ft_nblen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_putnb(n, str, len - 1);
	return (str);
}

int	ft_printf_u(va_list *argc, t_flags flags)
{
	unsigned int	value;
	char			*nbr;
	int				length;
	int				spaces;
	int				zeros;

	value = va_arg(*argc, int);
	nbr = ft_itoa(value);
	length = max(ft_strlen(nbr), max(flags.point, flags.minimal_length));
	zeros = calcul_zeros(flags.point, ft_strlen(nbr));
	spaces = length - ft_strlen(nbr) - zeros;
	while (spaces-- > 0 && !flags.tiret)
		write(1, &" 0"[flags.zero], 1);
	while (zeros-- > 0)
		write(1, "0", 1);
	write(1, nbr, ft_strlen(nbr));
	while (spaces-- >= 0)
		write(1, " ", 1);
	return (free(nbr), length);
}
