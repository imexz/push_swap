/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:00:22 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/23 14:01:09 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	ft_s_node_lst_size(struct s_node *lst)
{
	int				i;
	struct s_node	*current;

	i = 0;
	current = lst;
	while (current->next != lst)
	{
		current = current->next;
		i++;
	}
	return (i);
}
