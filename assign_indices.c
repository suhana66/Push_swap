/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:27:43 by susajid           #+#    #+#             */
/*   Updated: 2023/12/15 12:57:21 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_index(t_list *stack);

void	assign_indices(int len, t_list *stack)
{
	if (!stack)
		return ;
	while (len)
	{
		assign_index(stack);
		len--;
	}
}

static void	assign_index(t_list *stack)
{
	static int	index = 1;
	int			min_val;
	t_list		*min_node;

	min_val = INT_MAX;
	while (stack)
	{
		if (stack->index == 0 && stack->value <= min_val)
		{
			min_val = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	min_node->index = index;
	index++;
}
