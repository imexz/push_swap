/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:41:22 by mstrantz          #+#    #+#             */
/*   Updated: 2021/09/26 14:47:47 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <errno.h>
# define ROTATE -1
# define RE_ROT  1
# define INSERT  0

struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				numb;
	int				indx;
	int				max_indx;
	int				min_indx;
};

void			ft_swap(struct s_node **head);
void			ft_rotate(struct s_node **head);
void			ft_rev_rotate(struct s_node **head);
void			ft_s_node_pop(struct s_node **from, int *number, int *index);
int				ft_s_node_push(struct s_node **to, int number, int index);
void			ft_push(struct s_node **from, struct s_node **to);
void			ft_free_arr(char **arr);
void			ft_free_n_terminate(char **temp, struct s_node **stack_a);
void			ft_terminate(char *s);
struct s_node	*ft_s_node_create_n_add_elem(char **numbers,
					long num, struct s_node **stack);
struct s_node	*ft_s_node_stack_init_str(char **argv);
struct s_node	*ft_s_node_stack_init_array(int argc, char **argv);
struct s_node	*ft_s_node_stack_init(int argc, char **argv);
struct s_node	*ft_s_node_create_new_element(int number, int index);
struct s_node	*ft_s_node_last(struct s_node *node);
void			ft_s_node_add_to_back(struct s_node **head_a,
					struct s_node *new_elem);
void			ft_s_node_list_clear(struct s_node **head);
void			ft_s_node_loop_clear(struct s_node	**head);
int				ft_s_node_lst_size(struct s_node *lst);
void			ft_s_node_check_for_duplicates(struct s_node *head);
int				ft_is_sorted(struct s_node *stack_a, struct s_node *stack_b);
void			ft_rotate_both(struct s_node **head_a, struct s_node **head_b);
void			ft_rev_rotate_both(struct s_node **head_a,
					struct s_node **head_b);
void			ft_execute(struct s_node **head_a, struct s_node **head_b,
					char *line);

#endif
