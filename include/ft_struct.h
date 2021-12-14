/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:41:06 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/14 19:20:28 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

typedef unsigned long long	t_ull;
typedef long long			t_ll;

typedef struct s_option
{
	int			flags;
	int			width;
	int			precision;
	int			length;
	int			type;
}				t_option;

typedef struct s_number
{
	int			lft;
	int			lft_z;
	int			flglen;
	int			numlen;
	t_ll		origin;
	t_ull		value;
}				t_number;

typedef struct s_return_n
{
	char		*cp;
	short		*sp;
	long		*lp;
	t_ll		*llp;
}				t_return_n;
#endif
