/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:38:30 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/28 17:11:05 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*convert(t_format *format, char *flag)
{
	char *tmp;

	if (ft_strequ(format->size, "l"))
	{
		*flag = format->arg.l_integer < 0 ? '-' : '+';
		format->arg.l_integer *= *flag == '-' ? -1 : 1;
		tmp = ft_llitoa(format->arg.l_integer);
	}
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
	{
		*flag = format->arg.ll_integer < 0 ? '-' : '+';
		format->arg.ll_integer *= *flag == '-' ? -1 : 1;
		tmp = ft_llitoa(format->arg.ll_integer);
	}
	else
	{
		*flag = format->arg.integer < 0 ? '-' : '+';
		format->arg.integer *= *flag == '-' ? -1 : 1;
		tmp = ft_itoa(format->arg.integer);
	}
	return (tmp);
}

void	digit(t_format *format)
{
	char	*tmp;
	char	flag;
	int		len;

	flag = 0;
	tmp = convert(format, &flag);
	len = ft_strlen(tmp);
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	if ((format->flag_plus && ft_isdigit(*tmp)) || flag == '-')
		tmp = ft_strinsert(&tmp, flag, 0);
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	format->output = tmp;
	return ;
}
