/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:54:45 by susajid           #+#    #+#             */
/*   Updated: 2023/12/21 11:24:30 by susajid          ###   ########.fr       */
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
	int		len_a;
}	t_sorting;

t_sorting	*set_sorting(int len, char **array);
void		push_swap(t_sorting *sorting);
void		clear_sorting(t_sorting *sorting);

bool		is_sorted(t_stack *stack);
int			find_max(t_stack *stack);
int			find_min(t_stack *stack);

void		swap(t_sorting *sorting, char stack_name, bool if_print);
void		rotate(t_sorting *sorting, char stack_name, bool if_print);
void		reverse_rotate(t_sorting *sorting, char stack_name, bool if_print);
void		push(t_sorting *sorting, char stack_name, bool if_print);

void		sort_3(t_sorting *sorting);
void		sort(t_sorting *sorting);

#endif /* PUSH_SWAP_H */