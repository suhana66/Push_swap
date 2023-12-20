/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:54:45 by susajid           #+#    #+#             */
/*   Updated: 2023/12/20 18:17:22 by susajid          ###   ########.fr       */
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

t_stack	*create_stack(int len, char **array);
void	push_swap(t_stack *stack_a, t_stack *stack_b, int len_a);
void	clear_stack(t_stack **stack);

bool	is_sorted(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);

void	swap(t_stack **stack, char stack_name);
void	rotate(t_stack **stack, char stack_name);
void	reverse_rotate(t_stack **stack, char stack_name);
void	push(t_stack **src_stack, t_stack **dst_stack, char dst_stack_name);
void	print_instruction(char *instruction, char name);

void	sort_3(t_stack *stack);
void	sort(t_stack *stack_a, t_stack *stack_b, int len_a);

#endif /* PUSH_SWAP_H */