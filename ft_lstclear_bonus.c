/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:16:32 by thomarna          #+#    #+#             */
/*   Updated: 2024/10/12 13:14:27 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*node_next;

	if (lst == NULL || del == NULL || *lst == NULL)
		return ;
	node = *lst;
	while (node)
	{
		node_next = node->next;
		ft_lstdelone(node, del);
		node = node_next;
	}
	*lst = NULL;
}
