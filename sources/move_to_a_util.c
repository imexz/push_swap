/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:09:25 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 19:14:24 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_s_stack_get_min_max_idx(struct s_stack *stack)
{
	struct s_stack_elem	*temp;
	int					*idx_arr;
	int					i;

	idx_arr = (int *)malloc(sizeof(int) * 2);
	if (idx_arr == NULL)
		ft_terminate("Error");
	temp = stack->head;
	idx_arr[0] = stack->head->idx;
	idx_arr[1] = stack->head->idx;
	i = 0;
	while (i < stack->size)
	{
		if (temp->idx > idx_arr[1])
			idx_arr[1] = temp->idx;
		else if (temp->idx < idx_arr[0])
			idx_arr[0] = temp->idx;
		i++;
		temp = temp->next;
	}
	return (idx_arr);
}

struct s_stack_elem	*ft_s_stack_find_fit_elem(struct s_stack *stack_a,
						int idx_b)
{
	struct s_stack_elem	*temp;
	struct s_stack_elem	*ret;
	int					*idx_arr_a;

	temp = stack_a->head;
	idx_arr_a = ft_s_stack_get_min_max_idx(stack_a);
	if ((idx_b < idx_arr_a[0] || idx_b > idx_arr_a[1]))
	{
		while (temp->idx != idx_arr_a[0])
			temp = temp->next;
	}
	else if (idx_b < temp->idx)
	{
		while (temp->prev->idx > idx_b)
			temp = temp->prev;
	}
	else if (idx_b > temp->idx)
	{
		while (temp->idx < idx_b)
			temp = temp->next;
	}
	ret = temp;
	free(idx_arr_a);
	return (ret);
}

int	ft_s_stack_get_rot_dir_n_moves(struct s_stack *stack,
		struct s_stack_elem *elem, int *moves)
{
	struct s_stack_elem	*temp;
	int					moves_rr;

	moves_rr = 0;
	*moves = 0;
	temp = stack->head;
	while (temp != elem)
	{
		temp = temp->next;
		(*moves)++;
	}
	temp = stack->head;
	while (temp != elem)
	{
		temp = temp->prev;
		moves_rr++;
	}
	if (*moves <= moves_rr)
		return (ROTATE);
	else
	{
		*moves = moves_rr;
		return (RE_ROT);
	}
}

void	ft_s_rot_info_list_add_rot_info(struct s_rot_info_list *list,
			struct s_rot_info *rot_info)
{
	if (list && rot_info)
	{
		if (list->head == NULL)
			list->head = rot_info;
		else
		{
			rot_info->next = list->head;
			list->head = rot_info;
		}
	}
	else
		ft_terminate("Error");
}

struct s_rot_info	*ft_s_rot_info_opt_elem(struct s_rot_info_list *list)
{
	struct s_rot_info	*opt_info;
	struct s_rot_info	*current;

	current = list->head;
	opt_info = current;
	while (current != NULL)
	{
		if (current->moves_a + current->moves_b
			< opt_info->moves_a + opt_info->moves_b)
			opt_info = current;
		else if (current->moves_a + current->moves_b
			== opt_info->moves_a + opt_info->moves_b)
		{
			if (opt_info->head_b->idx < current->head_b->idx)
				opt_info = current;
		}
		current = current->next;
	}
	return (opt_info);
}
