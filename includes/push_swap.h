/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:49:34 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/26 14:47:31 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# define ROTATE -1
# define RE_ROT 1

struct s_stack
{
	struct s_stack_elem	*head;
	struct s_stack_elem	*sorted_head;
	int					size;
	int					sorted;
};

struct s_stack_elem
{
	struct s_stack_elem	*next;
	struct s_stack_elem	*prev;
	int					num;
	int					idx;
	int					hold;
};

struct s_action_list
{
	int					size;
	struct s_action		*head;
};

struct s_action
{
	char				*name;
	struct s_action		*next;
};

struct s_rot_info_list
{
	struct s_rot_info	*head;
};

struct s_rot_info
{
	struct s_stack_elem	*head_a;
	struct s_stack_elem	*head_b;
	int					dir_a;
	int					dir_b;
	int					moves_a;
	int					moves_b;
	struct s_rot_info	*next;
};

struct s_stack			*ft_s_stack_init(void);
struct s_stack_elem		*ft_s_stack_elem_create(long numb);
void					ft_s_stack_elem_add_back(struct s_stack *stack,
							struct s_stack_elem *elem);
void					ft_terminate(char *msg);
void					ft_parse_input(int argc, char **argv,
							struct s_stack *stack);
void					ft_parse_string(char **argv, struct s_stack *stack);
void					ft_parse_array(int argc, char **argv,
							struct s_stack *stack);
void					ft_free_array(char **arr);
void					ft_s_stack_check_for_duplicates(struct s_stack *stack);
void					ft_s_stack_get_index(struct s_stack *stack);
void					ft_s_stack_get_sorted_head(struct s_stack *stack,
							int (*ft_get_sorted_size)(struct s_stack_elem *,
								struct s_stack *));
int						ft_get_sorted_size_idx(struct s_stack_elem *elem,
							struct s_stack *stack);
int						ft_get_sorted_size_grt(struct s_stack_elem *elem,
							struct s_stack *stack);
struct s_action_list	*ft_s_stack_solve(struct s_stack *stack_a,
							int (*ft_get_sorted_size)
							(struct s_stack_elem *, struct s_stack *));
struct s_stack			*ft_move_elements_to_b(struct s_stack *stack_a,
							int (*ft_get_sorted_size)(struct s_stack_elem *,
								struct s_stack *), struct s_action_list *list);
int						ft_s_stack_push_helpful(struct s_stack *stack_a);
int						ft_s_stack_swap_helpful(struct s_stack *stack_a,
							int (*ft_get_sorted_size)(struct s_stack_elem *,
								struct s_stack *));
void					ft_s_stack_swap(struct s_stack *stack);
struct s_action_list	*ft_s_action_list_create(void);
void					ft_s_action_list_add_action(struct s_action_list *list,
							char *name);
struct s_action			*ft_s_action_create(char *name);
void					ft_s_stack_push(struct s_stack *from,
							struct s_stack *to);
struct s_stack_elem		*ft_s_stack_pop(struct s_stack *stack);
void					ft_s_stack_add_elem_front(struct s_stack *stack,
							struct s_stack_elem *elem);
void					ft_s_stack_rotate_x(struct s_stack *stack, int dir);
void					ft_move_elements_back_to_a(struct s_stack *stack_a,
							struct s_stack *stack_b,
							struct s_action_list *list);
struct s_rot_info_list	*ft_s_rot_info_list_create(void);
struct s_rot_info		*ft_s_rot_info_create(void);
struct s_rot_info		*ft_s_stack_choose_opt_elements(struct s_stack *a,
							struct s_stack *b,
							struct s_rot_info_list *rot_info_list);
struct s_stack_elem		*ft_s_stack_find_fit_elem(struct s_stack *stack_a,
							int idx_b);
void					ft_s_rot_info_update(struct s_stack_elem *elem_b,
							struct s_stack *stack_a, struct s_stack *stack_b,
							struct s_rot_info_list *list);
int						*ft_s_stack_get_min_max_idx(struct s_stack *stack);
int						ft_s_stack_get_rot_dir_n_moves(struct s_stack *stack,
							struct s_stack_elem *elem, int *moves);
void					ft_s_rot_info_list_add_rot_info(
							struct s_rot_info_list *list,
							struct s_rot_info *rot_info);
struct s_rot_info		*ft_s_rot_info_opt_elem(struct s_rot_info_list *list);
void					ft_s_stack_move_to_opt_elements(struct s_stack *stack_a,
							struct s_stack *stack_b, struct s_rot_info *info,
							struct s_action_list *list);
void					ft_s_stack_rotate_both(struct s_stack *stack_a,
							struct s_stack *stack_b, int dir,
							struct s_action_list *list);
void					ft_s_stack_move_to_opt_elem_eq_dir(
							struct s_stack *stack_a, struct s_stack *stack_b,
							struct s_rot_info *info,
							struct s_action_list *list);
void					ft_s_stack_move_a_to_opt_elem(struct s_stack *stack,
							struct s_rot_info *info,
							struct s_action_list *list);
void					ft_s_stack_move_b_to_opt_elem(struct s_stack *stack,
							struct s_rot_info *info,
							struct s_action_list *list);
void					ft_s_rot_info_list_free(struct s_rot_info_list *list);
void					ft_s_stack_final_sort_a(struct s_stack *stack,
							struct s_action_list *list);
int						ft_s_stack_align_stack_a_get_dir(struct s_stack *stack);
void					ft_s_stack_free(struct s_stack *stack);
void					ft_s_action_list_free(struct s_action_list *list);
void					ft_s_action_list_print_best(struct s_action_list *idx,
							struct s_action_list *grt);
void					ft_s_stack_rotate_helper(struct s_stack *stack, int dir,
							struct s_action_list *list, char c);

#endif