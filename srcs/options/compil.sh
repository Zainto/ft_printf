make -C ../../libft
gcc -Werror -Wall -Wextra main.c char.c unitest.h ../../libft/libft.a
