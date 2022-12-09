#include "../include/ft_printf.h"

int	ft_is_printable(char c)
{
	if (c == 'd' || c == 'i'
		|| c == 'u' || c == 'p'
		|| c == 'c' || c == 's'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_flags(const char **format, t_flags *flags)
{
	while (format && *format && **format && !ft_is_printable(**format))
	{
		if (**format == '.')
		{
			++*format;
			flags->point = ft_atoi_deluxe(format);
		}
		else if (**format == '#')
			flags->diese = 1;
		else if (**format == ' ')
			flags->espace = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == '0')
			flags->zero = 1;
		else if (**format == '-')
			flags->tiret = 1;
		else if (**format >= '0' && **format <= '9')
			flags->minimal_length = ft_atoi_deluxe(format);
		++*format;
	}
	flags->type = **format;
	++*format;
}

int	ft_format(va_list *argc, const char **format)
{
	t_flags	flags;

	ft_initialize_flags(&flags);
	ft_flags(format, &flags);
	if (flags.type == 'd' || flags.type == 'i')
		return (ft_printf_di(argc, flags));
	if (flags.type == 'u')
		return (ft_printf_u(argc, flags));
	if (flags.type == 'c')
		return (ft_printf_c(argc, flags));
	if (flags.type == 's')
		return (ft_printf_s(argc, flags));
	if (flags.type == 'p')
		return (ft_printf_p(argc, flags));
	if (flags.type == 'x')
		return (ft_printf_x(argc, flags, 0));
	if (flags.type == 'X')
		return (ft_printf_x(argc, flags, 1));
	if (flags.type == '%')
		return (write(1, "%%", 1), 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		nbchar;
	char	c;

	nbchar = 0;
	va_start(args, format);
	while (*format)
	{
		c = *format;
		++format;
		if (c == '%')
			nbchar += ft_format(&args, &format);
		else
		{
			write(1, &c, 1);
			nbchar++;
		}
	}
	va_end(args);
	return (nbchar);
}
