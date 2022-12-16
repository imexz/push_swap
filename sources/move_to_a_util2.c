/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 21:07:58 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 18:58:10 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_s_stack_rotate_both(struct s_stack *stack_a, struct s_stack *stack_b,
		 int dir, struct s_action_list *list)
{
	if (dir == ROTATE)
	{
		ft_s_stack_rotate_x(stack_a, dir);
		ft_s_stack_rotate_x(stack_b, dir);
		ft_s_action_list_add_action(list, "rr");
	}
	else if (dir == RE_ROT)
	{
		ft_s_stack_rotate_x(stack_a, dir);
		ft_s_stack_rotate_x(stack_b, dir);
		ft_s_action_list_add_action(list, "rrr");
	}
}

void	ft_s_stack_move_to_opt_elem_eq_dir(struct s_stack *stack_a,
			struct s_stack *stack_b, struct s_rot_info *info,
			struct s_action_list *list)
{
	int	i;

	if (info->moves_a <= info->moves_b)
	{
		i = 0;
		while (info->moves_a > 0 && i++ < info->moves_a)
			ft_s_stack_rotate_both(stack_a, stack_b, info->dir_a, list);
		if (info->moves_a > 0)
			i--;
		while (i++ < info->moves_b)
			ft_s_stack_rotate_helper(stack_b, info->dir_b, list, 'b');
	}
	else if (info->moves_a > info->moves_b)
	{
		i = 0;
		while (info->moves_b > 0 && i++ < info->moves_b)
			ft_s_stack_rotate_both(stack_a, stack_b, info->dir_a, list);
		if (info->moves_b > 0)
			i--;
		while (i++ < info->moves_a)
			ft_s_stack_rotate_helper(stack_a, info->dir_a, list, 'a');
	}
}

void	ft_s_stack_move_a_to_opt_elem(struct s_stack *stack,
			struct s_rot_info *info, struct s_action_list *list)
{
	int	i;

	i = 0;
	if (info->dir_a == ROTATE)
	{
		while (i++ < info->moves_a)
		{
			ft_s_stack_rotate_x(stack, info->dir_a);
			ft_s_action_list_add_action(list, "ra");
		}
	}
	else
	{
		while (i++ < info->moves_a)
		{
			ft_s_stack_rotate_x(stack, info->dir_a);
			ft_s_action_list_add_action(list, "rra");
		}
	}
}

void	ft_s_stack_move_b_to_opt_elem(struct s_stack *stack,
			struct s_rot_info *info, struct s_action_list *list)
{
	int	i;

	i = 0;
	if (info->dir_b == ROTATE)
	{
		while (i++ < info->moves_b)
		{
			ft_s_stack_rotate_x(stack, info->dir_b);
			ft_s_action_list_add_action(list, "rb");
		}
	}
	else
	{
		while (i++ < info->moves_b)
		{
			ft_s_stack_rotate_x(stack, info->dir_b);
			ft_s_action_list_add_action(list, "rrb");
		}
	}
}

void	ft_s_stack_move_to_opt_elements(struct s_stack *stack_a,
			struct s_stack *stack_b, struct s_rot_info *info,
			struct s_action_list *list)
{
	if (info->dir_a == info->dir_b)
		ft_s_stack_move_to_opt_elem_eq_dir(stack_a, stack_b, info, list);
	else
	{
		ft_s_stack_move_a_to_opt_elem(stack_a, info, list);
		ft_s_stack_move_b_to_opt_elem(stack_b, info, list);
	}
}
