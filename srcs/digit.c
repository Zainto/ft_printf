/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:38:30 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/29 05:20:28 by cempassi         ###   ########.fr       */
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
	if (*tmp == '0' && format->precision == 0)
		*tmp = '\0';
	return (tmp);
}

static char		*sign(t_format *format, char *tmp, char flag)
{
	int		i;

	i = 0;
	while (tmp[i] == ' ' && tmp[i + 1] == ' ')
		i++;
	if (tmp[i] == ' ')
		tmp[i] = flag;
	else if (tmp[i] == '0' && format->precision < 0)
		tmp[i] = flag;
	else
		tmp = ft_strinsert(&tmp, flag, 0);
	return (tmp);
}

void			digit(t_format *format)
{
	char	*tmp;
	char	flag;
	int		len;

	flag = 0;
	tmp = convert(format, &flag);
	len = ft_strlen(tmp);
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	format->width = format->width - len;
	if (format->flag_plus && (format->flag_minus || *tmp == '0'))
		format->width -= 1;
	if (format->width > 0)
		tmp = width(format, tmp);
	if (format->flag_plus || flag == '-')
		tmp = sign(format, tmp, flag);
	format->output = tmp;
	return ;
}
