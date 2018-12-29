/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:26:03 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/29 03:41:50 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexadecimal(t_format *format)
{
	char	*tmp;
	char	*holder;
	int		len;
	int		i;

	i = 0;
	tmp = unsigned_convert(format);
	tmp = *(holder = tmp) ? ft_convert_base(tmp, TEN, HEXA) : tmp;
	if (format->type == 'X')
	{
		while ((tmp[i] = ft_toupper(tmp[i])))
			i++;
	}
	len = ft_strlen(tmp);
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	if (*holder)
		ft_strdel (&holder);
	format->output = tmp;
	return ;
}
