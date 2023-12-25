/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:13:56 by susajid           #+#    #+#             */
/*   Updated: 2023/12/25 13:25:41 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_move(int a_move, int b_move);
static void	find_cheap(t_sorting *sorting, int *a_move, int *b_move);

int	find_move(t_stack *stack, int len, int insert, bool if_desc)
{
	int	difference;
	int	min_difference;
	int	count;
	int	i;

	min_difference = INT_MAX;
	i = 0;
	while (i < len)
	{
		difference = stack->value - insert;
		if (difference == 0)
			return (i);
		if ((!if_desc && difference > 0) || (if_desc && difference < 0))
		{
			difference = absolute(difference);
			if (difference < min_difference)
			{
				count = i;
				min_difference = difference;
			}
		}
		i++;
		stack = stack->next;
	}
	return (count);
}

void	do_move(t_sorting *sorting, int a_move, int b_move)
{
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
	(void)sorting;
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
