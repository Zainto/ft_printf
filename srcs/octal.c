/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:47:35 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/28 17:49:48 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	octal(t_format *format)
{
	char	*tmp;
	char	*holder;
	int		len;
	int		i;

	i = 0;
	tmp = unsigned_convert(format);
	holder = tmp;
	tmp = ft_convert_base(tmp, TEN, OCTAL);
	ft_strdel (&holder);
	len = ft_strlen(tmp);
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	if (format->flag_hashtag && !format->precision)
	{
		holder = tmp;
		tmp = ft_strjoin("0", tmp);
		ft_strdel (&holder);
	}
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	format->output = tmp;
	return ;
}
