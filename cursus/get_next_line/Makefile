.PHONY = all clean fclean re
CC = gcc
#CFLAGS = -Wall -Wextra -Werror

FILES =	get_next_line
LIBFILES = get_next_line_utils

CLIBFILES = $(LIBFILES:%=%.c)
CFILES = $(FILES:%=%.c) $(CLIBFILES)
OFILES = $(LIBFILES:%=%.o)

LIBNAME = get_next_line_utils.a
NAME = get_next_line.out 

$(NAME): $(OFILES)
	ar -rc $(LIBNAME) $(OFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME) -L. $(LIBNAME)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME) $(LIBNAME)

re: fclean all
