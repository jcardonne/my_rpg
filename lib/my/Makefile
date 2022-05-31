##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## Makefile
##

SRC    =    $(wildcard *.c) \
	  my_printf/my_printf.c \
	  my_printf/struct_utils.c \
	  my_printf/type_base.c \
	  my_printf/type_char.c \
	  my_printf/type_num.c \
	  my_printf/type_utils.c \
	  my_printf/printf_handling.c \
	  my_printf/type_float.c \
	  my_printf/str_utils.c \
	  my_printf/type_long_base.c \
	  my_printf/my_fprintf.c

OBJ	=	$(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
		cp my.h ../../include

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
