/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:31:26 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/05 17:56:07 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*bufnext;

	tmp = *alst;
	while (tmp)
	{
		bufnext = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = bufnext;
	}
	*alst = NULL;
}
