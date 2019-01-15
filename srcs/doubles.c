/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:38:49 by nrechati          #+#    #+#             */
/*   Updated: 2019/01/15 13:07:08 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	doubles(t_format *format)
{
	int		i;
	int		prev;
	int		curr;
	char	*tmp;
	char	*dst;

	i = -1;
	prev = 0;
	curr = 0;
	tmp = ft_strnew(20);
	tmp = ft_strcpy(tmp, ft_itoa((int)format->arg.s_double));
	tmp = ft_strcat(tmp, ".");
	while (++i < format->precision - 1)
	{
		prev = ft_abs((int)format->arg.s_double);
		format->arg.s_double *= 10;
		curr = ft_abs(((int)format->arg.s_double));
		tmp = ft_strcat(tmp, ft_itoa(curr - (prev * 10)));
	}
	prev = ft_abs((int)format->arg.s_double);
	format->arg.s_double *= 10;
	curr = ft_abs(((int)format->arg.s_double));
	format->arg.s_double *= 10;
	i = ft_abs((((int)format->arg.s_double) - (curr * 10)));
	if (i >= 5)
		tmp = ft_strcat(tmp, ft_itoa(curr - (prev * 10) + 1));
	else
		tmp = ft_strcat(tmp, ft_itoa(curr - (prev * 10)));
	dst = ft_strdup(tmp);
	ft_strdel(&tmp);
	format->width = format->width - ft_strlen(dst);
	if (format->width > 0)
		dst = width(format, dst);
	format->output = dst;
	return ;
}
