# === Colors ===
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
RESET   = \033[0m
BOLD		= \033[1m
UNDERLINE = \033[4;32m
GREEN_BG = \033[42m

NAME					= library

# Paths
HEADERS_DIR				= include
SRC_DIR						= src
OBJ_DIR						= obj

LIBFT_DIR					= libs/libft
LIBFT_HEADERS_DIR = $(LIBFT_DIR)/include

# Compiler
CC 						=	cc
CFLAGS 				= -Wall -Werror -Wextra -I$(HEADERS_DIR) -I$(SRC_DIR) -I$(LIBFT_DIR) -I$(LIBFT_HEADERS_DIR)

# Linker/Loader ld
LDFLAGS 			= -L$(LIBFT_DIR) -lft

# Sources
SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/core.c \
	$(SRC_DIR)/utils.c 

LIBFT					= $(LIBFT_DIR)/libft.a

OBJS					= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_CLEAN_ENABLED ?= 1

all: $(NAME)
	@echo "$(GREEN)---- Building of $(NAME) ----$(RESET)";

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(CYAN)---- Linking target $@ $(RESET)---- using $^"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(LIBFT):
	@echo "$(YELLOW)---- Building $< $(RESET) ----> $@"
	$(MAKE) -C $(LIBFT_DIR) --quiet

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)---- Compiling $< $(RESET) ----> $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@echo "$(MAGENTA)---- Create folder $@ $(RESET)"
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)---- Removing .o files in $(NAME)----$(RESET)"
	@rm -rf $(OBJ_DIR)
ifeq ($(LIBFT_CLEAN_ENABLED),1)
	@echo "$(RED)---- cleaning libft =---$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR) --silent
endif

fclean:
	@if [ -n "$(NAME)" ] && [ -e "$(NAME)" ]; then \
		echo "$(RED)---- Removing executable $(NAME)...$(RESET)"; \
		rm -f $(NAME); \
	fi
	@echo "$(RED)---- fcleaning libft ----$(RESET)"
	@$(MAKE) --no-print-directory LIBFT_CLEAN_ENABLED=0 clean
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent

re: fclean all

.PHONY: all clean fclean re