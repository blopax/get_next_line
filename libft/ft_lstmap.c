/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:10:13 by pclement          #+#    #+#             */
/*   Updated: 2017/11/16 18:55:29 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh_lst;
	t_list	*fresh_lst_start;
	
	if (!(lst && f))
		return (NULL);
	fresh_lst = ft_lstnew(lst->content, lst->content_size);
	fresh_lst = f(fresh_lst);
	fresh_lst_start = fresh_lst;
	lst = lst->next;
	while (lst)
	{
		fresh_lst->next = ft_lstnew(lst->content, lst->content_size);
		fresh_lst->next = f(fresh_lst->next);
		fresh_lst = fresh_lst->next;
		lst = lst->next;
	}
	return (fresh_lst_start);
}
