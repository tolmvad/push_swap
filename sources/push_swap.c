/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:18:57 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/06 16:59:27 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int		*arr;
	t_list	*list_a;

	if (argc >= 2)
	{
		check_input(argc, argv);
		arr = creat_arr(argc, argv);
		is_doubles(arr, argc - 1);
		list_a = creat_list(arr, argc - 1);
		ft_sort(arr, argc - 1);
		add_index(list_a, arr);
		markup_head(list_a);
		push_swap(list_a);
	}
	return (0);
}

void	push_swap(t_list *list_a)
{
	t_list	*list_b;

	list_b = NULL;
	solve_a(&list_a, &list_b);
	solve_b(&list_a, &list_b);
	align(&list_a);
	free_list(list_a);
}
