/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 23:22:25 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 19:15:40 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_s_action_list_print_best(struct s_action_list *idx,
				struct s_action_list *grt)
{
	struct s_action	*temp;

	if (idx->size < grt->size)
	{
		temp = idx->head;
		while (temp != NULL)
		{
			ft_putendl_fd(temp->name, 1);
			temp = temp->next;
		}
	}
	else
	{
		temp = grt->head;
		while (temp != NULL)
		{
			ft_putendl_fd(temp->name, 1);
			temp = temp->next;
		}
	}
}
