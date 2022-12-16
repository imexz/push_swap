/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:43:42 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/23 13:50:30 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

struct s_node	*ft_s_node_create_n_add_elem(char **numbers,
				long num, struct s_node **stack)
{
	struct s_node	*new_elem;

	new_elem = ft_s_node_create_new_element(num, -1);
	if (new_elem == NULL)
		ft_free_n_terminate(numbers, stack);
	ft_s_node_add_to_back(stack, new_elem);
	return (new_elem);
}

struct s_node	*ft_s_node_stack_init_str(char **argv)
{
	struct s_node	*stack;
	struct s_node	*new_elem;
	char			**numbers;
	long			num;
	int				i;

	stack = NULL;
	numbers = ft_split(argv[1], ' ');
	if (numbers == NULL)
		ft_terminate("Error");
	i = 0;
	while (numbers[i])
	{
		if (ft_isint(numbers[i], &num))
			new_elem = ft_s_node_create_n_add_elem(numbers, num, &stack);
		else
			ft_free_n_terminate(numbers, &stack);
		i++;
	}
	new_elem->next = stack;
	stack->prev = new_elem;
	ft_free_arr(numbers);
	return (stack);
}

struct s_node	*ft_s_node_stack_init_array(int argc, char **argv)
{
	struct s_node	*stack;
	struct s_node	*new_elem;
	long			num;
	int				i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_isint(argv[i], &num))
			new_elem = ft_s_node_create_n_add_elem(NULL, num, &stack);
		else
			ft_free_n_terminate(NULL, &stack);
		i++;
	}
	new_elem->next = stack;
	stack->prev = new_elem;
	return (stack);
}

struct s_node	*ft_s_node_stack_init(int argc, char **argv)
{
	struct s_node	*stack;

	if (argc == 2)
		stack = ft_s_node_stack_init_str(argv);
	else
		stack = ft_s_node_stack_init_array(argc, argv);
	return (stack);
}
