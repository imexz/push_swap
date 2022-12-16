/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:27:13 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/24 23:41:45 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_terminate(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	ft_s_stack_elem_add_back(struct s_stack *stack,
			struct s_stack_elem *elem)
{
	int					i;
	struct s_stack_elem	*temp;

	if (stack->head == NULL)
	{
		elem->next = elem;
		elem->prev = elem;
		stack->head = elem;
	}
	else
	{
		temp = stack->head;
		i = 1;
		while (i < stack->size)
		{
			i++;
			temp = temp->next;
		}
		temp->next = elem;
		elem->prev = temp;
		elem->next = stack->head;
		stack->head->prev = elem;
	}
	stack->size++;
}

struct s_stack_elem	*ft_s_stack_elem_create(long numb)
{
	struct s_stack_elem	*elem;

	elem = (struct s_stack_elem *)malloc(sizeof(struct s_stack_elem));
	if (elem == NULL)
		ft_terminate("Error");
	elem->num = numb;
	elem->idx = -1;
	elem->hold = 0;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

struct s_stack	*ft_s_stack_init(void)
{
	struct s_stack	*stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (stack == NULL)
		ft_terminate("Error");
	stack->head = NULL;
	stack->sorted_head = NULL;
	stack->size = 0;
	stack->sorted = 0;
	return (stack);
}
