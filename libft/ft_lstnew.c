/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:29:40 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/07 13:32:58 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	if (content)
	{
		tmp->content = malloc(sizeof(*content));
		if (tmp->content == NULL)
		{
			free(tmp);
			return (NULL);
		}
		ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	else
	{
		tmp->content_size = 0;
		tmp->content = NULL;
	}
	tmp->next = NULL;
	return (tmp);
}
