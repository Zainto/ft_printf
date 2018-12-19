/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:20:45 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/19 02:49:52 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "-+0 #"
# define SIZE "hlL"
# define OTHER "csp"
# define SIGNED "di"
# define UNSIGNED "ouxX"
# define FLOAT "f"
# define TYPE "cspdiouxXf"
# include "libft.h"

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

typedef struct	s_format{

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
	char			(*convert)(struct s_format *);
	t_args			arg;
}				t_format;	

int				ft_printf(const char * format, ...);
int				ft_vprintf(const char *format, va_list args);

t_list			*format_list(const char *format, va_list args);
int				format_output(const char *format, t_list *current, int result);
char			*printformat(t_format *format);

void			extract_flags(char **spec, t_format *format);
void			extract_width(char **spec, t_format *format, va_list args);
void			extract_precision(char **spec, t_format *format, va_list args);
void			extract_size(char **spec, t_format *format);
void			extract_type(char **spec, t_format *format, va_list args);

void			type_signed_integer(t_format *format, va_list args);
void			type_unsigned_integer(t_format *format, va_list args);
void			type_float(t_format *format, va_list args);
void			type_other(t_format *format, va_list args);
#endif
