/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 22:07:26 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 11:01:34 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_s_stack_align_stack_a_get_dir(struct s_stack *stack)
{
	struct s_stack_elem	*temp;
	int					moves_r;
	int					moves_rr;

	temp = stack->head;
	moves_r = 0;
	while (temp->idx != 0)
	{
		temp = temp->next;
		moves_r++;
	}
	temp = stack->head;
	moves_rr = 0;
	while (temp->idx != 0)
	{
		temp = temp->next;
		moves_rr++;
	}
	if (moves_r < moves_rr)
		return (ROTATE);
	else
		return (RE_ROT);
}

void	ft_s_stack_final_sort_a(struct s_stack *stack,
		struct s_action_list *list)
{
	int	dir;

	dir = ft_s_stack_align_stack_a_get_dir(stack);
	if (dir == ROTATE)
	{
		while (stack->head->idx != 0)
		{
			ft_s_stack_rotate_x(stack, dir);
			ft_s_action_list_add_action(list, "ra");
		}
	}
	else
	{
		while (stack->head->idx != 0)
		{
			ft_s_stack_rotate_x(stack, dir);
			ft_s_action_list_add_action(list, "rra");
		}
	}
}
