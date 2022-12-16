/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:39:42 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 11:37:20 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_sorted_size_idx(struct s_stack_elem *elem, struct s_stack *stack)
{
	int					sorted;
	int					i;
	int					idx;
	struct s_stack_elem	*temp_1;

	sorted = 1;
	temp_1 = elem;
	temp_1->hold = 1;
	idx = temp_1->idx;
	temp_1 = temp_1->next;
	i = 1;
	while (i < stack->size - 1)
	{
		if (temp_1->idx == idx + 1)
		{
			temp_1->hold = 1;
			sorted++;
			idx++;
		}
		else
			temp_1->hold = 0;
		temp_1 = temp_1->next;
		i++;
	}
	return (sorted);
}

int	ft_get_sorted_size_grt(struct s_stack_elem *elem, struct s_stack *stack)
{
	int					sorted;
	int					i;
	int					num;
	struct s_stack_elem	*temp;

	sorted = 1;
	temp = elem;
	temp->hold = 1;
	num = temp->num;
	temp = temp->next;
	i = 1;
	while (i < stack->size)
	{
		if (temp->num > num)
		{
			temp->hold = 1;
			sorted++;
			num = temp->num;
		}
		else
			temp->hold = 0;
		temp = temp->next;
		i++;
	}
	return (sorted);
}

void	ft_s_stack_get_sorted_head(struct s_stack *stack,
		int (*ft_get_sorted_size)(struct s_stack_elem *,
		struct s_stack *))
{
	int					i;
	int					temp_sorted;
	struct s_stack_elem	*temp;

	i = 0;
	temp = stack->head;
	while (i < stack->size)
	{
		temp_sorted = ft_get_sorted_size(temp, stack);
		if (stack->sorted_head == NULL
			 || temp_sorted > stack->sorted
			 || (temp_sorted == stack->sorted
				 && (temp->num < stack->sorted_head->num)))
		{
			stack->sorted = temp_sorted;
			stack->sorted_head = temp;
		}
		temp = temp->next;
		i++;
	}
	ft_get_sorted_size(stack->sorted_head, stack);
}
