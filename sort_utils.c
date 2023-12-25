/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:58:41 by susajid           #+#    #+#             */
/*   Updated: 2023/12/25 14:04:31 by susajid          ###   ########.fr       */
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
	min_pos = find_move(stack, stack_len, find_min(stack), false);
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

int	find_max(t_stack *stack)
{
	int	max_value;

	max_value = INT_MIN;
	while (stack)
	{
		if (stack->value > max_value)
			max_value = stack->value;
		stack = stack->next;
	}
	return (max_value);
}

int	find_min(t_stack *stack)
{
	int	min_value;

	min_value = INT_MAX;
	while (stack)
	{
		if (stack->value < min_value)
			min_value = stack->value;
		stack = stack->next;
	}
	return (min_value);
}

int	absolute(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
