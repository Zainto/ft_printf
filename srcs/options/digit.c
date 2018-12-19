/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:38:30 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 11:40:10 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unitest.h"

void	printf_d(t_format *format)
{
	printf("Doing Digit conversion !\n");
	format->output = ft_itoa(format->d);
	return ;
}
