/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:54:12 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 02:54:55 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef	struct	s_flags
{
	char	conv;
	char	*attr;
	int		field;
	int		pre;
	char	*modif;
	int		count;
}				t_flags;

char			*ft_itoa_base(size_t n, int base);
int				ft_conv(va_list ap, t_flags *fl);
int				ft_clone(va_list ap, const char *format, int i, int ret);
int				ft_pointer(va_list ap, t_flags *fl);
int				ft_zero(t_flags *fl);
int				ft_percent(t_flags *fl);
char			*ft_min(char *str, t_flags *fl, int a);
int				ft_nega(char *str, t_flags *fl);
char			*ft_is_pre(char *str, t_flags *fl);
int				ft_string(char *str, t_flags *fl, int a);
char			*ft_fill_0(int n);
char			*ft_fill(int n);
int				ft_attr_id(char *str, t_flags *fl);
int				ft_attr_ux(char *str, t_flags *fl);
void			ft_upper(char *str);
int				ft_mod_id2(va_list ap, t_flags *fl);
int				ft_mod_id(va_list ap, t_flags *fl);
int				ft_mod_uns2(va_list ap, t_flags *fl);
int				ft_mod_uns(va_list ap, t_flags *fl);
int				ft_putarg(va_list ap, t_flags *fl);
int				ft_printf(const char *format, ...);
t_flags			ft_init_flags(void);
int				ft_parsing(const char *format, t_flags *fl);

#endif
