/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:07:19 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/07 15:13:32 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*first_buf;

	tmp = NULL;
	first_buf = NULL;
	if (lst)
	{
		tmp = (t_list *)malloc(sizeof(*f(lst)));
		if (tmp == NULL)
			return (NULL);
		tmp = f(lst);
		first_buf = tmp;
		while (lst->next)
		{
			tmp->next = (t_list *)malloc(sizeof(*f(lst->next)));
			tmp->next = f(lst->next);
			tmp = tmp->next;
			lst = lst->next;
		}
		tmp->next = NULL;
	}
	return (first_buf);
}
