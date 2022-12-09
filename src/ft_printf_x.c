#include "../include/ft_printf.h"

int	calcul_zeros(int a, int b)
{
	if (a - b < 0)
		return (0);
	return (a - b);
}

static void	put_hexa(unsigned int nb, int base, char *res, int i)
{
	char	*base_str;

	if (base)
		base_str = "0123456789ABCDEF";
	else
		base_str = "0123456789abcdef";
	if (nb != 0)
	{
		put_hexa(nb / 16, base, res, i - 1);
		res[i] = base_str[nb % 16];
	}
}

static char	*convert_nb(unsigned int nb, int base)
{
	int				i;
	unsigned int	nbr;
	char			*res;

	i = 0;
	nbr = nb;
	while (nbr != 0 && ++i)
		nbr /= 16;
	if (i == 0)
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	put_hexa(nb, base, res, i - 1);
	res[i] = '\0';
	return (res);
}

int	ft_printf_x(va_list *argc, t_flags flags, int base)
{
	unsigned int	value;
	char			*nbr;
	int				length;
	int				spaces;
	int				zeros;

	value = va_arg(*argc, unsigned int);
	nbr = convert_nb(value, base);
	length = max(ft_strlen(nbr) + (flags.diese && value) * 2, max(flags.point
				+ (flags.diese && value) * 2,
				flags.minimal_length - 2 * (!value)));
	zeros = calcul_zeros(flags.point, ft_strlen(nbr));
	spaces = length - (ft_strlen(nbr) + (flags.diese && value) * 2) - zeros;
	while (spaces-- > 0 && !flags.tiret)
		write(1, &" 0"[flags.zero], 1);
	if (flags.diese && base && value)
		write(1, "0X", 2);
	else if (flags.diese && value)
		write(1, "0x", 2);
	while (zeros-- > 0)
		write(1, "0", 1);
	write(1, nbr, ft_strlen(nbr));
	while (spaces-- >= 0)
		write(1, " ", 1);
	return (free(nbr), length);
}
