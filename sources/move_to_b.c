/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:06:45 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 19:15:24 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_s_stack_push_helpful(struct s_stack *stack)
{
	struct s_stack_elem	*temp;
	int					i;

	i = 0;
	temp = stack->head;
	while (i < stack->size)
	{
		if (temp->hold == 0)
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}

int	ft_s_stack_swap_helpful(struct s_stack *stack,
		int (*ft_get_sorted_size)(struct s_stack_elem *, struct s_stack *))
{
	int	temp_sorted;

	if (stack && stack->size >= 2)
	{
		ft_s_stack_swap(stack);
		temp_sorted = ft_get_sorted_size(stack->sorted_head, stack);
		ft_s_stack_swap(stack);
		ft_get_sorted_size(stack->sorted_head, stack);
		if (temp_sorted > stack->sorted)
			return (1);
	}
	return (0);
}

struct s_stack	*ft_move_elements_to_b(struct s_stack *stack_a,
				int (*ft_get_sorted_size)(struct s_stack_elem *,
				struct s_stack *), struct s_action_list *list)
{
	struct s_stack	*stack_b;

	stack_b = ft_s_stack_init();
	while (ft_s_stack_push_helpful(stack_a))
	{
		if (ft_s_stack_swap_helpful(stack_a, ft_get_sorted_size))
		{
			ft_s_stack_swap(stack_a);
			stack_a->sorted = ft_get_sorted_size(stack_a->sorted_head, stack_a);
			ft_s_action_list_add_action(list, "sa");
		}
		else if (stack_a->head->hold == 0)
		{
			ft_s_stack_push(stack_a, stack_b);
			ft_s_action_list_add_action(list, "pb");
		}
		else
		{
			ft_s_stack_rotate_x(stack_a, ROTATE);
			ft_s_action_list_add_action(list, "ra");
		}
	}
	return (stack_b);
}

struct s_action_list	*ft_s_stack_solve(struct s_stack *stack_a,
						int (*ft_get_sorted_size)
						(struct s_stack_elem *, struct s_stack *))
{
	struct s_action_list	*list;
	struct s_stack			*stack_b;

	list = ft_s_action_list_create();
	stack_b = ft_move_elements_to_b(stack_a, ft_get_sorted_size, list);
	ft_move_elements_back_to_a(stack_a, stack_b, list);
	ft_s_stack_final_sort_a(stack_a, list);
	return (list);
}
