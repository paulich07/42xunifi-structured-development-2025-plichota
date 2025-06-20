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

NAME = libft.a

CFILES =	ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_strlen.c \
					ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strnstr.c \
					ft_atoi.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \

BONUSFILES =	ft_lstnew.c \
							ft_lstadd_front.c \
							ft_lstsize.c \
							ft_lstlast.c \
							ft_lstadd_back.c \
							ft_lstdelone.c \
							ft_lstclear.c \
							ft_lstiter.c \
							ft_lstmap.c

OFILES = $(CFILES:.c=.o)

OBONUSFILES = $(BONUSFILES:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES) $(OBONUSFILES)
	@echo "$(GREEN)---- Building archive $@ ----$(RESET)"
	@ar rcs $(NAME) $(OFILES) $(OBONUSFILES)

# REGOLA IMPLICITA
#%.o: %.c libft.h
#	$(CC) $(CFLAGS) -c $< -o $@

# to do rimuovere bonus
clean:
	@echo "$(RED)---- Removing .o files in $(NAME) ----$(RESET)"
	@rm -f $(OFILES) $(OBONUSFILES)

fclean: clean
	@if [ -n "$(NAME)" ] && [ -e "$(NAME)" ]; then \
		echo "$(RED)---- Removing executable $(NAME)...$(RESET)"; \
		rm -f $(NAME); \
	fi

bonus: $(OFILES) $(OBONUSFILES)
	@echo "$(GREEN)---- Building bonus ----$(RESET)"
	@ar rcs $(NAME) $(OFILES) $(OBONUSFILES)

re: fclean all

.PHONY:  all clean fclean re bonus