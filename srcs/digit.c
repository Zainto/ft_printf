/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:38:30 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/29 06:30:07 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*convert(t_format *format, char flag)
{
	char 		*tmp;
	long long	holder;

	if (ft_strequ(format->size, "l"))
	{
		format->arg.l_integer *= flag == '-' ? -1 : 1;
		tmp = ft_llitoa(format->arg.l_integer);
	}
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
	{
		format->arg.ll_integer *= flag == '-' ? -1 : 1;
		tmp = ft_llitoa(format->arg.ll_integer);
	}
	else
	{
		holder = (long long)format->arg.integer * (flag == '-' ? -1 : 1);
		tmp = ft_llitoa(holder);
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
	else if (tmp[i] == '0')
	{
		if (format->precision < 0 || flag == ' ' || flag == '-')
			tmp[i] = flag;
	}
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
	else if (ft_strequ(format->size, "ll") && format->arg.l_integer < 0)
			flag = '-';
	else if (ft_strequ(format->size, "L") && format->arg.l_integer < 0)
			flag = '-';
	else if (format->arg.integer < 0)
			flag = '-';
	if (format->flag_plus && flag == ' ')
		flag = '+';
	return (flag);
}

void			digit(t_format *format)
{
	char	*tmp;
	char	flag;
	int		len;

	flag = flag_create(format);
	tmp = convert(format, flag);
	len = ft_strlen(tmp);
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	format->width = format->width - len;
	if (format->flag_plus || format->flag_space)
	{
		if (format->flag_minus || *tmp == '0')
			format->width -= 1;
	}
	if (format->width > 0)
		tmp = width(format, tmp);
	if (format->flag_plus || format->flag_space || flag == '-')
		tmp = sign(format, tmp, flag);
	format->output = tmp;
	return ;
}
