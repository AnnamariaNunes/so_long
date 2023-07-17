NAME := so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror -Iheaders/ -g -fsanitize=address 
SOURCE := controls.c errors.c graphics.c map.c so_long.c errors2.c mainControls.c flood_fill.c utils.c
GETNEXTLINE := get_next_line/*.c
LIBRARY := -Lminilibx-linux-master -lmlx -lXext -lX11 -lm -lz
MINILIBX := minilibx-linux-master/

OBJECTS := $(SOURCE:.c=.o)

.PHONY: all clean fclean re

$(NAME): $(OBJECTS)
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

all: $(NAME)
	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(MINILIBX)
	rm -f $(OBJECTS)

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all