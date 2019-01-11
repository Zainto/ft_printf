/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:41:01 by nrechati          #+#    #+#             */
/*   Updated: 2019/01/11 12:25:02 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/unitest.h"

static int		get_opt_gettho(char **av)
{
	if (av[1][0] != '%')
		return (0);
	if (av[1][1] == 'c')
		return (1);
	if (av[1][1] == 's')
		return (2);
	if (av[1][1] == 'p')
		return (3);
	if (av[1][1] == 'd' || av[1][1] == 'i')
		return (4);
	if (av[1][1] == 'o')
		return (5);
	if (av[1][1] == 'u')
		return (6);
	if (av[1][1] == 'x')
		return (7);
	if (av[1][1] == 'X')
		return (8);
	if (av[1][1] == 'f')
		return (9);
	return (0);
}

static int		fill_format(t_format *format, char **av)
{
	int		ret;

	ret = 0;
	if (!(ret = get_opt_gettho(av)))
		return (0);
	if (ret == 1)
		format->c = av[2][0];
	if (ret == 2)
		format->str = av[2];
	if (ret == 3)
		format->p = av[2];
	if (ret == 4)
		format->d = atoi(av[2]);
	if (ret == 5)
		format->d = atoi(av[2]);
	if (ret == 6)
		format->u = atoi(av[2]);
	if (ret == 7)
		format->d = atoi(av[2]);
	if (ret == 8)
		format->d = atoi(av[2]);
	if (ret == 9)
		format->f = atof(av[2]);
	return (ret);
}

static void		init_format(t_format *format)
{
	format->output = NULL;
	format->c = 0;
	format->str = NULL;
	format->d = 0;
	format->p = NULL;
	format->u = 0;
}

int				main(int ac, char **av)
{
	int			ret;
	t_format	format;

	if (ac != 3)
	{
		printf("usage : ./printf %%[opt] [var]");
		return (0);
	}
	init_format(&format);
	if (!(ret = fill_format(&format, av)))
	{
		printf("ERROR\n");
		return (0);
	}
	if (ret == 1)
		printf_c(&format);
	else if (ret == 2)
		printf_s(&format);
	else if (ret == 2)
		printf_s(&format);
	else if (ret == 3)
		printf_p(&format);
	else if (ret == 4)
		printf_d(&format);
	else if (ret == 5)
		printf_o(&format);
	else if (ret == 6)
		printf_u(&format);
	else if (ret == 7)
		printf_x(&format);
	else if (ret == 8)
		printf_xc(&format);
	else if (ret == 9)
		printf_f(&format);
	else
		printf("Unsupported Option ! Soon ;)\n");
	if (format.output != NULL)
		printf("Output : %s\n", format.output);
	return (0);
}
