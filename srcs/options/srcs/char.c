/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:36:59 by nrechati          #+#    #+#             */
/*   Updated: 2018/12/19 14:16:39 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/unitest.h"

void	printf_c(t_format *format)
{
	format->output = ft_strdup(&format->c);
	return ;
}
