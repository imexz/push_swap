/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:08:56 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 11:02:03 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

struct s_action	*ft_s_action_create(char *name)
{
	struct s_action	*action;

	action = (struct s_action *)malloc(sizeof(struct s_action));
	if (action == NULL)
		ft_terminate("Error");
	action->name = ft_strdup(name);
	if (action->name == NULL)
		ft_terminate("Error");
	action->next = NULL;
	return (action);
}

void	ft_s_action_list_add_action(struct s_action_list *list, char *name)
{
	struct s_action	*action;
	struct s_action	*temp;

	action = ft_s_action_create(name);
	if (list == NULL)
		ft_terminate("Error");
	if (list->head == NULL)
		list->head = action;
	else
	{
		temp = list->head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = action;
	}
	list->size++;
}

struct s_action_list	*ft_s_action_list_create(void)
{
	struct s_action_list	*list;

	list = (struct s_action_list *)malloc(sizeof(struct s_action_list));
	if (list == NULL)
		ft_terminate("Error");
	list->size = 0;
	list->head = NULL;
	return (list);
}
