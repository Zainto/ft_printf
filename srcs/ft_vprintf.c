/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:24:06 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 02:24:08 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

t_list			*parser(char *spec, va_list args)
{
	t_format	format;
	t_list		*node;

	format_init(&format);
	spec++;
	format.diff += 1;
	if (ft_strchr(FLAGS, *spec))
		extract_flags(&spec, &format);
	if (ft_isdigit(*spec) || *spec == '*')
		extract_width(&spec, &format, args);
	if (*spec == '.')
		extract_precision(&spec, &format, args);
	if (ft_strchr(SIZE, *spec))
		extract_size(&spec, &format);
	if (ft_strchr(TYPE, *spec))
		extract_type(&spec, &format, args);
	node = ft_lstnew(&format, sizeof(t_format));
	return (node);
}

int				ft_vprintf(const char *format, va_list args)
{
	int				result;
	t_list			*lst;

	result = 0;
	if (!(lst = format_list(format, args)))
		return (-1);
	result = format_output(format, lst, 0);
	return (result);
}
