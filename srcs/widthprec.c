/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widthprec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:08:00 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/28 17:28:40 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*precision(t_format *format, char *tmp)
{
	char	*holder;
	char	*prc;

	holder = tmp;
	prc = ft_strnew(format->precision);	
	ft_memset(prc, '0', format->precision);
	tmp = ft_strjoin(prc, holder);
	ft_strdel(&holder);
	return (tmp);
}

char		*width(t_format *format, char *tmp)
{
	char 	*width;
	char	*holder;

	holder = tmp;
	width = ft_strnew(format->width);
	ft_memset(width, ' ', format->width);
	if (format->flag_minus)
		tmp = ft_strjoin(tmp, width);	
	else
		tmp = ft_strjoin(width, tmp);	
	ft_strdel(&holder);
	ft_strdel(&width);
	return (tmp);
}

char		*unsigned_convert(t_format *format)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strequ(format->size, "l"))
		tmp = ft_ullitoa(format->arg.ul_integer);
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		tmp = ft_ullitoa(format->arg.ull_integer);
	else
		tmp = ft_ullitoa(format->arg.u_integer);
	return (tmp);
}
