/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:20:49 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/04 16:20:14 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_idx(int *arr, int x)
{
	int	i;

	i = 0;
	while (arr[i] != x)
		i++;
	return (i);
}

void	add_index(t_list *lst, int *arr)
{
	while (lst)
	{
		lst->index = find_idx(arr, lst->value);
		lst = lst->next;
	}
	free(arr);
}
