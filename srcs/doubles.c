/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:38:49 by nrechati          #+#    #+#             */
/*   Updated: 2019/01/15 13:37:10 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_float(t_format *format, char **tmp)
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

void			doubles(t_format *format)
{
	char	*tmp;
	char	*dst;

	tmp = ft_strnew(20);
	tmp = ft_strcpy(tmp, ft_itoa((int)format->arg.s_double));
	tmp = ft_strcat(tmp, ".");
	toto(format, &tmp);
	dst = ft_strdup(tmp);
	ft_strdel(&tmp);
	format->width = format->width - ft_strlen(dst);
	if (format->width > 0)
		dst = width(format, dst);
	format->output = dst;
	return ;
}
