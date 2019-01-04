/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:20:45 by cempassi          #+#    #+#             */
/*   Updated: 2019/01/04 00:29:22 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"
# define FLAGS "-+0 #"
# define SIZE "hlLIjzt"
# define OTHER "csp%"
# define SIGNED "di"
# define UNSIGNED "bouxX"
# define FLOAT "f"
# define TYPE "cspdDibouUxXf"
# define TEN "0123456789"
# define BINARY "01"
# define OCTAL "01234567"
# define HEXA "0123456789abcdef"

typedef struct s_format	t_format;
typedef void			(*t_convert)(t_format *);

typedef union			u_args{
	char				character;
	unsigned char		u_character;
	short				s_short;
	unsigned short		u_short;
	int					integer;
	long int			l_integer;
	long long int		ll_integer;
	intmax_t			intmax;
	ssize_t				ssizet;
	unsigned int		u_integer;
	unsigned long		ul_integer;
	unsigned long long	ull_integer;
	uintmax_t			u_intmax;
	size_t				sizet;
	ptrdiff_t			ptrdiff;
	double				s_double;
	long double			l_double;
	char				*string;
	void				*pointer;
}						t_args;

struct					s_format{

	char				id;
	char				type;
	char				flag_minus;
	char				flag_plus;
	char				flag_zero;
	char				flag_space;
	char				flag_hashtag;
	int					width;
	int					precision;
	unsigned int		diff;
	char				*size;
	char				*output;
	t_convert			convert;
	t_args				arg;
};

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);
int						ft_asprintf(char **dst, const char *format, ...);
int						ft_vdprintf(const char *format, va_list args, int fd);
int						ft_vasprintf(char **dst, const char *format,\
						va_list args);

t_list					*format_list(const char *format, va_list args);
void					format_delete(void **data);
int						doutput(const char *format, t_list *node, int fd);
int						soutput(char **dst, const char *fmt, t_list *node);

void					extract_flags(char **spec, t_format *format);
void					extract_size(char **spec, t_format *format);
void					extract_width(char **spec, t_format *format,\
						va_list args);
void					extract_precision(char **spec, t_format *format,\
						va_list args);
void					extract_type(char **spec, t_format *format,\
						va_list args);

void					type_signed_integer(t_format *format, va_list args);
void					type_unsigned_integer(t_format *format, va_list args);
void					type_float(t_format *format, va_list args);
void					type_other(t_format *format, va_list args);

char					*precision(t_format *format, char *tmp);
char					*width(t_format *format, char *tmp);
char					*prefix(t_format *format, char *tmp);
char					*unsigned_convert(t_format *format);

void					pointer(t_format *format);
void					string(t_format *format);
void					digit(t_format *format);
void					character(t_format *format);
void					u_integer(t_format *format);
void					binary(t_format *format);
void					octal(t_format *format);
void					hexadecimal(t_format *format);
void					doubles(t_format *format);

#endif
