/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:38:05 by susajid           #+#    #+#             */
/*   Updated: 2023/12/22 12:15:39 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_sorting *sorting)
{
	if (!sorting || sorting->total_len < 2 || is_sorted(sorting->stack_a))
		return ;
	if (sorting->total_len == 2)
		return (swap(sorting, 'a', true));
	sort(sorting);
}

bool	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
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
