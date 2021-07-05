/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:12:48 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/10 21:41:42 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	idx;

	if (!s)
		return ((void *)0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return ((void *)0);
	idx = 0;
	while (idx < len && s[start + idx])
	{
		ret[idx] = s[start + idx];
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}
