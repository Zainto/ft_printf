make -C ../../libft
gcc -Werror -Wall -Wextra main.c char.c ../../libft/libft.a -o ft_printf
