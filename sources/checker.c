/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:05:55 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/06 20:11:30 by bcaffere         ###   ########.fr       */
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
		free(arr);
		checker(list_a);
	}
	return (0);
}

static void	do_command(t_list **list_a, t_list **list_b, char *str)
{
	if (!ft_strncmp(str, "sa"))
		swap(*list_a);
	else if (!ft_strncmp(str, "sb"))
		swap(*list_b);
	else if (!ft_strncmp(str, "ss"))
		swap_d(*list_a, *list_b);
	else if (!ft_strncmp(str, "pa"))
		pa(list_a, list_b, 0);
	else if (!ft_strncmp(str, "pb"))
		pb(list_a, list_b, 0);
	else if (!ft_strncmp(str, "ra"))
		ra(list_a, 0);
	else if (!ft_strncmp(str, "rb"))
		rb(list_b, 0);
	else if (!ft_strncmp(str, "rr"))
		rr_nw(list_a, list_b);
	else if (!ft_strncmp(str, "rra"))
		rra(list_a, 0);
	else if (!ft_strncmp(str, "rrb"))
		rrb(list_b, 0);
	else if (!ft_strncmp(str, "rrr"))
		rrr_nw(list_a, list_b);
	else
		command_err(*list_a, *list_b);
}

static int	good_solution(t_list *lst)
{
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	checker(t_list *list_a)
{
	t_list	*list_b;
	char	*line;

	list_b = NULL;
	while (get_next_line(0, &line) > 0)
	{
		do_command(&list_a, &list_b, line);
		free(line);
	}
	if (good_solution(list_a))
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	if (list_a)
		free_list(list_a);
	if (list_b)
		free_list(list_b);
}
