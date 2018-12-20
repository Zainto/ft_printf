/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:40:24 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/20 03:06:46 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			u_integer(t_format *format)
{
	char *tmp;

	if (ft_strequ(format->size, "l"))
		tmp = ft_ullitoa(format->arg.l_integer);
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		tmp = ft_ullitoa(format->arg.ll_integer);
	else
		tmp = ft_ullitoa(format->arg.integer);
	format->output = tmp;
	ft_strdel(&tmp);
	return ;
}
