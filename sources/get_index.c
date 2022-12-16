/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:02:58 by mstrantz          #+#    #+#             */
/*   Updated: 2021/11/18 13:01:58 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Ideas for improvement:
	compare current value with all the other values and count how many values are smaller than the current one. This gives the index of the current value.
 */

static void	ft_sort_indices_array(int *indices, int size)
{
	int	temp;
	int	i;
	int	swapped;

	i = 0;
	while (i < size - 1)
	{
		if (indices[i] > indices[i + 1])
		{
			swapped = 1;
			temp = indices[i];
			indices[i] = indices[i + 1];
			indices[i + 1] = temp;
		}
		i++;
		if (swapped && i == size - 1)
		{
			swapped = 0;
			i = 0;
		}
	}
}

static int	*ft_get_indices_array(struct s_stack *stack)
{
	int					*indices;
	int					i;
	struct s_stack_elem	*temp;

	indices = (int *)malloc(sizeof(int) * stack->size);
	if (indices == NULL)
		ft_terminate("Error");
	temp = stack->head;
	i = 0;
	while (i < stack->size)
	{
		indices[i] = temp->num;
		temp = temp->next;
		i++;
	}
	ft_sort_indices_array(indices, stack->size);
	return (indices);
}

void	ft_s_stack_get_index(struct s_stack *stack)
{
	struct s_stack_elem	*temp;
	int					*indices;
	int					i;
	int					j;

	indices = ft_get_indices_array(stack);
	temp = stack->head;
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (indices[j] != temp->num)
			j++;
		temp->idx = j;
		temp = temp->next;
		i++;
	}
	free(indices);
}
