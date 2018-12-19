/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:38:30 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 23:16:45 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	digit(t_format *format)
{
	char *tmp;

	if (ft_strequ(format->size, "l"))
		tmp = ft_llitoa(format->arg.l_integer);
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		tmp = ft_llitoa(format->arg.ll_integer);
	else
		tmp = ft_itoa(format->arg.integer);
	format->output = tmp;
	ft_strdel(&tmp);
	return ;
}
