/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 03:32:50 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/10 19:00:30 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*curr;

	if (!lst || !f)
		return ((void *)0);
	if (!(new = ft_lstnew(f(lst->content))))
		return ((void *)0);
	lst = lst->next;
	curr = new;
	while (lst)
	{
		if (!(curr->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			return ((void *)0);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (new);
}
