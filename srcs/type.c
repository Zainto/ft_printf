/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 01:10:05 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 22:53:01 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	type_signed_integer(t_format *format, va_list args)
{
	if (format->size == NULL)
		format->arg.integer = va_arg(args, int);
	else if (ft_strequ(format->size, "hh"))
	{
		format->arg.integer = va_arg(args, int);
		format->arg.character = (char)format->arg.integer;
	}
	else if (ft_strequ(format->size, "h"))
	{
		format->arg.integer = va_arg(args, int);
		format->arg.s_short = (short)format->arg.integer;
	}
	else if (ft_strequ(format->size, "l"))
		format->arg.l_integer = va_arg(args, long int);
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		format->arg.ll_integer = va_arg(args, long long int);
	format->convert = digit;
}

t_convert	 unsigned_convert(t_format *format)
{
	if (format->type == 'b')
		return (octal);
	if (format->type == 'o')
		return (octal);
	if (format->type == 'x' || format->type == 'X')
		return (hexadecimal);
	else
		return (u_integer);
}

void	type_unsigned_integer(t_format *format, va_list args)
{
	if (format->size == NULL)
		format->arg.u_integer = va_arg(args, int);
	else if (ft_strequ(format->size, "hh"))
	{
		format->arg.u_integer = va_arg(args, int);
		format->arg.u_character = (unsigned char)format->arg.u_integer;
	}
	else if (ft_strequ(format->size, "h"))
	{
		format->arg.u_integer = va_arg(args, unsigned int);
		format->arg.u_short = (unsigned short)format->arg.u_integer;
	}
	else if (ft_strequ(format->size, "l"))
		format->arg.ul_integer = va_arg(args, unsigned long int);
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		format->arg.ull_integer = va_arg(args, unsigned long long int);
	format->convert = unsigned_convert(format);
}

void	type_float(t_format *format, va_list args)
{
	if (format->size == NULL)
	{
		format->arg.s_double = va_arg(args, double);
		format->arg.s_float = format->arg.s_double;
	}
}

void	type_other(t_format *format, va_list args)
{
	if (format->type == 'c')
	{
		format->arg.integer = va_arg(args, int);
		format->arg.character = format->arg.integer;
		format->convert = character;
	}
	if (format->type == 's')
	{
		format->arg.string = ft_strdup(va_arg(args, char *));
		format->convert = string;
	}
	if (format->type == 'p')
	{
		format->arg.pointer = va_arg(args, void *);
		format->convert = pointer;
	}
}
