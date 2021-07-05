/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:39:14 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/09 20:09:50 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	idx;
	unsigned int	len;

	if (!s || !f)
		return ((void *)0);
	len = ft_strlen(s);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return ((void *)0);
	idx = 0;
	while (idx < len)
	{
		ret[idx] = (*f)(idx, (char)(s[idx]));
		idx++;
	}
	ret[len] = 0;
	return (ret);
}
