CC = cc 

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -lmlx -framework OpenGL -framework AppKit

OBJ =	main.o \
		fractol.o \
		color.o \
		helper.o \
		inits.o
		input_check.o \
		key_hook.o \
		libft.o \

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
