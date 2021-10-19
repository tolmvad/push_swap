/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:20:17 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/06 18:44:09 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	terminate(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	command_err(t_list *list_a, t_list *list_b)
{
	if (list_a)
		free_list(list_a);
	if (list_b)
		free_list(list_b);
	terminate();
}
