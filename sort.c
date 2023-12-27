/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:13:56 by susajid           #+#    #+#             */
/*   Updated: 2023/12/27 07:43:04 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_move(int a_move, int b_move);
static void	find_cheap(t_sorting *sorting, int *a_move, int *b_move);

int	find_move(t_stack *stack, int len, int insert, bool if_desc)
{
	long	difference;
	long	min_difference;
	int		count;
	int		i;

	min_difference = LONG_MAX;
	i = -1;
	count = 0;
	while (++i < len)
	{
		difference = (long)stack->value - insert;
		if ((!if_desc && difference > 0) || (if_desc && difference < 0))
		{
			if (difference < 0)
				difference *= -1;
			if (difference < min_difference)
			{
				count = i;
				min_difference = difference;
			}
		}
		stack = stack->next;
	}
	return (count);
}

void	do_move(t_sorting *sorting, int a_move, int b_move, bool is_cheap)
{
	if (!is_cheap)
		find_cheap(sorting, &a_move, &b_move);
	while (a_move < 0 && b_move < 0 && a_move++ && b_move++)
	{
		reverse_rotate(sorting, 'a', false);
		reverse_rotate(sorting, 'b', false);
		ft_printf("rrs\n");
	}
	while (a_move > 0 && b_move > 0 && a_move-- && b_move--)
	{
		rotate(sorting, 'a', false);
		rotate(sorting, 'b', false);
		ft_printf("rs\n");
	}
	while (a_move < 0 && a_move++)
		reverse_rotate(sorting, 'a', true);
	while (a_move > 0 && a_move--)
		rotate(sorting, 'a', true);
	while (b_move < 0 && b_move++)
		reverse_rotate(sorting, 'b', true);
	while (b_move > 0 && b_move--)
		rotate(sorting, 'b', true);
}

void	do_cheap(t_sorting *sorting)
{
	int		a_move;
	int		b_move;
	int		a_min;
	int		b_min;
	t_stack	*counter;

	a_min = INT_MAX;
	b_min = INT_MAX;
	counter = sorting->stack_a;
	while (counter)
	{
		a_move = find_move(sorting->stack_a, sorting->len_a, counter->value, false);
		b_move = find_move(sorting->stack_b, sorting->len_b, counter->value, true);
		find_cheap(sorting, &a_move, &b_move);
		if (total_move(a_move, b_move) < total_move(a_min, b_min))
		{
			a_min = a_move;
			b_min = b_move;
		}
		counter = counter->next;
	}
	do_move(sorting, a_move, b_move, true);
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
		if (*a_move && i >= 2)
			poss_a[i] -= sorting->len_a;
		poss_b[i] = *b_move;
		if (*b_move && i % 2 != 0)
			poss_b[i] -= sorting->len_b;
	}
	min_move = INT_MAX;
	while (--i >= 0)
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
