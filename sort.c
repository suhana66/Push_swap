/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:08:54 by susajid           #+#    #+#             */
/*   Updated: 2023/12/20 18:06:33 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_position(t_stack *stack, int len, int to_insert);

void	sort(t_stack *stack_a, t_stack *stack_b, int len_a)
{
	int	pushed;

	pushed = 0;
	while (len_a - pushed > 3 && !is_sorted(stack_a))
	{
		push(&stack_a, &stack_b, 'b');
		pushed++;
	}
	sort_3(stack_a);
	while (stack_b)
	{
		find_position(stack_a, len_a, stack_b->value);
		push(&stack_b, &stack_a, 'a');
	}
	find_position(stack_a, len_a, find_min(stack_a));
}

static void	find_position(t_stack *stack, int len, int to_insert)
{
	int		pos;
	bool	if_reverse;

	pos = 0;
	while (stack && stack->value < to_insert && ++pos)
		stack = stack->next;
	if (!stack)
		return ;
	if_reverse = false;
	if (pos > len / 2)
	{
		pos -= len / 2;
		if_reverse = true;
	}
	while (pos--)
	{
		if (if_reverse)
			reverse_rotate(&stack, 'a');
		else
			rotate(&stack, 'a');
	}
}
