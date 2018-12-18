/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:41:01 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/18 16:52:07 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unitest.h"

static void 	init_format(t_format *format, char **av)
{
	char	*output;

	format->c = av[1][0];
	format->output = output;
}

int 			main(int ac, char **av)
{
	t_format 	format;

	init_format(&format, av);
	printf_c(format);


	return (0);
}
