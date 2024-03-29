/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejankovs <ejankovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:54:21 by ejankovs          #+#    #+#             */
/*   Updated: 2022/12/19 08:54:22 by ejankovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_c(va_list *argc, t_flags flags)
{
	unsigned char	c;
	int				length;
	int				spaces;

	c = (unsigned char)va_arg(*argc, int);
	length = max(flags.minimal_length, 1);
	spaces = length - 1;
	while (spaces-- > 0 && !flags.tiret)
		write(1, " ", 1);
	write(1, &c, 1);
	while (spaces-- >= 0)
		write(1, " ", 1);
	return (length);
}
