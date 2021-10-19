/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:21:04 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/05 21:05:47 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list **lst, int rev)
{
	t_list	*tmp;

	if (rev)
	{
		tmp = ft_lstake_last(lst);
		ft_lstadd_front(lst, tmp);
	}
	else
	{
		tmp = ft_lstake_first(lst);
		ft_lstadd_back(lst, tmp);
	}
}

void	ra(t_list **lst, int w)
{
	rotate(lst, 0);
	if (w)
		write(1, "ra\n", 3);
}

void	rb(t_list **lst, int w)
{
	rotate(lst, 0);
	if (w)
		write(1, "rb\n", 3);
}

void	rra(t_list **lst, int w)
{
	rotate(lst, 1);
	if (w)
		write(1, "rra\n", 4);
}

void	rrb(t_list **lst, int w)
{
	rotate(lst, 1);
	if (w)
		write(1, "rrb\n", 4);
}
