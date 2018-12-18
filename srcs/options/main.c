/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:41:01 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/18 17:34:46 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unitest.h"

static int 		get_opt_gettho(char **av)
{
	if (av[1][0] != '%')
		return (0);
	if (av[1][1] == 'c')
		return (1);
	if (av[1][1] == 's')
		return (2);
	return (0);
}

static int 		fill_format(t_format *format, char **av)
{
	int 	ret = 0;
	char 	*str;

	if (!(ret = get_opt_gettho(av)))
		return (0);
	if (ret == 1)
		format->c = av[2][0];
	if (ret == 2)
	{
		str = ft_strdup(av[2]);
		format->str = str;
	}
	return (ret);
}

static void		init_format(t_format *format)
{

	format->c = 0;
	format->str = NULL;
	format->output = NULL;
}

int 			main(int ac, char **av)
{
	int 		ret;
	t_format 	format;

	if (ac!= 3)
	{
		printf ("usage : ./printf %%[opt] [var]");
		return (0);
	}
	init_format(&format);
	if (!(ret = fill_format(&format, av)))
	{
		printf("ERROR\n");
		return (0);
	}
	if (ret == 1)
		printf_c(format);
	else
		printf("Unsupported Option ! Soon ;)\n");
	return (0);
}
