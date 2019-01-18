# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 22:26:25 by cempassi          #+#    #+#              #
#    Updated: 2019/01/18 11:49:25 by cempassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = $(LPATH)libft.a
LIBDB = $(LPATH)libftdb.a
EXEC = ft_printf

CC = Clang
COMPILE = $(CC) -c

vpath %.c srcs/
vpath %.h includes/

#Reset
NC=\033[0m

# Regular Colors
BLACK=\033[0;30m
RED=\033[0;31m
GREEN =\033[32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m

MKDIR = mkdir -p
CLEANUP = rm -rf

#WFLAGS += -Wall
#WFLAGS += -Werror
#WFLAGS += -Wextra
DFLAGS = -fsanitize=address
IFLAGS = -I $(IPATH)
CFLAGS = $(WFLAGS) $(IFLAGS)

OPATH = obj/
SPATH = srcs/
IPATH =includes/
LPATH =libft/

INCS = ft_printf.h

SRCM = main.c
SRCS += ft_printf.c
SRCS += format.c
SRCS += extract.c
SRCS += type.c
SRCS += widthprec.c
SRCS += output.c
SRCS += char.c
SRCS += digit.c
SRCS += u_int.c
SRCS += binary.c
SRCS += octal.c
SRCS += hexadecimal.c
SRCS += doubles.c
SRCS += string.c
SRCS += pointer.c


#--------------------Memory--------------------#
SRCS +=ft_bzero.c
SRCS +=ft_memalloc.c
SRCS +=ft_memmove.c
SRCS +=ft_memchr.c
SRCS +=ft_memcmp.c
SRCS +=ft_memcpy.c
SRCS +=ft_memccpy.c
SRCS +=ft_memdel.c
SRCS +=ft_memset.c

#--------------------Strings---------------------#
SRCS +=ft_isalnum.c
SRCS +=ft_isalpha.c
SRCS +=ft_isascii.c
SRCS +=ft_isdigit.c
SRCS +=ft_isprint.c
SRCS +=ft_abs.c
SRCS +=ft_strcat.c
SRCS +=ft_strchr.c
SRCS +=ft_strcmp.c
SRCS +=ft_strcpy.c
SRCS +=ft_strdup.c
SRCS +=ft_strlcat.c
SRCS +=ft_strlen.c
SRCS +=ft_strncat.c
SRCS +=ft_strncmp.c
SRCS +=ft_strncpy.c
SRCS +=ft_strnstr.c
SRCS +=ft_strrchr.c
SRCS +=ft_strstr.c
SRCS +=ft_strclr.c
SRCS +=ft_strdel.c
SRCS +=ft_strequ.c
SRCS +=ft_striter.c
SRCS +=ft_striteri.c
SRCS +=ft_strjoin.c
SRCS +=ft_strmap.c
SRCS +=ft_strmapi.c
SRCS +=ft_strnequ.c
SRCS +=ft_strnew.c
SRCS +=ft_strsplit.c
SRCS +=ft_strsub.c
SRCS +=ft_strtrim.c
SRCS +=ft_tolower.c
SRCS +=ft_toupper.c
SRCS +=ft_strinsert.c
SRCS +=ft_strcspn.c
SRCS +=ft_strspn.c
SRCS +=ft_strrev.c

#--------------------Conversion------------------#
SRCS +=ft_atoi.c
SRCS +=ft_itoa.c
SRCS +=ft_ullitoa.c
SRCS +=ft_llitoa.c
SRCS +=ft_atoll_base.c
SRCS +=ft_atoull_base.c
SRCS +=ft_convert_base.c

#----------------------Tab-----------------------#
SRCS +=ft_freetab.c

#--------------------Lists-----------------------#
SRCS +=ft_lstadd.c
SRCS +=ft_lstdel.c
SRCS +=ft_lstdelone.c
SRCS +=ft_lstiter.c
SRCS +=ft_lstmap.c
SRCS +=ft_lstnew.c
SRCS +=ft_lstrev.c
SRCS +=ft_lstaddback.c
SRCS +=ft_lstmerge.c
SRCS +=ft_lstfind.c
SRCS +=ft_lstlen.c
SRCS +=ft_tabtolst.c

#--------------------Output----------------------#
SRCS +=ft_putchar.c
SRCS +=ft_putchar_fd.c
SRCS +=ft_putendl.c
SRCS +=ft_putendl_fd.c
SRCS +=ft_putnbr.c
SRCS +=ft_putnbr_fd.c
SRCS +=ft_putstr.c
SRCS +=ft_putnstr.c
SRCS +=ft_putstr_fd.c
SRCS +=ft_ringbuffer.c
SRCS +=ft_getopt.c
SRCS +=ft_getdelim.c

OBJS = $(patsubst %.c, ./%.o, $(SRCS))

all : $(NAME)

run : all
	$(COMPILE) $(CFLAGS) ../main.c -o main.o
	$(CC) -o $(EXEC) $(NAME) main.o
	./$(EXEC)

$(NAME): $(OBJS) 
	ar -rus $@ $^

$(OBJS) : ./%.o : $(SPATH)%.c $(SRCS) 
	$(COMPILE) $(CFLAGS) $< -o $@

clean :
	$(CLEANUP) $(OBJS)
	$(CLEANUP) main.o

fclean : clean
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(EXEC)

re: fclean all

.PHONY: all clean fclean re run
