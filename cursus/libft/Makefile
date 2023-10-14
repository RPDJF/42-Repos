.PHONY = all clean fclean re
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_atoi \
				ft_bzero \
				ft_calloc \
				ft_isalnum \
				ft_isalpha \
				ft_isascii \
				ft_isdigit \
				ft_isprint \
				ft_itoa \
				ft_memchr \
				ft_memcmp \
				ft_memcpy \
				ft_memmove \
				ft_memset \
				ft_split \
				ft_strchr \
				ft_strdup \
				ft_strjoin \
				ft_strlcat \
				ft_strlcpy \
				ft_strlen \
				ft_strmapi \
				ft_strncmp \
				ft_strnstr \
				ft_strrchr \
				ft_strtrim \
				ft_substr \
				ft_tolower \
				ft_toupper

CFILES = $(FILES:%=%.c)
OFILES = $(FILES:%=%.o)
NAME = libft.a

$(NAME): $(OFILES)
	ar -rc $(NAME) $(OFILES)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)
re: fclean all