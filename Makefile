NAME = push_swap
NAME_BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -lft -L$(LIBFT_DIR)
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(LIBFT_DIR)

HEADERS_LIST =	push_swap.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = ./sources/
SRC_LIST =	main.c \
			init.c \
			parse_input.c \
			utils.c \
			get_index.c \
			sorted_head.c \
			actions.c \
			align_a.c \
			free.c \
			init2.c \
			move_to_a_util.c \
			move_to_a_util2.c \
			move_to_a_util3.c \
			move_to_a.c \
			move_to_b.c \
			print.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = ./objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

HEADERS_B_LIST = push_swap_bonus.h
HEADERS_B = $(addprefix $(HEADERS_DIR), $(HEADERS_B_LIST))

SRC_B_LIST =	main_bonus.c \
				actions1_bonus.c \
				actions2_bonus.c \
				free_bonus.c \
				init_bonus.c \
				list_bonus1.c \
				list_bonus2.c \
				util_bonus.c

SRC_B = $(addprefix $(SRC_DIR), $(SRC_B_LIST))

OBJ_B_LIST = $(patsubst %.c, %.o, $(SRC_B_LIST))
OBJ_B = $(addprefix $(OBJ_DIR), $(OBJ_B_LIST))

.PHONY : all bonus clean fclean re

all : $(NAME) bonus

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIBFT) $(OBJ_DIR) $(OBJ_B)
	$(CC) $(CFLAGS) $(INCLUDES_B) $(LIBS) $(OBJ_B) -o $(NAME_BONUS)

$(OBJ_B_DIR)%.o: $(SRC_B_DIR)%.c $(HEADERS_B)
	$(CC) $(CFLAGS) -c $(INCLUDES_B) $< -o $@

clean :
	$(MAKE) -sC $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(LIBFT)
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re : fclean all