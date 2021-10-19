/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstake_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:19:45 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/03 19:19:46 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstake_first(t_list **lst)
{
	t_list	*tmp;

	if (!(*lst))
		return (NULL);
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	return (tmp);
}
