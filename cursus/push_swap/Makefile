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
 

                            __ __ __                                      __                                    
.----.-----.--------.-----.|__|  |__|.-----.-----.    .-----.--.--.-----.|  |--.    .-----.--.--.--.---.-.-----.
|  __|  _  |        |  _  ||  |  |  ||     |  _  |    |  _  |  |  |__ --||     |    |__ --|  |  |  |  _  |  _  |
|____|_____|__|__|__|   __||__|__|__||__|__|___  |    |   __|_____|_____||__|__|____|_____|________|___._|   __|
                    |__|                   |_____|    |__|                    |______|                   |__|   
                                                                                                                                                                                                                                                                                           
endef
export APP_HEADER

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft/
LIBFT_LIB = $(LIBFT_PATH:%=%libft.a)


SRC = 	push_swap \
		utils/checkers \
		utils/error_handler \
		utils/handler \
		utils/sorter \
		utils/stack_utils \

CFILES = $(SRC:%=%.c) 
OFILES = $(SRC:%=%.o)

NAME = push_swap

all: $(NAME)

%.o: %.c
	@printf "\t🤖 Compiling $<...\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): header $(CFILES) lib_header buildlibft $(OFILES)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME)...\r"
	@$(CC) $(CFLAGS) $(OFILES) $(LIBFT_LIB) -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO] [$(NAME)]\t$(NAME) is compiled ✅\n"

debug: fclean header $(CFILES) lib_header buildlibft $(OFILES)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME)...\r"
	@$(CC) $(CFLAGS) -g3 -fsanitize=address $(OFILES) $(LIBFT_LIB) -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO] [$(NAME)]\t$(NAME) is compiled ✅"
	@echo "\nThe programm was compiled with debug sanitizer and without cflags\nDo not forget to use \"leaks -atExit -- $(NAME)\" in order to check for potential leaks.\nNote that it won't work with the debug version.\n"

buildlibft: $(LIBFT_PATH)Makefile
	@make -C $(LIBFT_PATH) all --no-print-directory

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
	@echo "all		-	Build $(NAME)"
	@echo "clean		-	Clean temporary files"
	@echo "fclean		-	Clean the whole build"
	@echo "debug		-	Runs the program with g3 fsanitize=address"
	@echo "$(NAME)	-	Build the $(NAME) with necessary libs"

.PHONY = help all clean fclean re header buildlibft lib_header
