/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:46:51 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/26 14:51:32 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	char			*line;
	struct s_node	*stack_a;
	struct s_node	*head_a;
	struct s_node	*head_b;

	if (argc == 1)
		return (0);
	stack_a = ft_s_node_stack_init(argc, argv);
	head_a = stack_a;
	ft_s_node_check_for_duplicates(stack_a);
	head_b = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		ft_execute(&head_a, &head_b, line);
	}
	if (ft_is_sorted(head_a, head_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
