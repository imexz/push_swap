/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:06:00 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/23 15:29:16 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_push(struct s_node **from, struct s_node **to)
{
	int	number;
	int	index;

	if (*from == NULL)
		return ;
	ft_s_node_pop(from, &number, &index);
	if (ft_s_node_push(to, number, index) == 0)
	{
		ft_s_node_loop_clear(from);
		ft_s_node_loop_clear(to);
		ft_terminate("Error");
	}
}
