/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:38:30 by nrechati          #+#    #+#             */
/*   Updated: 2019/01/05 19:26:14 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static char		*convert(t_format *format, long long value)
{
	char	*tmp;

	tmp = ft_llitoa(value);
	if (*tmp == '0' && format->precision == 0)
		*tmp = '\0';
	if (*tmp == '-')
	{
		format->output = tmp;
		tmp = ft_strsub(tmp, 1, ft_strlen(tmp));
		ft_strdel(&format->output);
	}
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

static long long	flag_create(t_format *format, char *flag)
{
	long long		value;

	value = 0;
	if (ft_strequ(format->size, "hh"))
		value = format->arg.character;
	else if (ft_strequ(format->size, "h"))
		value = format->arg.s_short;
	else if (ft_strequ(format->size, "l"))
		value = format->arg.l_integer;
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		value = format->arg.ll_integer;
	else if (ft_strequ(format->size, "t"))
		value = format->arg.ptrdiff;
	else if (ft_strequ(format->size, "j"))
		value = format->arg.intmax;
	else if (ft_strequ(format->size, "z"))
		value = format->arg.ssizet;
	else
		value = format->arg.integer;
	if (format->flag_plus || value < 0)
		*flag = value < 0 ? '-' : '+';
	return (*flag == '-' && value != LONG_MIN ? -value: value);
}

void			digit(t_format *format)
{
	char			*tmp;
	char			flag;
	long long		value;

	flag = ' ';
	value = flag_create(format, &flag);
	tmp = convert(format, value);
	if ((format->precision -= ft_strlen(tmp)) > 0)
		tmp = precision(format, tmp);
	format->width = format->width - ft_strlen(tmp);
	if (format->flag_plus || format->flag_space || flag == '-')
	{
		if (format->flag_minus)
			format->width -= 1;
		else if (*tmp == '0' && format->precision < 0)
			format->width -= 1;
	}
	if (format->width > 0)
		tmp = width(format, tmp);
	if (format->flag_plus || format->flag_space || flag == '-')
		tmp = sign(format, tmp, flag);
	format->output = tmp;
	return ;
}
