/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:19:03 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 19:30:51 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	struct s_stack			*stack_idx;
	struct s_stack			*stack_grt;
	struct s_action_list	*actions_idx;
	struct s_action_list	*actions_grt;

	if (argc >= 2)
	{
		stack_idx = ft_s_stack_init();
		ft_parse_input(argc, argv, stack_idx);
		ft_s_stack_check_for_duplicates(stack_idx);
		ft_s_stack_get_index(stack_idx);
		ft_s_stack_get_sorted_head(stack_idx, &ft_get_sorted_size_idx);
		actions_idx = ft_s_stack_solve(stack_idx, &ft_get_sorted_size_idx);
		ft_s_stack_free(stack_idx);
		stack_grt = ft_s_stack_init();
		ft_parse_input(argc, argv, stack_grt);
		ft_s_stack_get_index(stack_grt);
		ft_s_stack_get_sorted_head(stack_grt, &ft_get_sorted_size_grt);
		actions_grt = ft_s_stack_solve(stack_grt, &ft_get_sorted_size_grt);
		ft_s_stack_free(stack_grt);
		ft_s_action_list_print_best(actions_idx, actions_grt);
		ft_s_action_list_free(actions_idx);
		ft_s_action_list_free(actions_grt);
	}
	return (0);
}
