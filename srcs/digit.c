/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:38:30 by nrechati          #+#    #+#             */
/*   Updated: 2019/01/04 00:19:00 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*convert(t_format *format, char flag)
{
	char	*tmp;

	if (ft_strequ(format->size, "z"))
		tmp = ft_ullitoa(format->arg.ll_integer);
	else if (ft_strequ(format->size, "hh"))
		tmp = ft_llitoa(format->arg.character * (flag == '-' ? -1 : 1));
	else if (ft_strequ(format->size, "h"))
		tmp = ft_llitoa(format->arg.s_short * (flag == '-' ? -1 : 1));
	else if (ft_strequ(format->size, "l") || format->type == 'D')
		tmp = ft_llitoa(format->arg.l_integer * (flag == '-' ? -1 : 1));
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		tmp = ft_llitoa(format->arg.ll_integer * (flag == '-' ? -1 : 1));
	else
		tmp = ft_llitoa(format->arg.integer * (flag == '-' ? -1 : 1));
	if (*tmp == '0' && format->precision == 0)
		*tmp = '\0';
	if (*tmp == '-')
	{
		format->output = tmp;
		tmp = ft_strsub(tmp, 1, ft_strlen(tmp + 1));
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

static int		flag_create(t_format *format)
{
	char	flag;

	flag = ' ';
	if (ft_strequ(format->size, "l") && format->arg.l_integer < 0)
		flag = '-';
	else if (ft_strequ(format->size, "hh") && format->arg.character < 0)
		flag = '-';
	else if (ft_strequ(format->size, "h") && format->arg.s_short < 0)
		flag = '-';
	else if (ft_strequ(format->size, "ll") && format->arg.l_integer < 0)
		flag = '-';
	else if (ft_strequ(format->size, "L") && format->arg.l_integer < 0)
		flag = '-';
	else if (ft_strequ(format->size, "t") && format->arg.ptrdiff < 0)
		flag = '-';
	else if (ft_strequ(format->size, "j") && format->arg.intmax < 0)
		flag = '-';
	else if (!ft_strequ(format->size, "z") && format->arg.integer < 0)
		flag = '-';
	if (format->flag_plus && flag == ' ')
		flag = '+';
	return (flag);
}

void			digit(t_format *format)
{
	char	*tmp;
	char	flag;

	flag = flag_create(format);
	tmp = convert(format, flag);
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
