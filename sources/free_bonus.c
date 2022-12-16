/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:01:55 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/23 15:29:32 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_n_terminate(char **temp, struct s_node **stack_a)
{
	if (temp != NULL)
		ft_free_arr(temp);
	if (stack_a != NULL)
		ft_s_node_list_clear(stack_a);
	ft_terminate("Error");
}

void	ft_terminate(char *s)
{
	if (errno == 0)
	{
		ft_putstr_fd(s, 2);
		ft_putchar_fd('\n', 2);
	}
	exit(EXIT_FAILURE);
}
