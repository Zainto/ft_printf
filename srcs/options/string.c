/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 09:45:19 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 11:35:42 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unitest.h"

void	printf_s(t_format *format)
{
	printf("Doing String conversion !\n");
	format->output = ft_strdup(format->str);
	return ;
}
