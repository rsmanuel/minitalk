FLAGS = -Wall -Werror -Wextra

RM = rm -f

all: server client

server: server.c libft/libft.a
	gcc $(FLAGS) $< -o $@ -Llibft/ -lft

client: client.c libft/libft.a
	gcc $(FLAGS) $< -o $@ -Llibft/ -lft

libft/libft.a:
	make libft.a -C ./libft

clean:
	make clean -C ./libft
	$(RM) libft/libft.a
	$(RM) server client

fclean: clean

re: fclean all

.PHONY: all clean fclean re
