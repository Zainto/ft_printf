/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:38:30 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/20 20:06:08 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*convert(t_format *format)
{
	char *tmp;

	if (ft_strequ(format->size, "l"))
		tmp = ft_llitoa(format->arg.l_integer);
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		tmp = ft_llitoa(format->arg.ll_integer);
	else
		tmp = ft_itoa(format->arg.integer);
	return (tmp);
}

void	digit(t_format *format)
{
	char	*tmp;

	tmp = convert(format);
	if (format->flag_plus && ft_isdigit(*tmp))
		tmp = ft_strinsert(&tmp, '+', 0);
	format->output = tmp;
	return ;
}
