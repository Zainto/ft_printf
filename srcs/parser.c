/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:40:22 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 01:00:35 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static void	extract_flags(char **spec, t_format *format)
{
	if (!ft_strchr(FLAGS,**spec))
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

static void	extract_width(char **spec, t_format *format, va_list args)
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

static void	extract_precision(char **spec, t_format *format, va_list args)
{
	*spec += 1;
	format->diff++;
	if (**spec == '*')
	{
		format->precision =  va_arg(args, int);
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

static void	extract_size(char **spec, t_format *format)
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
	if ((format->type == 'd' && ft_strequ(format->size , "hh"))
			|| format->type == 'c')
	{
		format->arg.integer = va_arg(args, int);	
		format->arg.character = format->arg.integer;
	}
	if (format->type == 's')
		format->arg.string = ft_strdup(va_arg(args, char *));	
	if (format->type == 'p')
		format->arg.pointer = va_arg(args, void *);	
	if (format->type == 'p')
		format->arg.pointer = va_arg(args, void *);	
}

t_list		*parser(char *spec, va_list args)
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
