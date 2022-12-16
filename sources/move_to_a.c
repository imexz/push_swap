/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:53:41 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/25 19:15:08 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

struct s_rot_info_list	*ft_s_rot_info_list_create(void)
{
	struct s_rot_info_list	*list;

	list = (struct s_rot_info_list *)malloc(sizeof(struct s_rot_info_list));
	if (list == NULL)
		ft_terminate("Error");
	list->head = NULL;
	return (list);
}

struct s_rot_info	*ft_s_rot_info_create(void)
{
	struct s_rot_info	*rot_info;

	rot_info = (struct s_rot_info *)malloc(sizeof(struct s_rot_info));
	if (rot_info == NULL)
		ft_terminate("Error");
	rot_info->head_a = NULL;
	rot_info->head_b = NULL;
	rot_info->dir_a = 0;
	rot_info->dir_b = 0;
	rot_info->moves_a = 0;
	rot_info->moves_b = 0;
	rot_info->next = NULL;
	return (rot_info);
}

void	ft_s_rot_info_update(struct s_stack_elem *elem_b,
			struct s_stack *stack_a, struct s_stack *stack_b,
			struct s_rot_info_list *list)
{
	struct s_rot_info	*rot_info;

	rot_info = ft_s_rot_info_create();
	rot_info->head_a = ft_s_stack_find_fit_elem(stack_a,
			elem_b->idx);
	rot_info->dir_a = ft_s_stack_get_rot_dir_n_moves(stack_a,
			rot_info->head_a, &(rot_info->moves_a));
	rot_info->head_b = elem_b;
	rot_info->dir_b = ft_s_stack_get_rot_dir_n_moves(stack_b,
			elem_b, &(rot_info->moves_b));
	ft_s_rot_info_list_add_rot_info(list, rot_info);
}

struct s_rot_info	*ft_s_stack_choose_opt_elements(struct s_stack *stack_a,
						struct s_stack *stack_b,
						struct s_rot_info_list *rot_info_list)
{
	int					i;
	struct s_stack_elem	*temp_b;

	temp_b = stack_b->head;
	i = 0;
	while (i < stack_b->size)
	{
		ft_s_rot_info_update(temp_b, stack_a, stack_b, rot_info_list);
		temp_b = temp_b->next;
		i++;
	}
	return (ft_s_rot_info_opt_elem(rot_info_list));
}

void	ft_move_elements_back_to_a(struct s_stack *stack_a,
				struct s_stack *stack_b, struct s_action_list *list)
{
	struct s_rot_info_list	*rot_info_list;
	struct s_rot_info		*rot_info;

	while (stack_b->head != NULL)
	{
		rot_info_list = ft_s_rot_info_list_create();
		rot_info = ft_s_stack_choose_opt_elements(stack_a, stack_b,
				rot_info_list);
		ft_s_stack_move_to_opt_elements(stack_a, stack_b, rot_info, list);
		ft_s_stack_push(stack_b, stack_a);
		ft_s_action_list_add_action(list, "pa");
		ft_s_rot_info_list_free(rot_info_list);
	}
	free(stack_b);
}
