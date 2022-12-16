/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 22:12:08 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 19:11:01 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_s_stack_swap(struct s_stack *stack)
{
	struct s_stack_elem	*old_head;
	struct s_stack_elem	*new_head;

	if (stack && stack->size >= 2)
	{
		old_head = stack->head;
		new_head = stack->head->next;
		old_head->prev->next = new_head;
		old_head->next->prev = old_head->prev;
		new_head->next->prev = old_head;
		old_head->next = new_head->next;
		new_head->next = old_head;
		old_head->prev = new_head;
		stack->head = new_head;
	}
}

struct s_stack_elem	*ft_s_stack_pop(struct s_stack *stack)
{
	struct s_stack_elem	*prev;
	struct s_stack_elem	*next;
	struct s_stack_elem	*temp;

	if (stack && stack->head != NULL)
	{
		temp = stack->head;
		if (stack->size > 1)
		{
			prev = stack->head->prev;
			next = stack->head->next;
			prev->next = next;
			next->prev = prev;
			stack->head = next;
		}
		else
			stack->head = NULL;
		temp->next = NULL;
		temp->prev = NULL;
		stack->size--;
		return (temp);
	}
	else
		return (NULL);
}

void	ft_s_stack_add_elem_front(struct s_stack *stack,
			struct s_stack_elem *elem)
{
	if (stack && elem)
	{
		if (stack->head == NULL)
		{
			stack->head = elem;
			elem->next = elem;
			elem->prev = elem;
		}
		else
		{
			elem->prev = stack->head->prev;
			stack->head->prev->next = elem;
			elem->next = stack->head;
			stack->head->prev = elem;
			stack->head = elem;
		}
		stack->size++;
	}
}

void	ft_s_stack_push(struct s_stack *from, struct s_stack *to)
{
	struct s_stack_elem	*popped;

	popped = ft_s_stack_pop(from);
	ft_s_stack_add_elem_front(to, popped);
}

void	ft_s_stack_rotate_x(struct s_stack *stack, int dir)
{
	if (stack && stack->head)
	{
		if (dir == ROTATE)
			stack->head = stack->head->next;
		else if (dir == RE_ROT)
			stack->head = stack->head->prev;
	}
}
