/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:58:54 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/23 14:00:09 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

struct s_node	*ft_s_node_create_new_element(int number, int index)
{
	struct s_node	*new_elem;

	new_elem = (struct s_node *) malloc(sizeof(struct s_node));
	if (new_elem == NULL)
		return (NULL);
	new_elem->numb = number;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	new_elem->indx = index;
	new_elem->max_indx = -1;
	new_elem->min_indx = -1;
	return (new_elem);
}

struct s_node	*ft_s_node_last(struct s_node *node)
{
	struct s_node	*current;

	current = node;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	ft_s_node_add_to_back(struct s_node **head_a, struct s_node *new_elem)
{
	struct s_node	*prev_last;

	if (*head_a == NULL)
	{
		*head_a = new_elem;
		return ;
	}
	prev_last = ft_s_node_last(*head_a);
	prev_last->next = new_elem;
	new_elem->prev = prev_last;
}

void	ft_s_node_list_clear(struct s_node **head)
{
	struct s_node	*element;

	if (head)
	{
		while (*head)
		{
			element = (*head)->next;
			free(*head);
			*head = element;
		}
		head = NULL;
	}
}

void	ft_s_node_loop_clear(struct s_node	**head)
{
	struct s_node	*element;
	struct s_node	*top;

	element = *head;
	top = *head;
	while (element->next != top)
	{
		element = (*head)->next;
		free(*head);
		*head = element;
	}
	head = NULL;
}
