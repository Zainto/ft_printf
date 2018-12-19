/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:28:43 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 02:18:25 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		ft_printf(const char * format, ...)
{
	va_list		args;
	int			result;

	va_start(args, format);
	result = ft_vprintf(format, args);
	va_end(args);
	return (result);
}
