/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:38:05 by susajid           #+#    #+#             */
/*   Updated: 2023/12/27 07:44:17 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_sorting *sorting);

void	push_swap(t_sorting *sorting)
{
	if (!sorting || sorting->total_len < 2
		|| is_sorted(sorting->stack_a))
		return ;
	if (sorting->total_len == 2)
		return (swap(sorting, 'a', true));
	if (!circle_sorted(sorting->stack_a, sorting->len_a))
	{
		while (sorting->len_a > 3)
		{
			if (sorting->len_b >= 2)
				do_cheap(sorting);
			push(sorting, 'b', true);
		}
		sort_3(sorting);
		while (sorting->stack_b)
		{
			do_move(sorting, find_move(sorting->stack_a, sorting->len_a,
					sorting->stack_b->value, false), 0, false);
			push(sorting, 'a', true);
		}
	}
	do_move(sorting, find_move(sorting->stack_a, sorting->len_a,
			INT_MIN, false), 0, false);
}

static void	sort_3(t_sorting *sorting)
{
	int		max_value;

	if (sorting->len_a != 3)
		return ;
	max_value = find_max(sorting->stack_a);
	if (sorting->stack_a->value == max_value)
		rotate(sorting, 'a', true);
	else if (sorting->stack_a->next->value == max_value)
		reverse_rotate(sorting, 'a', true);
	if (sorting->stack_a->value > sorting->stack_a->next->value)
		swap(sorting, 'a', true);
}
