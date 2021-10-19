/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:18:21 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/16 18:40:19 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* to malloc, free, exit */
# include <stdlib.h>

/* to write, read */
# include <unistd.h>

/* to get_next_line */
# include "../gnl/get_next_line.h"

typedef struct s_list
{
	int				value;
	int				index;
	int				head;
	int				tag;
	struct s_list	*next;
}t_list;

typedef struct s_max
{
	int	index;
	int	len;
	int	current;
}t_max;

typedef struct s_move
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}t_move;

/* push_swap.c */
void	push_swap(t_list *list_a);

/* checker.c */
void	checker(t_list *list_a);

/* moves.c */
void	init_mv(t_move *mv);
void	do_move(t_list **list_a, t_list **list_b, t_move mv);
int		move_a(t_list *list_a, t_list *list_b);
int		move_b(t_list *lst, t_list *elem);

/* need.c */
int		need_rb(t_list *lst);
int		need_sa(t_list *lst);

/* solve_a.c*/
void	solve_a(t_list **list_a, t_list **list_b);

/* solve_b.c*/
void	solve_b(t_list **list_a, t_list **list_b);

/* align.c */
void	align(t_list **lst);

/* free.c */
void	free_list(t_list *lst);

/* index.c */
int		idx_last(t_list *lst);
int		idx_min(t_list *lst);

/* error.c */
void	terminate(void);
void	command_err(t_list *list_a, t_list *list_b);

/* checks.c */
void	check_input(int argc, char **argv);
int		is_digit(char *str);
void	is_doubles(int *arr, int n);

/* markup.c */
void	markup(t_list *lst);
void	markup_clean(t_list *lst);

/* markup_head.c */
void	markup_head(t_list *lst);

/* positions.c */
void	add_index(t_list *lst, int *arr);

/* creating.c */
int		*creat_arr(int argc, char **argv);
t_list	*creat_list(int *arr, int n);

/* swap.c */
void	swap(t_list *lst);
void	swap_d(t_list *list_a, t_list *list_b);

/* push.c */
void	pa(t_list **lst1, t_list **lst2, int w);
void	pb(t_list **lst1, t_list **lst2, int w);

/* rotate.c */
void	rotate(t_list **lst, int rev);
void	ra(t_list **lst, int w);
void	rb(t_list **lst, int w);
void	rra(t_list **lst, int w);
void	rrb(t_list **lst, int w);

/* double rotate.c */
void	rr(t_list **lst1, t_list **lst2, int *ra, int *rb);
void	rrr(t_list **lst1, t_list **lst2, int *rra, int *rrb);
void	rr_nw(t_list **list_a, t_list **list_b);
void	rrr_nw(t_list **list_a, t_list **list_b);

/* functoins */
int		ft_atoi(const char *s, int *flag);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstake_first(t_list **lst);
t_list	*ft_lstake_last(t_list **lst);
int		ft_lstlen(t_list *lst);
void	ft_sort(int *arr, int n);
int		ft_strncmp(const char *s1, const char *s2);

#endif
