/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:38:49 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/20 00:10:19 by cempassi         ###   ########.fr       */
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
	while (++i < format->precision)
	{
		prev = (int)format->arg.s_double;
		format->arg.s_double *= 10;
		curr = ((int)format->arg.s_double);
		tmp = ft_strcat(tmp, ft_itoa(curr - (prev * 10)));
	}
	dst = ft_strdup(tmp);
	ft_strdel(&tmp);
	format->output = dst;
	return ;
}