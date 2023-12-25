/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:58:41 by susajid           #+#    #+#             */
/*   Updated: 2023/12/25 17:30:09 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	circle_sorted(t_stack *stack, int stack_len)
{
	int		first_val;
	int		min_pos;

	if (!stack)
		return (true);
	min_pos = find_move(stack, stack_len, INT_MIN, false);
	first_val = stack->value;
	while (--min_pos && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	stack = stack->next;
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	if (stack->value > first_val)
		return (false);
	return (true);
}

int	absolute(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
