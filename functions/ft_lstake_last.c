/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstake_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:19:48 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/03 19:19:51 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstake_last(t_list **lst)
{
	t_list	*tmp;
	t_list	*run;

	if (!(*lst))
		return (NULL);
	if (!(*lst)->next)
	{
		tmp = *lst;
		*lst = NULL;
		return (tmp);
	}
	run = *lst;
	while (run->next->next)
		run = run->next;
	tmp = run->next;
	run->next = NULL;
	return (tmp);
}
