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
		utils/resolver \
		utils/sorter \
		utils/stack_utils \

CFILES = $(SRC:%=%.c) 

NAME = push_swap

all: $(NAME)

header:
	@echo "$$HEADER"

$(CFILES): header

%.o: %.c
	@printf "\t🤖 Compiling $<...\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES) $(LIBFT_LIB)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME)...\r"
	@$(CC) $(CFLAGS) $(CFILES) $(LIBFT_LIB) -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO] [$(NAME)]\t$(NAME) is compiled ✅\n"

debug: fclean $(CFILES) $(LIBFT_LIB)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME)...\r"
	@$(CC) $(CFLAGS) -g -fsanitize=address $(CFILES) $(LIBFT_LIB) -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO] [$(NAME)]\t$(NAME) is compiled ✅"
	@echo "\nThe programm was compiled with debug sanitizer set to address\nDo not forget to use \"leak -atExit -- $(NAME)\" in order to check for potential leaks.\nNote that it won't work with the debug version.\n\nFor better debug, you can use \"lldb $(name) <args>\" after using debug rule.\n"

$(LIBFT_LIB): $(LIBFT_PATH)Makefile
	@echo "$$LIB_HEADER"
	@make -C $(LIBFT_PATH) all --no-print-directory

clean:
	@$(MAKE) -C $(LIBFT_PATH) fclean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@echo "\t[INFO] [$(NAME)]\t$(NAME) is fully deleted 🗑️"

re: fclean all

help:
	@echo "$$HEADER"
	@echo "all		-	Build $(NAME)"
	@echo "clean		-	Clean temporary files"
	@echo "fclean		-	Clean the whole build"
	@echo "debug		-	Runs the program with g3 fsanitize=address"
	@echo "$(NAME)	-	Build the $(NAME) with necessary libs"
	@echo "$(LIBFT_LIB)	-	Build the lib $(LIBFT_LIB)"

.PHONY = help all clean fclean re header
