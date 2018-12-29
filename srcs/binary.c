/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 22:11:53 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/29 03:45:12 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	binary(t_format *format)
{
	char	*tmp;
	char	*holder;
	int		len;

	tmp = unsigned_convert(format);
	tmp = *(holder = tmp) ? ft_convert_base(tmp, TEN, HEXA) : tmp;
	if (*holder)
		ft_strdel (&holder);
	len = ft_strlen(tmp);
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	if (format->flag_hashtag)
	{
		holder = tmp;
		tmp = ft_strjoin("0b", tmp);
		ft_strdel (&holder);
	}
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	format->output = tmp;
	return ;
}
