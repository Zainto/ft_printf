/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:40:22 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/20 01:41:38 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		extract_flags(char **spec, t_format *format)
{
	if (!ft_strchr(FLAGS, **spec))
		return ;
	if (**spec == '-')
		format->flag_minus = 1;
	if (**spec == '+')
		format->flag_plus = 1;
	if (**spec == '0')
		format->flag_zero = 1;
	if (**spec == ' ')
		format->flag_space = 1;
	if (**spec == '#')
		format->flag_hashtag = 1;
	format->diff++;
	*spec += 1;
	return (extract_flags(spec, format));
}

void		extract_width(char **spec, t_format *format, va_list args)
{
	if (**spec == '*')
	{
		format->width = va_arg(args, int);
		if (format->width < 0)
		{
			format->flag_minus = 1;
			format->width *= -1;
		}
		*spec += 1;
		format->diff++;
	}
	else
	{
		format->width = ft_atoi(*spec);
		while (ft_isdigit(**spec))
		{
			*spec += 1;
			format->diff++;
		}
	}
}

void		extract_precision(char **spec, t_format *format, va_list args)
{
	*spec += 1;
	format->diff++;
	if (**spec == '*')
	{
		format->precision = va_arg(args, int);
		format->diff++;
		*spec += 1;
	}
	else if (ft_isdigit(**spec))
	{
		format->precision = ft_atoi(*spec);
		while (ft_isdigit(**spec))
		{
			*spec += 1;
			format->diff++;
		}
	}
}

void		extract_size(char **spec, t_format *format)
{
	int		len;

	len = ft_strspn(*spec, SIZE);
	format->size = ft_strsub(*spec, 0, len);
	format->diff += len;
	*spec += len;
}

void		extract_type(char **spec, t_format *format, va_list args)
{
	format->type = **spec;
	format->diff++;
	if (ft_strchr(OTHER, format->type))
		type_other(format, args);
	else if (ft_strchr(SIGNED, format->type))
		type_signed_integer(format, args);
	else if (ft_strchr(UNSIGNED, format->type))
		type_unsigned_integer(format, args);
	else if (ft_strchr(FLOAT, format->type))
		type_float(format, args);
}
