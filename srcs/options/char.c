/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:36:59 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 09:48:37 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unitest.h"

void	printf_c(t_format *format)
{
	printf("Doing Char conversion !\n");
	format->output = ft_strdup(&format->c);
	return ;
}
