#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//# include <assert.h>
# include <stdarg.h>
//# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	char	type;
	int		point;
	int		diese;
	int		espace;
	int		plus;
	int		zero;
	int		tiret;
	int		minimal_length;
}			t_flags;

int		ft_printf(const char *format, ...);
int		ft_format(va_list *argc, const char **format);
int		ft_is_printable(char c);
int		ft_atoi_deluxe(const char **str);
int		min(int a, int b);
int		max(int a, int b);
int		calcul_zeros(int a, int b);
int		ft_printf_x(va_list *argc, t_flags flags, int base);
int		ft_printf_p(va_list *argc, t_flags flags);
int		ft_printf_s(va_list *argc, t_flags flags);
int		ft_printf_c(va_list *argc, t_flags flags);
int		ft_printf_di(va_list *argc, t_flags flags);
int		ft_printf_u(va_list *argc, t_flags flags);
size_t	ft_strlen(char *s);
void	ft_initialize_flags(t_flags *flags);
void	ft_flags(const char **format, t_flags *flags);
#endif