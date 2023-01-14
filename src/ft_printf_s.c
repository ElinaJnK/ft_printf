/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejankovs <ejankovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:54:35 by ejankovs          #+#    #+#             */
/*   Updated: 2023/01/14 18:22:51 by ejankovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	null_string(t_flags flags)
{
	int		total_length;
	int		spaces;

	if (flags.point < 0 || flags.point >= 6)
	{
		total_length = max(6, flags.minimal_length);
		spaces = total_length - 6;
		while (spaces-- > 0 && !flags.tiret)
			write(1, " ", 1);
		write(1, "(null)", 6);
		while (spaces-- >= 0)
			write(1, " ", 1);
		return (total_length);
	}
	return (0);
}

int	ft_printf_s(va_list *argc, t_flags flags)
{
	char	*str;
	int		string_length;
	int		total_length;
	int		spaces;

	str = va_arg(*argc, char *);
	if (!str)
		return (null_string(flags));
	if (flags.point < 0)
		string_length = ft_strlen(str);
	else
		string_length = min(ft_strlen(str), flags.point);
	total_length = max(string_length, flags.minimal_length);
	spaces = total_length - string_length;
	while (spaces-- > 0 && !flags.tiret)
		write(1, " ", 1);
	write(1, str, string_length);
	while (spaces-- >= 0)
		write(1, " ", 1);
	return (total_length);
}
