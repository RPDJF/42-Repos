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

                             __ __ __                         __                    
 .----.-----.--------.-----.|__|  |__|.-----.-----.   .-----.|__|.-----.-----.--.--.
 |  __|  _  |        |  _  ||  |  |  ||     |  _  |   |  _  ||  ||  _  |  -__|_   _|
 |____|_____|__|__|__|   __||__|__|__||__|__|___  |   |   __||__||   __|_____|__.__|
                     |__|                   |_____|   |__|       |__|               
                                                                                                                                                                                                                                                                                                   
endef
export APP_HEADER

define BONUS_HEADER


                            __ __ __                   __                            
.----.-----.--------.-----.|__|  |__|.-----.-----.    |  |--.-----.-----.--.--.-----.
|  __|  _  |        |  _  ||  |  |  ||     |  _  |    |  _  |  _  |     |  |  |__ --|
|____|_____|__|__|__|   __||__|__|__||__|__|___  |    |_____|_____|__|__|_____|_____|
                    |__|                   |_____|                                   

endef
export BONUS_HEADER

CC = gcc
CFLAGS = -Wall -Wextra -Werror

BETTERFT_PATH = ./betterft/
BETTERFT_LIB = $(BETTERFT_PATH:%=%betterft.a)

BONUS_BETTERFT_PATH = ./betterft_bonus/
BONUS_BETTERFT_LIB = $(BONUS_BETTERFT_PATH:%=%betterft_bonus.a)


SRC = 	pipex \
		utils/argument_parser \
		utils/command_parser \
		utils/error_handler \
		utils/pathser \
		utils/runner \

CFILES = $(SRC:%=%.c)

BONUS_SRC =	pipex_bonus \
			utils_bonus/argument_parser_bonus \
			utils_bonus/command_parser_bonus \
			utils_bonus/error_handler_bonus \
			utils_bonus/heredoc_bonus \
			utils_bonus/pathser_bonus \
			utils_bonus/runner_bonus \

BONUS_CFILES = $(BONUS_SRC:%=%.c)

NAME = pipex
BONUS_NAME = pipex_bonus

all: $(NAME)

debug: fclean $(CFILES) $(BETTERFT_LIB)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME)...\r"
	@$(CC) $(CFLAGS) -g3 -fsanitize=address $(CFILES) $(BETTERFT_LIB) -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) is compiled ✅"
	@echo "\nThe programm was compiled with debug sanitizer set to address\nDo not forget to use \"leak -atExit -- $(NAME)\" in order to check for potential leaks.\nNote that it won't work with the debug version.\n\nFor better debug, you can use \"lldb $(name) <args>\" after using debug rule.\n\n"
	@echo $(shell norminette)

clean:
	@$(MAKE) -C $(BETTERFT_PATH) fclean --no-print-directory
	@$(MAKE) -C $(BONUS_BETTERFT_PATH) fclean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) is fully deleted 🗑️"
	@echo "\t[INFO]\t[$(NAME)]\t$(BONUS_NAME) is fully deleted 🗑️"

re: fclean all

bonus: $(BONUS_NAME)

help:
	@echo "$$HEADER"
	@echo "all		-	Build $(NAME)"
	@echo "bonus		-	Build $(BONUS_NAME)"
	@echo "clean		-	Clean temporary files"
	@echo "fclean		-	Clean the whole build"
	@echo "debug		-	Runs the program with g3 fsanitize=address"
	@echo "$(NAME)	-	Build the $(NAME) with necessary libs"
	@echo "$(BONUS_NAME)		-	Build the $(BONUS_NAME) with necessary libs"
	@echo "$(BETTERFT_LIB)	-	Build the lib $(BETTERFT_LIB)"

$(CFILES): header

$(BONUS_CFILES): header

%.o: %.c
	@printf "\t🤖 Compiling $<...\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES) $(BETTERFT_LIB)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME)...\r"
	@$(CC) $(CFLAGS) $(CFILES) $(BETTERFT_LIB) -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) is compiled ✅\n"

$(BETTERFT_LIB): $(BETTERFT_PATH)Makefile
	@echo "$$LIB_HEADER"
	@make -C $(BETTERFT_PATH) all --no-print-directory

$(BONUS_BETTERFT_LIB): $(BONUS_BETTERFT_PATH)Makefile
	@echo "$$LIB_HEADER"
	@make -C $(BONUS_BETTERFT_PATH) all --no-print-directory

$(BONUS_NAME): $(BONUS_CFILES) $(BONUS_BETTERFT_LIB)
	@echo "$$BONUS_HEADER"
	@printf "\t🤖 Compiling $(BONUS_NAME) 🌟...\r"
	@$(CC) $(CFLAGS) $(BONUS_CFILES) $(BONUS_BETTERFT_LIB) -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(BONUS_NAME)]\t$(NAME) ($(BONUS_NAME)) 🌟 is compiled ✅\n"

header:
	@echo "$$HEADER"

.PHONY = all clean fclean re bonus header help
