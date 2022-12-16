/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:49:17 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 10:40:45 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_array(char **arr)
{
	int	i;

	if (arr != NULL)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	ft_parse_string(char **argv, struct s_stack *stack)
{
	char				**numbers;
	int					i;
	long				numb;
	struct s_stack_elem	*new_elem;

	numbers = ft_split(argv[1], ' ');
	if (numbers == NULL)
		ft_terminate("Error");
	i = 0;
	while (numbers[i])
	{
		if (ft_isint(numbers[i], &numb))
		{
			new_elem = ft_s_stack_elem_create(numb);
			ft_s_stack_elem_add_back(stack, new_elem);
		}
		else
		{
			ft_free_array(numbers);
			ft_terminate("Error");
		}
		i++;
	}
	ft_free_array(numbers);
}

void	ft_parse_array(int argc, char **argv, struct s_stack *stack)
{
	int					i;
	long				numb;
	struct s_stack_elem	*new_elem;

	i = 1;
	while (i < argc)
	{
		if (ft_isint(argv[i], &numb))
		{
			new_elem = ft_s_stack_elem_create(numb);
			if (new_elem == NULL)
				ft_terminate("Error");
			ft_s_stack_elem_add_back(stack, new_elem);
		}
		else
			ft_terminate("Error");
		i++;
	}
}

void	ft_parse_input(int argc, char **argv, struct s_stack *stack)
{
	if (argc == 2)
		ft_parse_string(argv, stack);
	else
		ft_parse_array(argc, argv, stack);
}
