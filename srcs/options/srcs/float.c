/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:38:49 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 14:14:57 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/unitest.h"

void	printf_f(t_format *format)
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
	tmp = ft_strcpy(tmp, ft_itoa((int)format->f));
	tmp = ft_strcat(tmp, ".");
	while (++i < 6)
	{
		prev = (int)format->f;
		format->f *= 10;
		curr = ((int)format->f);
		tmp = ft_strcat(tmp, ft_itoa(curr - (prev * 10)));
	}
	dst = ft_strdup(tmp);
	free(tmp);
	format->output = dst;
	return ;
}
