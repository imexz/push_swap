/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:25:56 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 19:18:19 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_s_stack_rotate_helper(struct s_stack *stack, int dir,
			struct s_action_list *list, char c)
{
	char	*name;

	if (dir == ROTATE && c == 'a')
		name = "ra";
	else if (dir == ROTATE && c == 'b')
		name = "rb";
	else if (dir == RE_ROT && c == 'a')
		name = "rra";
	else if (dir == RE_ROT && c == 'b')
		name = "rrb";
	else
	{
		name = NULL;
		ft_terminate("Error");
	}
	ft_s_stack_rotate_x(stack, dir);
	ft_s_action_list_add_action(list, name);
}
