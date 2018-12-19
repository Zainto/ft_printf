/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:20:45 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 23:01:12 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# define FLAGS "-+0 #"
# define SIZE "hlL"
# define OTHER "csp%"
# define SIGNED "di"
# define UNSIGNED "bouxX"
# define FLOAT "f"
# define TYPE "cspdibouxXf"
# define TEN "0123456789"
# define BINARY "01"
# define OCTAL "01234567"
# define HEXA "0123456789abcdef"

typedef struct s_format t_format;
typedef void (*t_convert)(t_format *);

typedef union	u_args{
	char					character;
	unsigned char			u_character;
	short					s_short;
	unsigned short			u_short;
	int						integer;
	long int				l_integer;
	long long int			ll_integer;
	unsigned int 			u_integer;
	unsigned long int 		ul_integer;
	unsigned long long int	ull_integer;
	float					s_float;
	double					s_double;
	long double				l_double;
	char					*string;
	void					*pointer;
}				t_args;

struct s_format{

	char			id;
	char			type;
	char			flag_minus;
	char			flag_plus;
	char			flag_zero;
	char			flag_space;
	char			flag_hashtag;
	int				width;
	int				precision;
	unsigned int	diff;
	char			*size;
	char			*output;
	t_convert		convert;
	t_args			arg;
};

int				ft_printf(const char * format, ...);
int				ft_vprintf(const char *format, va_list args);

t_list			*format_list(const char *format, va_list args);
int				output(const char *format, t_list *current);

void			extract_flags(char **spec, t_format *format);
void			extract_width(char **spec, t_format *format, va_list args);
void			extract_precision(char **spec, t_format *format, va_list args);
void			extract_size(char **spec, t_format *format);
void			extract_type(char **spec, t_format *format, va_list args);

void			type_signed_integer(t_format *format, va_list args);
void			type_unsigned_integer(t_format *format, va_list args);
void			type_float(t_format *format, va_list args);
void			type_other(t_format *format, va_list args);

void			pointer(t_format *format);
void			string(t_format *format);
void			digit(t_format *format);
void			character(t_format *format);
void			u_integer(t_format *format);
void			binary(t_format *format);
void			octal(t_format *format);
void			hexadecimal(t_format *format);
#endif
