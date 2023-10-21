.PHONY = all clean fclean re bonus homemade
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

BONUS_FILES =	ft_lstadd_back \
				ft_lstadd_front \
				ft_lstclear \
				ft_lstdelone \
				ft_lstiter \
				ft_lstlast \
				ft_lstmap \
				ft_lstnew \
				ft_lstsize \

HOMEMADE_FILES = ft_itoa_base \
				ft_itoa_unsigned \
				ft_exallocf \
				ft_get_next_line \
				ft_memncat \
				ft_memsuperclear \
				ft_memtostr \

CFILES = $(FILES:%=%.c)
OFILES = $(FILES:%=%.o)
BONUS_CFILES = $(BONUS_FILES:%=%.c)
BONUS_OFILES = $(BONUS_FILES:%=%.o)
HOMEMADE_CFILES = $(HOMEMADE_FILES:%=%.c)
HOMEMADE_OFILES = $(HOMEMADE_FILES:%=%.o)
NAME = libft.a

all: homemade

$(NAME): $(OFILES)
	ar -rc $(NAME) $(OFILES)

bonus: $(BONUS_OFILES) $(OFILES)
	ar -rc $(NAME) $(BONUS_OFILES) $(OFILES)

homemade:	$(HOMEMADE_OFILES) $(OFILES) $(BONUS_OFILES)
	ar -rc $(NAME) $(BONUES_OFILES) $(OFILES) $(HOMEMADE_OFILES)

clean:
	rm -f $(OFILES) $(BONUS_OFILES) $(HOMEMADE_OFILES)

fclean: clean
	rm -f $(NAME)
re: fclean all