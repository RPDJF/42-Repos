.PHONY = all clean fclean re bonus
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
				ft_putchar_fd \
				ft_putendl_fd \
				ft_putnbr_fd \
				ft_putstr_fd \
				ft_split \
				ft_strchr \
				ft_strdup \
				ft_striteri \
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

BONUS_FILES = ft_lstnew \

CFILES = $(FILES:%=%.c)
OFILES = $(FILES:%=%.o)
BONUS_CFILES = $(BONUS_FILES:%=%.c)
BONUS_OFILES = $(BONUS_FILES:%=%.o)
NAME = libft.a

$(NAME): $(OFILES)
	ar -rc $(NAME) $(OFILES)

all: $(NAME)

bonus: $(BONUS_OFILES) $(OFILES)
	ar -rc $(NAME) $(BONUS_OFILES) $(OFILES)

clean:
	rm -f $(OFILES) $(BONUS_OFILES)

fclean: clean
	rm -f $(NAME)
re: fclean all