make -C ../../libft
gcc -Werror -Wall -Wextra ./run/main.c ./srcs/char.c ./srcs/string.c ./srcs/addr.c ./srcs/digit.c ./srcs/u_int.c ./srcs/octal.c ./srcs/hexa_s.c ./srcs/hexa_c.c ../../libft/libft.a -o ft_printf
