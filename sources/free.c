/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 21:59:22 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 19:13:25 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_s_rot_info_list_free(struct s_rot_info_list *list)
{
	struct s_rot_info	*temp;
	struct s_rot_info	*del;

	if (list)
	{
		temp = list->head;
		while (temp != NULL)
		{
			del = temp;
			temp = temp->next;
			free(del);
		}
		free(list);
	}
}

void	ft_s_stack_free(struct s_stack *stack)
{
	struct s_stack_elem	*temp;
	struct s_stack_elem	*del;
	int					i;

	if (stack)
	{
		if (stack->head != NULL)
		{
			temp = stack->head;
			i = 0;
			while (i < stack->size)
			{
				del = temp;
				temp = temp->next;
				free(del);
				i++;
			}
		}
		free(stack);
	}
}

void	ft_s_action_list_free(struct s_action_list *list)
{
	struct s_action	*temp;
	struct s_action	*del;

	if (list)
	{
		temp = list->head;
		while (temp != NULL)
		{
			del = temp;
			temp = temp->next;
			free(del->name);
			free(del);
		}
		free(list);
	}
}
