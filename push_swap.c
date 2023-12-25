/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:38:05 by susajid           #+#    #+#             */
/*   Updated: 2023/12/25 18:00:36 by susajid          ###   ########.fr       */
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
					sorting->stack_b->value, false), 0);
			push(sorting, 'a', true);
		}
	}
	do_move(sorting, find_move(sorting->stack_a, sorting->len_a,
			INT_MIN, false), 0);
}

static void	sort_3(t_sorting *sorting)
{
	t_stack	*temp;
	int		max_value;

	temp = sorting->stack_a;
	max_value = INT_MIN;
	while (temp)
	{
		if (temp->value > max_value)
			max_value = temp->value;
		temp = temp->next;
	}
	if (sorting->stack_a->value == max_value)
		rotate(sorting, 'a', true);
	else if (sorting->stack_a->next->value == max_value)
		reverse_rotate(sorting, 'a', true);
	if (sorting->stack_a->value > sorting->stack_a->next->value)
		swap(sorting, 'a', true);
}
