/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:03:31 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/23 15:29:50 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_s_node_check_for_duplicates(struct s_node *head)
{
	struct s_node	*iterator1;
	struct s_node	*iterator2;

	iterator1 = head;
	while (iterator1->next != head)
	{
		iterator2 = iterator1->next;
		while (iterator2 != iterator1)
		{
			if (iterator2->numb == iterator1->numb)
			{
				ft_s_node_loop_clear(&head);
				ft_terminate("Error");
			}
			iterator2 = iterator2->next;
		}
		iterator1 = iterator1->next;
	}
}

int	ft_is_sorted(struct s_node *stack_a, struct s_node *stack_b)
{
	struct s_node	*temp;

	if (stack_b)
		return (0);
	temp = stack_a;
	while (temp->next != stack_a)
	{
		if (temp->next->numb < temp->numb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_rotate_both(struct s_node **head_a, struct s_node **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
}

void	ft_rev_rotate_both(struct s_node **head_a, struct s_node **head_b)
{
	ft_rev_rotate(head_a);
	ft_rev_rotate(head_b);
}

void	ft_execute(struct s_node **head_a, struct s_node **head_b, char *line)
{
	if (ft_strcmp(line, "ra\n"))
		ft_rotate(head_a);
	else if (ft_strcmp(line, "rb\n"))
		ft_rotate(head_b);
	else if (ft_strcmp(line, "rr\n"))
		ft_rotate_both(head_a, head_b);
	else if (ft_strcmp(line, "rra\n"))
		ft_rev_rotate(head_a);
	else if (ft_strcmp(line, "rrb\n"))
		ft_rev_rotate(head_b);
	else if (ft_strcmp(line, "rrr\n"))
		ft_rev_rotate_both(head_a, head_b);
	else if (ft_strcmp(line, "sa\n"))
		ft_swap(head_a);
	else if (ft_strcmp(line, "sb\n"))
		ft_swap(head_b);
	else if (ft_strcmp(line, "pa\n"))
		ft_push(head_b, head_a);
	else if (ft_strcmp(line, "pb\n"))
		ft_push(head_a, head_b);
	else
		ft_terminate("Error");
}
