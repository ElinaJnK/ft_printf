/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejankovs <ejankovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:53:34 by ejankovs          #+#    #+#             */
/*   Updated: 2023/01/17 16:10:59 by ejankovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	pm(int n, char c)
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

static char	*ft_itoa(int n, t_flags flags)
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
	if (n == 0 && flags.point == 0)
		return (str[0] = '\0', str);
	str[len] = '\0';
	ft_putnb(nbr, str, len - 1);
	return (str);
}

int	ft_printf_di(va_list *argc, t_flags f)
{
	int		v;
	char	*nbr;
	int		l;
	int		spaces;
	int		zeros;

	v = va_arg(*argc, int);
	nbr = ft_itoa(v, f);
	l = max(ft_strlen(nbr), max(f.point, f.minimal_length
				- (v < 0) - (v > 0 && (f.espace || f.plus))));
	zeros = calcul_zeros(f.point, ft_strlen(nbr));
	spaces = l - ft_strlen(nbr) - zeros;
	if (v < 0 && f.zero)
		write(1, "-", 1);
	while (spaces-- > 0 && !f.tiret)
		write(1, &" 0"[f.zero - (!v && !f.point && f.zero)], 1);
	if (f.plus && v >= 0)
		write(1, "+", 1);
	else if (f.espace && v >= 0)
		write(1, " ", 1);
	else if (v < 0 && !f.zero)
		write(1, "-", 1);
	pm(zeros, '0');
	write(1, nbr, ft_strlen(nbr));
	return (pm(spaces + 1, ' '), free(nbr), l + (f.plus || f.espace || v < 0));
}
