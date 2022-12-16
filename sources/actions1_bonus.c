/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:05:10 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/23 15:29:11 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_swap(struct s_node **head)
{
	struct s_node	*old_head;
	struct s_node	*new_head;

	if (ft_s_node_lst_size(*head) < 2)
		return ;
	old_head = *head;
	old_head->prev->next = old_head->next;
	old_head->next->prev = old_head->prev;
	old_head->next->next->prev = old_head;
	old_head->prev = old_head->next;
	new_head = old_head->next;
	old_head->next = old_head->next->next;
	new_head->next = old_head;
	*head = new_head;
}

void	ft_rotate(struct s_node **head)
{
	*head = (*head)->next;
}

void	ft_rev_rotate(struct s_node **head)
{
	*head = (*head)->prev;
}

void	ft_s_node_pop(struct s_node **from, int *number, int *index)
{
	struct s_node	*temp;

	temp = *from;
	*number = temp->numb;
	*index = temp->indx;
	if (*from == (*from)->next)
	{
		free(*from);
		*from = NULL;
	}
	else
	{
		(*from)->prev->next = (*from)->next;
		(*from)->next->prev = (*from)->prev;
		*from = (*from)->next;
		free(temp);
	}
}

int	ft_s_node_push(struct s_node **to, int number, int index)
{
	struct s_node	*new_top;

	new_top = ft_s_node_create_new_element(number, index);
	if (new_top == NULL)
		return (0);
	if (*to == NULL)
	{
		new_top->next = new_top;
		new_top->prev = new_top;
		*to = new_top;
	}
	else
	{
		new_top->next = *to;
		new_top->prev = (*to)->prev;
		(*to)->prev->next = new_top;
		(*to)->prev = new_top;
		(*to) = new_top;
	}
	return (1);
}
