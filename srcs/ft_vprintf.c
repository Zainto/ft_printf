/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:24:06 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/18 19:41:20 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int				ft_vprintf(const char *format, va_list args)
{
	int				result;
	t_list			*lst;

	result = 0;
	lst = format_list(format, args);
	result = format_output(format, lst, 0);
	return (result);
}
