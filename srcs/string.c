/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 09:45:19 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/29 03:16:00 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string(t_format *format)
{
	char	*tmp;
	char	*width;

	if (format->precision == -1)
		tmp = ft_strdup(format->arg.string);
	else
		tmp = ft_strsub(format->arg.string, 0, format->precision);
	format->width = format->width - ft_strlen(tmp);
	width = NULL;
	if (format->width > 0)
	{
		width = ft_strnew(format->width);
		ft_memset(width, ' ', format->width);
	}
	if (format->flag_minus)
		format->output = ft_strjoin(tmp, width);	
	else
		format->output = ft_strjoin(width, tmp);	
	ft_strdel(&tmp);
	ft_strdel(&width);
	return ;
}
