/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:38:49 by nrechati          #+#    #+#             */
/*   Updated: 2019/01/15 13:50:04 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static char			*sign(t_format *format, char *tmp, char flag)
{
	int i;

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

static long double	flag_create(t_format *format, char *flag)
{
	long double value;

	value = 0;
	if (ft_strequ(format->size, "l"))
		value = format->arg.l_double;
	else
		value = format->arg.s_double;
	if (format->flag_plus || value < 0)
		*flag = value < 0 ? '-' : '+';
	return (*flag == '-' && value != LONG_MIN ? -value : value);
}

static void			fill_float(t_format *format, char **tmp)
{
	int		i;
	int		prev;
	int		curr;

	prev = 0;
	curr = 0;
	i = -1;
	while (++i < format->precision - 1)
	{
		prev = ft_abs((int)format->arg.s_double);
		format->arg.s_double *= 10;
		curr = ft_abs(((int)format->arg.s_double));
		*tmp = ft_strcat(*tmp, ft_itoa(curr - (prev * 10)));
	}
	prev = ft_abs((int)format->arg.s_double);
	format->arg.s_double *= 10;
	curr = ft_abs(((int)format->arg.s_double));
	format->arg.s_double *= 10;
	i = ft_abs((((int)format->arg.s_double) - (curr * 10)));
	if (i >= 5)
		*tmp = ft_strcat(*tmp, ft_itoa(curr - (prev * 10) + 1));
	else
		*tmp = ft_strcat(*tmp, ft_itoa(curr - (prev * 10)));
	return ;
}

void				doubles(t_format *format)
{
	char		flag;
	char		*tmp;
	char		*dst;
	long double	value;

	flag = ' ';
	value = flag_create(format, &flag);
	tmp = ft_strnew(20);
	tmp = ft_strcpy(tmp, ft_itoa(ft_abs((int)format->arg.s_double)));
	tmp = ft_strcat(tmp, ".");
	fill_float(format, &tmp);
	dst = ft_strdup(tmp);
	ft_strdel(&tmp);
	format->width = format->width - ft_strlen(dst);
	if (format->width > 0)
		dst = width(format, dst);
	if (format->flag_plus || format->flag_space || flag == '-')
		dst = sign(format, dst, flag);
	format->output = dst;
	return ;
}
