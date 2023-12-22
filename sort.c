/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:58:41 by susajid           #+#    #+#             */
/*   Updated: 2023/12/22 17:38:48 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_sorting *sorting);
static void	find_cheap(t_sorting *sorting, int *a_move, int *b_move);
static void	do_cheap(t_sorting *sorting);
static int	total_move(int a_move, int b_move);

void	sort(t_sorting *sorting)
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
	do_move(sorting, find_move(sorting->stack_a, sorting->len_a,
			find_min(sorting->stack_a), false), 0);
}

static void	sort_3(t_sorting *sorting)
{
	int	max_value;

	max_value = find_max(sorting->stack_a);
	if (sorting->stack_a->value == max_value)
		rotate(sorting, 'a', true);
	else if (sorting->stack_a->next->value == max_value)
		reverse_rotate(sorting, 'a', true);
	if (sorting->stack_a->value > sorting->stack_a->next->value)
		swap(sorting, 'a', true);
}

static void	do_cheap(t_sorting *sorting)
{
	t_stack	*counter;
	int		to_insert;
	int		a_move;
	int		b_move;

	counter = sorting->stack_a;
	while (counter)
	{
		to_insert = counter->value;
		if (to_insert < find_min(sorting->stack_b)
			|| to_insert > find_min(sorting->stack_b))
			to_insert = find_max(sorting->stack_b);
		a_move = find_move(sorting->stack_a, sorting->len_a,
				counter->value, false);
		b_move = find_move(sorting->stack_b, sorting->len_b, to_insert, true);
		find_cheap(sorting, &a_move, &b_move);
		do_move(sorting, a_move, b_move);
		counter = counter->next;
	}
}

static void	find_cheap(t_sorting *sorting, int *a_move, int *b_move)
{
	int	poss_a[4];
	int	poss_b[4];
	int	i;
	int	min_move;

	i = -1;
	while (++i < 4)
	{
		poss_a[i] = *a_move;
		if (i >= 2)
			poss_a[i] -= sorting->len_a;
		poss_b[i] = *b_move;
		if (i % 2 != 0)
			poss_b[i] -= sorting->len_b;
	}
	min_move = INT_MAX;
	while (--i <= 0)
	{
		if (total_move(poss_a[i], poss_b[i]) < min_move)
		{
			min_move = total_move(poss_a[i], poss_b[i]);
			*a_move = poss_a[i];
			*b_move = poss_b[i];
		}
	}
}

static int	total_move(int a_move, int b_move)
{
	if ((a_move < 0 && b_move < 0) || (a_move > 0 && b_move > 0))
	{
		a_move = absolute(a_move);
		b_move = absolute(b_move);
		if (a_move > b_move)
			return (a_move);
		else
			return (b_move);
	}
	else
		return (absolute(a_move) + absolute(b_move));
}
