/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:40:24 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/28 17:15:01 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*convert(t_format *format)
{
	char *tmp;

	tmp = NULL;
	if (ft_strequ(format->size, "l"))
		tmp = ft_ullitoa(format->arg.ul_integer);
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		tmp = ft_ullitoa(format->arg.ull_integer);
	else
		tmp = ft_ullitoa(format->arg.u_integer);
	return (tmp);
}

void			u_integer(t_format *format)
{
	char	*tmp;
	int		len;

	tmp = convert(format);
	len = ft_strlen(tmp);
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	//if ((format->flag_plus && ft_isdigit(*tmp)) || flag == '-')
	//	tmp = ft_strinsert(&tmp, flag, 0);
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	format->output = tmp;
	return ;
}
