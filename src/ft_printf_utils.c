/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejankovs <ejankovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:54:47 by ejankovs          #+#    #+#             */
/*   Updated: 2022/12/19 08:54:48 by ejankovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_atoi_deluxe(const char **str)
{
	int				sign;
	unsigned int	nb;

	nb = 0;
	sign = 1;
	while (**str && (**str == ' ' || (**str >= 9 && **str <= 13)))
		++*str;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		++*str;
	}
	while (**str && **str >= '0' && **str <= '9')
	{
		nb = nb * 10 + **str - '0';
		++*str;
	}
	return (--*str, (int)(sign * nb));
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		++len;
	return (len);
}

void	ft_initialize_flags(t_flags *flags)
{
	flags->type = '\0';
	flags->point = -1;
	flags->diese = 0;
	flags->espace = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->tiret = 0;
	flags->minimal_length = -1;
}
