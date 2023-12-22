/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:13:56 by susajid           #+#    #+#             */
/*   Updated: 2023/12/22 17:34:03 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}
