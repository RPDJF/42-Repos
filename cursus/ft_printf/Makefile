.PHONY = all clean fclean re
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_FILES = ft_atoi \
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
				ft_toupper \
				ft_lstadd_back \
				ft_lstadd_front \
				ft_lstclear \
				ft_lstdelone \
				ft_lstiter \
				ft_lstlast \
				ft_lstmap \
				ft_lstnew \
				ft_lstsize \
				ft_itoa_base \
				ft_itoa_unsigned \
				ft_exallocf \
				ft_get_next_line \
				ft_memncat \
				ft_memsuperclear \
				ft_memtostr \

LIBFT_SRC = $(LIBFT_FILES:%=libs/%)
SRC = ft_printf \
		utils/ft_printf_utils
LIBFT_OFILES = $(LIBFT_SRC:%=%.o)
OFILES = $(SRC:%=%.o)
LIBFT = libft.a
NAME = ft_printf.a

all: $(NAME)

$(NAME): $(LIBFT) $(OFILES)
	ar -rc $(NAME) $(OFILES) $(LIBFT:%=libs/%)

$(LIBFT): $(LIBFT_OFILES)
	ar -rc $(LIBFT:%=libs/%) $(LIBFT_OFILES)

clean:
	rm -f $(OFILES) $(LIBFT_OFILES) $(LIBFT:%=libs/%)

fclean: clean
	rm -f $(NAME)
re: fclean all