/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:26:03 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 22:59:13 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexadecimal(t_format *format)
{
	char	*dst;
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strequ(format->size, "l"))
		tmp = ft_ullitoa(format->arg.ul_integer);
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		tmp = ft_ullitoa(format->arg.ull_integer);
	else
		tmp = ft_ullitoa(format->arg.u_integer);
	dst = ft_convert_base(tmp, TEN, HEXA);
	if (format->type == 'X')
	{
		while ((dst[i] = ft_toupper(dst[i])))
			i++;
	}
	ft_strdel(&tmp);
	format->output = dst;
	return ;
}
