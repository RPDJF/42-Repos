define HEADER
                                ..                                
                              ...                                 
                      ..........................                  
                   ................................               
                     .................................            
                   .....................................          
                  ........................................        
                .............................................     
               ................................................   
              ...............................................     
              ................................................    
              ................................................    
              .................................................   
              ....................................-............   
              ...................--...............+#...........   
              ...................##...............###...........  
             ...................+###.............+###+..........  
                ...............+#####...........-+####-....... .. 
                 ..+##........+##+++--...............-#.......    
                  .####......+#-....--#-......+-.....+#-......    
 ...---           .+####+.....#-.......#+..#.##-++-+-###.....     
 .++++-..+-.........+######...##-+++++-#########..-+####.. .      
 -+++++++..............-++####+#########################-                           _
.+++++++.....................-##############+####+-..-+++-                         | |            __
.++++++-.........................-++#########+-+-++++++++.        _______ __ __  __| | ____      |__| ____   ______
.++++++-...............................++.....-+++++++++-         \_  __ \  |  \/ __ |/ __ \_____|  |/ __ \ /  ___/ 
 .+++++-......................................++++++++++.          |  | \/  |  / /_/ \  ___/_____/  \  ___/ \___ \  
    .-++.....................................++++++++++.           |__|  |____/\____ |\___  >/\__|  |\___  >____  > 
         ..................................#-+++++++++-                             \/    \/ \______|    \/     \/  
               ...........................####-+++++-##           
                          ................###--+++++-+.           
                              .............-.-...    

=======================================================================================================================
endef
export HEADER

define LIB_HEADER
 

                             __ __ __                  __ __ __                     __              
 .----.-----.--------.-----.|__|  |__|.-----.-----.   |  |__|  |--.----.---.-.----.|__|.-----.-----.
 |  __|  _  |        |  _  ||  |  |  ||     |  _  |   |  |  |  _  |   _|  _  |   _||  ||  -__|__ --|
 |____|_____|__|__|__|   __||__|__|__||__|__|___  |   |__|__|_____|__| |___._|__|  |__||_____|_____|
                     |__|                   |_____|                                                 
                                                                                                    
endef
export LIB_HEADER

define APP_HEADER
 

                             __ __ __                  __ __ __     ___ __               __         __    ___         
 .----.-----.--------.-----.|__|  |__|.-----.-----.   |  |__|  |--.'  _|  |_.-----.----.|__|.-----.|  |_.'  _| .---.-.
 |  __|  _  |        |  _  ||  |  |  ||     |  _  |   |  |  |  _  |   _|   _|  _  |   _||  ||     ||   _|   _|_|  _  |
 |____|_____|__|__|__|   __||__|__|__||__|__|___  |   |__|__|_____|__| |____|   __|__|  |__||__|__||____|__||__|___._|
                     |__|                   |_____|                         |__|                                      
                                                                                                                                                                                                                                                                                           
endef
export APP_HEADER

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_SRC =	ft_atoi \
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

LIBFT_CFILES = $(LIBFT_SRC:%=libs/%.c)
LIBFT_OFILES = $(LIBFT_SRC:%=libs/%.o)

UTILS_SRC =	ft_printf_utils \

UTILS_CFILES = $(UTILS_SRC:%=utils/%.c)
UTILS_OFILES = $(UTILS_SRC:%=utils/%.o)


SRC = ft_printf \

CFILES = $(SRC:%=%.c) $(UTILS_CFILES)
OFILES = $(SRC:%=%.o) $(UTILS_OFILES)

NAME = libftprintf.a

all: $(NAME)

$(NAME): header  $(LIBFT_CFILES) $(CFILES) lib_header $(LIBFT_OFILES) $(OFILES)
	@echo "$$APP_HEADER"
	ar -rc $(NAME) $(LIBFT_OFILES) $(OFILES)

lib_header:
	@echo "$$LIB_HEADER"

clean:
	rm -f $(LIBFT_OFILES) $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

header:
	clear
	@echo "$$HEADER"

help:
	@echo "all		-	Build the whole project"
	@echo "clean		-	Clean temporary files"
	@echo "fclean		-	Clean the whole build"
	@echo "$$NAME	-	Build the libftprintf.a with necessary libs"

.PHONY = libs_header all clean fclean re header