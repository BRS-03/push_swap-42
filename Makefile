NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = push_swap.c instraction.c parc.c push_utils.c sort.c instraone.c instratwo.c instrathree.c push_utilsone.c push_utilstwo.c  push_utilsthree.c sortone.c  sorttwo.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all