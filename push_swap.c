/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:38:05 by susajid           #+#    #+#             */
/*   Updated: 2023/12/20 17:35:38 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b, int len_a)
{
	if (is_sorted(stack_a))
		return ;
	if (len_a == 2)
		swap(&stack_a, 'a');
	else if (len_a == 3)
		sort_3(stack_a);
	else
		sort(stack_a, stack_b, len_a);
	print_instruction(0, 0);
}

void	sort_3(t_stack *stack)
{
	int	max_value;

	if (is_sorted(stack))
		return ;
	max_value = find_max(stack);
	if (stack->value == max_value)
		rotate(&stack, 'a');
	else if (stack->next->value == max_value)
		reverse_rotate(&stack, 'a');
	if (stack->value > stack->next->value)
		swap(&stack, 'a');
}
