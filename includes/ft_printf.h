/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:20:45 by cempassi          #+#    #+#             */
/*   Updated: 2018/12/18 22:57:26 by cempassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "-+0 #"
# define SIZE "hlL"
# define OTHER "csp"
# define INTEGER "diouxX"
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
void			format_init(t_format *format);
t_list			*parser(char *spec, va_list args);
#endif
