#include "../include/ft_printf.h"

int	ft_printf_s(va_list *argc, t_flags flags)
{
	char	*str;
	int		string_length;
	int		total_length;
	int		spaces;

	str = va_arg(*argc, char *);
	if (!str)
		return (write(1, "(null)", 6), 6);
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
