make -C ../../libft
gcc -Werror -Wall -Wextra ./run/main.c ./srcs/char.c ./srcs/string.c ./srcs/addr.c ./srcs/digit.c ../../libft/libft.a -o ft_printf
