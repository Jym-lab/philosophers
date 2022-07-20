CC = gcc
#CFLAGS = -Wall -Werror -Wextra
FSANI = -g3 -fsanitize=address
RM = rm -f
NAME = philo

INCLUDE = -I./include
SRCS_DIR = ./srcs
SRCS_FILES = main.c argv_init.c
SRCS = $(addprefix $(addsuffix /, $(SRCS_DIR)), $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(INCLUDE) $^ -o $@

re : fclean all

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

.PHONY: all re clean fclean
