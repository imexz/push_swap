/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:55:33 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 11:06:40 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_s_stack_check_for_duplicates(struct s_stack *stack)
{
	struct s_stack_elem	*iterator1;
	struct s_stack_elem	*iterator2;

	iterator1 = stack->head;
	while (iterator1->next != stack->head)
	{
		iterator2 = iterator1->next;
		while (iterator2 != iterator1)
		{
			if (iterator2->num == iterator1->num)
			{
				ft_terminate("Error");
			}
			iterator2 = iterator2->next;
		}
		iterator1 = iterator1->next;
	}
}
