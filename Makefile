NAME = libftprintf.a
CC = gcc -c
INCLUDE = ft_printf.h
FLAGS = -Wall -Wextra -Werror
AR = ar rc

SRC = ft_printf.c print_nmb.c print_str.c print_nmb_u.c print_nmb_hexa.c print_pointer.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC)  $(FLAGS) $(SRC)
	$(AR)  $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

# -c  - Directs the compiler to suppress linking with ld(1) and to produce a .o file for each source file
# 
# The - ar - command maintains the indexed libraries used by the linkage editor. The ar command combines one 
# or more named files into a single archive file written in ar archive format. When the ar command creates 
# a library, it creates headers in a transportable format; when it creates or updates a library, it rebuilds 
# the symbol table. See the ar file format entry for information on the format and structure of indexed 
# archives and symbol tables.
# 
# A phony target is one that is not really the name of a file; rather it is just a name for a recipe to be 
# executed when you make an explicit request.