#############################################
# Colors for output
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE_LIGHT = \033[0;94m
BLUE = \033[0;34m
CYAN_LIGHT = \033[0;96m
CYAN = \033[0;36m
MAGENTA_LIGHT = \033[0;35m
MAGENTA = \033[0;38;5;129m
NC = \033[0m

#############################################

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror 

# Directories
SRC_DIR = src
OBJ_DIR = .cache

# Files
SRC = $(SRC_DIR)/main.c\
	  $(SRC_DIR)/utils/utils.c\
	  $(SRC_DIR)/check_args.c\
	  
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#############################################

all: $(NAME)

ll: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[38;5;33m██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗\033[0m"
	@echo "\033[38;5;37m██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝\033[0m"
	@echo "\033[38;5;39m██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗\033[0m"
	@echo "\033[38;5;45m██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║\033[0m"
	@echo "\033[38;5;51m██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║\033[0m"
	@echo "\033[38;5;57m╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝\033[0m"
	@echo "                                                                             "
	@echo "$(GREEN)Building the Philosophers project...$(NC)"
	@total=$(words $(OBJ)); \
	count=0; \
	spinner="|/-\\"; \
	for file in $(OBJ); do \
		count=$$((count + 1)); \
		percentage=$$((count * 100 / total)); \
		progress=$$((percentage / 2)); \
		spin_char=$$(echo "$${spinner}" | cut -c $$(($$count % 4 + 1))); \
		bar=""; \
		for i in $$(seq 1 $$progress); do bar="$${bar}█"; done; \
		for i in $$(seq $$progress 49); do bar="$${bar}░"; done; \
		if [ $$percentage -eq 100 ]; then \
			bar="███████████████████████████████████████████████████"; \
		fi; \
		printf "\r\033[K$(YELLOW)Compiling : $${bar} %d%% $${spin_char}" $$percentage; \
		sleep 0.01; \
	done; \
	printf "\r\033[K\n";

	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)Compilation successful!$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@) # Crée les sous-dossiers nécessaires dans .cache/
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Cleaned!$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Fully cleaned!$(NC)"

re: fclean all

.PHONY: all clean fclean re
