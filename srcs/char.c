/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:36:59 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/20 17:54:21 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	character(t_format *format)
{
	char		*tmp;
	char		*width;

	tmp = ft_strnew(1);
	*tmp = format->arg.character;
	format->width = format->width - 1;
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
