/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:41:06 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/14 21:21:30 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_opt(t_option *opt, va_list *ap)
{
	if (opt->type == 'c')
		return (ft_print_c(opt, ap));
	else if (opt->type == '%')
		return (ft_print_per(opt));
	else if (opt->type == 's')
		return (ft_print_s(opt, ap));
	else if (opt->type == 'd' || opt->type == 'i' || opt->type == 'u')
		return (ft_print_d(opt, ap));
	else if (opt->type == 'x' || opt->type == 'X' || opt->type == 'p')
		return (ft_print_d(opt, ap));
	return (0);
}

static void	ft_print_n(t_option *opt, va_list *ap, int *len)
{
	t_return_n	nret;

	ft_memset(&nret, 0, sizeof(t_return_n));
	if (opt->length == 1)
	{
		nret.lp = va_arg(*ap, long *);
		*nret.lp = (long)(*len);
	}
	else if (opt->length == 2)
	{
		nret.sp = va_arg(*ap, short *);
		*nret.sp = (short)(*len);
	}
	else if (opt->length == 3)
	{
		nret.llp = va_arg(*ap, long long *);
		*nret.llp = (long long)(*len);
	}
	else if (opt->length == 4)
	{
		nret.cp = va_arg(*ap, char *);
		*nret.cp = (char)(*len);
	}
}

const char	*ft_check_obj(const char *str, va_list *ap, int *len)
{
	t_option	opt;
	int			*n;

	ft_memset(&opt, 0, sizeof(t_option));
	opt.precision = -1;
	str = ft_check_flag(str, &opt);
	str = ft_check_width(str, &opt, ap);
	str = ft_check_precision(str, &opt, ap);
	str = ft_check_length(str, &opt);
	str = ft_check_type(str, &opt);
	if (opt.type == 'n')
	{
		if (opt.length)
			ft_print_n(&opt, ap, len);
		else
		{
			n = va_arg(*ap, int *);
			*n = *len;
		}
	}
	*len += ft_print_opt(&opt, ap);
	return (str);
}
