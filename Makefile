CC			= gcc

NAME		= libftprintf.a

CFLAGS		= -Wall -Wextra -Werror

INCLUDE		= include

SRC_DIR		= src

OBJ_DIR		= obj

RM			= rm -f

SOURCES =	ft_printf_x.c		\
			ft_printf_s.c		\
			ft_printf_c.c		\
			ft_printf_p.c		\
			ft_printf_di.c		\
			ft_printf_u.c		\
			ft_printf.c			\
			ft_printf_utils.c	\


SRC	=	$(addprefix $(SRC_DIR)/,$(SOURCES))
#$(info $$SRC is [${SRC}])
OBJS =	$(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))
#$(info $$OBJS is [${OBJS}])

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)/ft_printf.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $@ -c $<

bonus: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re