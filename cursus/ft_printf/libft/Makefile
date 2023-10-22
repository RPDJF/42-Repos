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
		ft_itoa_base_un \
		ft_itoa_base \
		ft_itoa_un \
		ft_exallocf \
		ft_get_next_line \
		ft_memncat \
		ft_memsuperclear \
		ft_memtostr \

CFILES = $(FILES:%=%.c)
OFILES = $(FILES:%=%.o)

NAME = libft.a

all: $(NAME)

%.o: %.c
	@if [ -n "$$TERM" ]; then \
		printf "\t🤖 Compiling $<...\r"; \
	fi
	@$(CC) $(CFLAGS) -c $< -o $@
	@if [ -n "$$TERM" ]; then \
		tput el; \
	else \
		echo "\t[INFO] [$(NAME)]\t$< is compiled ✅"; \
	fi

$(NAME): $(CFILES) $(OFILES)
	@if [ -n "$$TERM" ]; then \
		printf "\t🤖 Compiling $(NAME)...\r"; \
	fi
	@ar -rc $(NAME) $(OFILES)
	@if [ -n "$$TERM" ]; then \
		tput el; \
	fi
	@echo "\t[INFO] [$(NAME)]\t$(NAME) is compiled ✅"

clean:
	@rm -f $(OFILES)
	@echo "\t[INFO] [$(NAME)]\t$(words $(OFILES)) object files deleted 🗑️"

fclean: clean
	@rm -f $(NAME)
	@echo "\t[INFO] [$(NAME)]\t$(NAME) is fully deleted 🗑️"

re: fclean all