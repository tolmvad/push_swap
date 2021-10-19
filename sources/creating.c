/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:20:14 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/16 18:37:00 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*creat_arr(int argc, char **argv)
{
	int	*arr;
	int	flag;
	int	i;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	flag = 0;
	i = 1;
	while (i < argc)
	{
		arr[i - 1] = ft_atoi(argv[i], &flag);
		if (flag)
		{
			free(arr);
			terminate();
		}
		i++;
	}
	return (arr);
}

t_list	*creat_list(int *arr, int n)
{
	t_list	*list_a;
	int		i;

	list_a = NULL;
	i = 0;
	while (i < n)
	{
		ft_lstadd_back(&list_a, ft_lstnew(arr[i]));
		i++;
	}
	return (list_a);
}
