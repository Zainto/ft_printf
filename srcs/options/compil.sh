make -C ../../libft
gcc -Werror -Wall -Wextra main.c char.c string.c addr.c digit.c ../../libft/libft.a -o ft_printf
