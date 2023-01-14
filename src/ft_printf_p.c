/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejankovs <ejankovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:54:28 by ejankovs          #+#    #+#             */
/*   Updated: 2022/12/19 16:28:43 by ejankovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	nil_ptr(t_flags flags)
{
	int		total_length;
	int		spaces;

	if (flags.point < 0 || flags.point >= 5)
	{
		total_length = max(5, flags.minimal_length);
		spaces = total_length - 5;
		while (spaces-- > 0 && !flags.tiret)
			write(1, " ", 1);
		write(1, "(nil)", 5);
		while (spaces-- >= 0)
			write(1, " ", 1);
		return (total_length);
	}
	return (0);
}

static void	put_hexa(size_t nb, char *res, int i)
{
	if (nb != 0)
	{
		put_hexa(nb / 16, res, i - 1);
		res[i] = "0123456789abcdef"[nb % 16];
	}
}

static char	*convert_nb(size_t nb)
{
	int		i;
	size_t	nbr;
	char	*res;

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
	put_hexa(nb, res, i - 1);
	res[i] = '\0';
	return (res);
}

int	ft_printf_p(va_list *argc, t_flags flags)
{
	size_t	value;
	char	*nbr;
	int		length;
	int		spaces;

	value = va_arg(*argc, size_t);
	if (!value)
		return (nil_ptr(flags));
	nbr = convert_nb(value);
	length = max(ft_strlen(nbr) + 2, flags.minimal_length);
	spaces = length - (ft_strlen(nbr) + 2);
	while (spaces-- > 0 && !flags.tiret)
		write(1, " ", 1);
	write(1, "0x", 2);
	write(1, nbr, ft_strlen(nbr));
	while (spaces-- >= 0)
		write(1, " ", 1);
	return (free(nbr), length);
}
