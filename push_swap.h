/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:54:45 by susajid           #+#    #+#             */
/*   Updated: 2023/12/27 09:06:40 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_sorting
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		total_len;
	int		len_a;
	int		len_b;
}	t_sorting;

t_sorting	*set_sorting(int len, char **array);
void		push_swap(t_sorting *sorting);
void		clear_sorting(t_sorting *sorting);
void		clear_stack(t_stack *stack);

int			find_move(t_stack *stack, int len, int insert, bool if_desc);
void		do_move(t_sorting *sorting, int a_move, int b_move, bool is_cheap);
void		do_cheap(t_sorting *sorting);

bool		is_sorted(t_stack *stack);
bool		circle_sorted(t_stack *stack, int stack_len);
long		absolute(int num);
int			find_min(t_stack *stack);
int			find_max(t_stack *stack);

void		swap(t_sorting *sorting, char stack_name, bool if_print);
void		rotate(t_sorting *sorting, char stack_name, bool if_print);
void		reverse_rotate(t_sorting *sorting, char stack_name, bool if_print);
void		push(t_sorting *sorting, char stack_name, bool if_print);

#endif /* PUSH_SWAP_H */