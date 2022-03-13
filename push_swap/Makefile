PUSH_SWAP_SRC = ft_rotate.c \
			push_swap.c \
			check_args.c \
			ft_split.c \
			check_errors.c \
			ft_swap.c \
			push_swap_utils1.c \
			exit.c \
			instruction_utils.c \
			push_swap_utils2.c \
			ft_reverse_rotate.c \
			main.c \

PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:%.c=%.o)
PUSH_SWAP = push_swap
CC = gcc 
CFLAGS = -Wall -Wextra -Werror

all : $(PUSH_SWAP)

$(PUSH_SWAP) : $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) -o $(PUSH_SWAP)

%.o:%.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o 

fclean: 
	rm -f $(PUSH_SWAP)

re: fclean all