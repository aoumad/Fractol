
NAME = fractol

CC = gcc

FLAGS = -Wall -Werror -Wextra -framework OpenGL -framework AppKit -O3

LINK = -Imlx -Lmlx -lmlx -Llibft -lft
SRC_PATH= src/
SRC = fractol.c helpers.c key_hooks.c main.c inits.c color.c input_check.c
OBJ_PATH = obj/
OBJ := $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
RM = rm -f
AR = ar crs
LIBFT_LIB = libft.a
LIBFT_PATH = libft/
LIBFT_COMB = $(LIBFT_PATH)$(LIBFT_LIB)
LIBFT_OBJS = ${LIBFT_PATH}*.o
LIBFTMAKE = $(MAKE) -silentx -C ${LIBFT_PATH}
MLX_COMB = mlx/libmlx.a

all: $(NAME)

$(LIBFT_COMB):
	@${LIBFTMAKE}
	@printf "$(LIGHTMAGENTA)           $(NAME) is Ready!$(NC)"
	@printf "$(LIGHTMAGENTA)          ---------------------$(NC)"
	@printf "$(LIGHTMAGENTA)             Libft is Ready!$(NC)"
	@printf "$(LIGHTMAGENTA)            -----------------$(NC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -Imlx -Ilibft -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_COMB)
	@printf $(RED)"*--------object files created!---------*\n"$(RESET)
	@${CC} ${FLAGS} ${HEADERS_FOLDER} ${OBJ} $(LINK) -o ${NAME}
	@printf $(LIGHTGREEN)"*--------executable created!-----------*\n"$(RESET)

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@make -C mlx clean

fclean: clean
	@${RM} ${NAME}
	@printf $(RED)"            FULL CLEAN COMPLETED!\n$(NC)"

re: fclean all
	@make -silent -C ./mlx

.PHONY: all clean fclean re

#COLORS
RED = "\e[32m"
LIGHTGREEN = "\e[92m"
LIGHTMAGENTA = "\e[95m"
RESET = "\e[0m"