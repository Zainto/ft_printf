# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 22:26:25 by cempassi          #+#    #+#              #
#    Updated: 2019/01/15 11:52:16 by nrechati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = $(LPATH)libft.a
LIBDB = $(LPATH)libftdb.a
EXEC = ft_printf

CC = Clang
COMPILE = $(CC) -c
DEBUG = $(CC) -g

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
IFLAGS = -I $(IPATH) -I $(LIPATH)
CFLAGS = $(WFLAGS) $(IFLAGS)

OPATH = obj/
SPATH = srcs/
IPATH =includes/
LPATH =libft/
LIPATH =libft/includes/

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

DSYM = $(NAME).dSYM

OBJS = $(patsubst %.c, $(OPATH)%.o, $(SRCS))
OBJDB = $(patsubst %.c, $(OPATH)%db.o, $(SRCS))

all : $(LIB) $(OPATH) $(NAME)

run : all
	$(COMPILE) $(CFLAGS) srcs/$(SRCM) -o $(OPATH)main.o
	$(CC) -o $(EXEC) $(NAME) $(OPATH)main.o
	./$(EXEC)

debug : $(OPATH) $(LIBDB) $(OBJDB) $(INCS)
	$(DEBUG) -o $(NAME) $(LIBDB) $(OBJDB)

$(LIBDB):
	$(MAKE) -C libft/ debug

$(OBJDB): $(OPATH)%db.o : %.c $(INCS)
	$(DEBUG) -c $(CFLAGS) $< -o $@

$(NAME): $(LIB) $(OBJS) $(INCS)
	ar -rus $@ $(OBJS) libft/objs/*.o
	@printf "$(GREEN)$@ is ready.\n$(NC)"

$(OBJS) : $(OPATH)%.o : %.c $(INCS)
	$(COMPILE) $(CFLAGS) $< -o $@

$(LIB) :
	$(MAKE) -C $(LPATH)

$(OPATH):
	$(MKDIR) $@

clean :
	$(MAKE) -C $(LPATH) clean
	$(CLEANUP) $(OBJS)
	$(CLEANUP) $(OBJDB)
	$(CLEANUP) $(OPATH)
	$(CLEANUP) $(DSYM)

fclean : clean
	$(MAKE) -C $(LPATH) fclean
	$(CLEANUP) $(OPATH)
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(EXEC)

re: fclean all

.PHONY: all clean fclean re debug run
.SILENT :
