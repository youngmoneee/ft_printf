/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:41:06 by youngpar          #+#    #+#             */
/*   Updated: 2021/07/03 03:32:09 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include "ft_struct.h"
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>

int			ft_printf(const char *str, ...);
int			is_flag(char c);
const char	*ft_check_obj(const char *str, va_list *ap, int *len);
const char	*ft_check_flag(const char *str, t_option *opt);
const char	*ft_check_width(const char *str, t_option *opt, va_list *ap);
const char	*ft_check_precision(const char *str, t_option *opt, va_list *ap);
const char	*ft_check_length(const char *str, t_option *opt);
const char	*ft_check_type(const char *str, t_option *opt);

size_t		ft_print_c(t_option *opt, va_list *ap);
size_t		ft_print_per(t_option *opt);
size_t		ft_print_s(t_option *opt, va_list *ap);

t_ull		ft_get_uvalue(t_option *opt, long long value);
int			ft_print_d(t_option *opt, va_list *ap);
int			ft_numlen(long long value, t_option *opt, t_number *num);
t_ll		ft_get_value(t_option *opt, va_list *ap);
#endif
