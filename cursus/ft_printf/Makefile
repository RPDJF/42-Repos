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

LIBFT_PATH = ./libft/
LIBFT_SRC =	ft_bzero \
			ft_calloc \
			ft_itoa \
			ft_memchr \
			ft_memset \
			ft_strjoin \
			ft_strlen \
			ft_itoa_base_signed \
			ft_itoa_base_unsigned \
			ft_itoa_base \
			ft_itoa_unsigned \

LIBFT_CFILES = $(LIBFT_SRC:%=$(LIBFT_PATH)%.c)
LIBFT_OFILES = $(LIBFT_SRC:%=$(LIBFT_PATH)%.o)

UTILS_SRC =	ft_printf_utils \

UTILS_CFILES = $(UTILS_SRC:%=utils/%.c)
UTILS_OFILES = $(UTILS_SRC:%=utils/%.o)


SRC = ft_printf \

CFILES = $(UTILS_CFILES) $(SRC:%=%.c) 
OFILES = $(UTILS_OFILES) $(SRC:%=%.o)

NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	@tput el
	@printf "\t🤖 Compiling $<...\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@tput el
	@echo "\t[INFO] [$(NAME)]\t$< is compiled ✅"

$(NAME): header $(CFILES) lib_header $(LIBFT_CFILES) buildlibft $(LIBFT_OFILES) $(OFILES)
	@echo "$$APP_HEADER"
	@tput el
	@printf "\t🤖 Compiling $(NAME)...\r"
	@ar -rc $(NAME) $(LIBFT_OFILES) $(OFILES)
	@tput el
	@echo "\t[INFO] [$(NAME)]\t$(NAME) is compiled ✅\n"

buildlibft: $(LIBFT_PATH)Makefile
	@$(MAKE) -C $(LIBFT_PATH) all --no-print-directory

lib_header:
	@echo "$$LIB_HEADER"

clean:
	@rm -f $(OFILES)
	@echo "\t[INFO] [$(NAME)]\t$(words $(OFILES)) object files deleted 🗑️"
	@$(MAKE) -C $(LIBFT_PATH) fclean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@echo "\t[INFO] [$(NAME)]\t$(NAME) is fully deleted 🗑️"

re: fclean all

header:
	@echo
	@echo "$$HEADER"

help:
	@echo "all		-	Build the whole project"
	@echo "clean		-	Clean temporary files"
	@echo "fclean		-	Clean the whole build"
	@echo "$$NAME	-	Build the libftprintf.a with necessary libs"

.PHONY = help all clean fclean re header buildlibft lib_header