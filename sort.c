/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:08:54 by susajid           #+#    #+#             */
/*   Updated: 2023/12/21 11:30:17 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_value(t_stack *stack, int len, int to_insert);
static void	move_cheapest(t_sorting *sorting);

void	sort(t_sorting *sorting)
{
	int	pushed;

	pushed = 0;
	while (sorting->len_a - pushed > 3 && !is_sorted(sorting->stack_a))
	{
		if (pushed >= 2)
			move_cheapest(sorting);
		push(sorting, 'b', true);
		pushed++;
	}
	sort_3(sorting);
	while (sorting->stack_b)
	{
		move_value(sorting->stack_a, sorting->len_a, sorting->stack_b->value);
		push(sorting, 'a', true);
	}
	move_value(sorting->stack_a, sorting->len_a, find_min(sorting->stack_a));
}

static void	move_value(t_stack *stack, int len, int to_insert)
{
	(void)stack;
	(void)len;
	(void)to_insert;
}

static void	move_cheapest(t_sorting *sorting)
{
	(void)sorting;
}
